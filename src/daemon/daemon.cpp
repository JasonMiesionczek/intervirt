#include <daemon/RpcServer.h>
#include <drivers/DriverFactory.h>
#include <drivers/hyperv/HypervDriverFactory.h>
#include <objects/HypervisorConnection.h>
#include <jsonrpccpp/server/connectors/httpserver.h>
#include <iostream>
#include <memory>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>

#define RUNNING_DIR "/tmp"
#define LOCK_FILE "intervirtd.lock"
#define LOG_FILE "intervirtd.log"

using namespace jsonrpc;
using namespace Drivers;

void signal_handler(int sig)
{
    switch(sig) {
        case SIGHUP:
            break;
        case SIGTERM:
            exit(EXIT_SUCCESS);
            break;
        }
}

void daemonize()
{
    pid_t pid, sid;

    if (getppid() == 1)
        return;

    pid = fork();
    if (pid < 0)
        exit(EXIT_FAILURE);

    if (pid > 0)
        exit(EXIT_SUCCESS);

    umask(0);

    sid = setsid();
    if (sid < 0)
        exit(EXIT_FAILURE);

    if ((chdir(RUNNING_DIR)) < 0) {
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    auto lfp = open(LOCK_FILE, O_RDWR | O_CREAT, 0640);
    if (lfp < 0)
        exit(EXIT_FAILURE);

    if (lockf(lfp, F_TLOCK, 0) < 0)
        exit(EXIT_SUCCESS);

    char str[10];
    sprintf(str, "%d\n", getpid());
    write(lfp, str, strlen(str));

    signal(SIGCHLD, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
    signal(SIGTTOU, SIG_IGN);
    signal(SIGTTIN, SIG_IGN);
    signal(SIGHUP, signal_handler);
    signal(SIGTERM, signal_handler);
}

int main()
{
    //daemonize();
    std::cout << "Registering drivers..." << std::endl;

    v1::Win32OperatingSystem* os = new v1::Win32OperatingSystem();
    auto uri = os->getResourceUri();
    std::cout << uri << std::endl;
    delete os;

    auto factory = std::make_shared<DriverFactory>();
    factory->registerDriver("hyperv", std::make_shared<HypervDriverFactory>());

    auto connection = std::make_shared<Connection::HypervisorConnection>("hyperv://administrator@10.0.22.97", "Datto1000!");
    std::cout << connection->getProtocol() << std::endl;
    std::cout << connection->getHost() << std::endl;
    std::cout << connection->getUsername() << std::endl;

    auto hypervisorFactory = factory->create(connection->getProtocol());
    auto driver = hypervisorFactory->connect(connection);

    // auto server = std::make_shared<HttpServer>(8383);
    // server->StartListening();
    // while (1)
    // {
    //     sleep(1);
    // }
}