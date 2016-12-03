#include <common/util.h>
#include <daemon/RpcServer.h>
#include <drivers/DriverManager.h>
#include <objects/HypervisorConnection.h>
#include <jsonrpccpp/server/connectors/httpserver.h>
#include <drivers/hyperv/wmi/WmiHelper.h>
#include <drivers/hyperv/HypervFactory.h>
#include <drivers/esx/EsxFactory.h>
#include <openwsman/wsman-api.h>
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

using namespace Drivers::Hyperv;
using namespace Drivers::Hyperv::Wmi;
using namespace Drivers::Hyperv::Wmi::Classes::Common;

using namespace Drivers::Esx;
namespace spd = spdlog;

int main()
{
    //daemonize();
    auto logger = spd::basic_logger_mt("logger", "/var/log/intervirt.log");
    logger->info("intervirtd starting up");

    auto console = spd::stdout_logger_mt("console", true);
    console->info("Intervirt System Daemon");
    console->info("Registering Drivers");

    auto manager = MKSHRD(DriverManager); //std::make_shared<DriverManager>();
    console->info("     hyper-v");
    manager->registerDriver("hyperv", MKSHRD(HypervFactory));
    console->info("     esx");
    manager->registerDriver("esx", MKSHRD(EsxFactory));

    auto connection = std::make_shared<Connection::HypervisorConnection>("hyperv://administrator@10.0.22.97", "Datto1000!");
    std::cout << connection->getProtocol() << std::endl;
    std::cout << connection->getHost() << std::endl;
    std::cout << connection->getUsername() << std::endl;
    std::cout << connection->getPassword() << std::endl;

    auto factory = manager->get(connection->getProtocol());
    auto driver = factory->create(connection);
    auto helper = MKSHRD(WmiHelper, connection);

    auto vms = driver->getVirtualMachines();
    for (auto&& vm : vms) {
        std::cout << vm->toString() << std::endl;
    }

    HttpServer httpServer(8383);
    RpcServer rpcServer(httpServer, manager);
    rpcServer.StartListening();
    getchar();
    rpcServer.StopListening();

    // server->StartListening();
    // while (1)
    // {
    //     sleep(1);
    // }
}