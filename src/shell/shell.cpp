#include <common/util.h>
#include <docopt/docopt.h>

#include <jsonrpccpp/client/connectors/httpclient.h>
#include <objects/HypervisorConnection.h>
#include <shell/CommandManager.h>
#include <shell/ShellContext.h>
#include <shell/ShellUtil.h>
#include <shell/commands/ListCommand.h>
#include <shell/rpcclient.h>

using namespace jsonrpc;

static const char USAGE[] =
        R"(ivsh - Intervirt Interactive Shell

    Usage:
      ivsh [--host=<host>] [--uri=<uri>] [--pw=<pw>]
      ivsh --version

    Options:
      -h --help     Show this screen

)";

int main(int argc, const char **argv) {
    std::map<std::string, docopt::value> args =
            docopt::docopt(USAGE, {argv + 1, argv + argc}, true, "ivsh v0.1.0");

    std::string uri;
    auto findUri = args.find("--uri");
    if (findUri != args.end() && findUri->second.isString()) {
        uri = findUri->second.asString();
    }

    std::string password;
    auto findPw = args.find("--pw");
    if (findPw != args.end() && findPw->second.isString()) {
        password = findPw->second.asString();
    }

    SHRDPTR(ShellContext) context = nullptr;

    if (uri.length() > 0) {
        auto conn = MKSHRD(Connection::HypervisorConnection, uri);
        if (password.length() == 0) {
            std::stringstream ss;
            ss << "Enter Password [" << conn->getUsername() << "]: ";
            password = ShellUtil::capturePassword(ss.str());
            conn->setPassword(password);
        } else {
            conn->setPassword(password);
        }

        context = MKSHRD(ShellContext, conn);
    } else {
        context = MKSHRD(ShellContext, nullptr);
    }

    auto cmdManager = MKSHRD(CommandManager, context);
    cmdManager->registerCommand("list", MKSHRD(ListCommand));

    HttpClient httpclient("http://localhost:8383");
    SHRDPTR(RpcClient) c = MKSHRD(RpcClient, httpclient);
    try {
        if (uri.length() > 0) {
            auto id = c->connect(password, uri);
            context->setConnId(id);
        }
        context->setClient(c);
    } catch (JsonRpcException e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }

    std::cout << std::endl
              << BOLD(FBLU("Intervirt Interactive Shell")) << std::endl
              << std::endl;
    bool quit = false;
    std::string input;

    while (!quit) {
        try {
            std::cout << context->getPrompt();
            std::getline(std::cin, input);
            if (input == "quit") {
                quit = true;
            } else {
                cmdManager->runCommand(input);
            }
        } catch (JsonRpcException e) {
            std::cerr << e.what() << std::endl;
        }
    }
}
