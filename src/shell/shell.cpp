#include <common/util.h>
#include <docopt/docopt.h>

#include <shell/ShellContext.h>
#include <shell/rpcclient.h>
#include <objects/HypervisorConnection.h>
#include <jsonrpccpp/client/connectors/httpclient.h>

using namespace jsonrpc;

static const char USAGE[] =
R"(ivsh - Intervirt Interactive Shell

    Usage:
      ivsh [--host=<host>] [--uri=<uri>]
      ivsh --version

    Options:
      -h --help     Show this screen

)";

std::string capturePassword(std::string prompt)
{
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    std::cout << std::endl << prompt;
    std::string s;
    std::getline(std::cin, s);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return s;
}

int main(int argc, const char** argv)
{
    std::map<std::string, docopt::value> args = docopt::docopt(USAGE, {argv + 1, argv + argc}, true, "ivsh v0.1.0");
    // for (auto const& arg : args) {
    //     std::cout << arg.first << arg.second << std::endl;
    // }

    std::string uri;
    auto findUri = args.find("--uri");
    if (findUri != args.end()) {
        uri = findUri->second.asString();
    }

    auto conn = MKSHRD(Connection::HypervisorConnection, uri);
    std::stringstream ss;
    ss << "Enter Password [" << conn->getUsername() << "]: ";
    auto pw = capturePassword(ss.str());
    conn->setPassword(pw);

    auto context = MKSHRD(ShellContext, conn);

    HttpClient httpclient("http://localhost:8383");
    RpcClient c(httpclient);
    try
    {
        auto id = c.connect(pw, uri);
        //std::cout << "connection id: " << id << std::endl;
        context->setConnId(id);
    }
    catch (JsonRpcException e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl
              << "Intervirt Interactive Shell" << std::endl
              << std::endl;
    bool quit = false;
    std::string input;
    
    while (!quit)
    {
        std::cout << "> ";
        std::getline(std::cin, input);
        if (input == "quit") {
            quit = true;
        }
    }
}