#include "CommandManager.h"

CommandManager::CommandManager(SHRDPTR(ShellContext) context)
    :context_(context) {}

std::vector<std::string> split(const std::string &s, char delim)
{
    std::stringstream ss(s);
    std::string item;
    std::vector<std::string> elems;
    while (std::getline(ss, item, delim)) {
        elems.push_back(std::move(item));
    }
    return elems;
}

void CommandManager::registerCommand(std::string name, SHRDPTR(ICommand) cmd)
{
    this->commands_[name] = cmd;
}

void CommandManager::showHelp()
{
    std::map<std::string, std::vector<std::string>> catMap;
    Color::Modifier lyellow(Color::FG_LIGHT_YELLOW);
    Color::Modifier lcyan(Color::FG_LIGHT_CYAN);
    Color::Modifier lred(Color::FG_LIGHT_RED);
    Color::Modifier def(Color::FG_DEFAULT);
    Color::Modifier bold(Color::BOLD);
    Color::Modifier reset(Color::RESET);

    for (auto const& cmd : this->commands_) {
        catMap[cmd.second->getCategory()].push_back(cmd.second->getName());
    }

    std::cout << std::endl;
    for (auto const &cat : catMap)
    {
        std::cout << "    " << lyellow << cat.first << def << std::endl
                  << std::endl;
        for (auto const &cmd : cat.second)
        {
            auto cmdo = this->commands_[cmd];
            std::cout << "      " << bold << lcyan << cmdo->getName() << "    " << reset << def << cmdo->getDesc() << std::endl;
        }
    }
    std::cout << std::endl;
}

void CommandManager::runCommand(std::string cmd)
{
    Color::Modifier lred(Color::FG_LIGHT_RED);
    Color::Modifier def(Color::FG_DEFAULT);
    Color::Modifier bold(Color::BOLD);
    Color::Modifier reset(Color::RESET);

    auto splitCmd = split(cmd, ' ');
    
    if (splitCmd[0] == "help") {
        this->showHelp();
        return;
    }

    if (splitCmd[0] == "connect") {
        if (splitCmd.size() > 1) {
            auto uri = splitCmd[1];
            auto conn = MKSHRD(Connection::HypervisorConnection, uri);
            std::stringstream ss;
            ss << "Enter Password [" << conn->getUsername() << "]: ";
            auto password = ShellUtil::capturePassword(ss.str());
            std::cout << std::endl;
            conn->setPassword(password);
            this->context_->setConnection(conn);
            auto id = this->context_->getClient()->connect(password, uri);
            this->context_->setConnId(id);
        } else {
            std::cout << bold << lred << "Missing URI parameter" << reset << def << std::endl;
        }
        return;
    }

    if (this->context_->getConnection() == nullptr) {
        std::cout << bold << lred << "Not connected" << reset << def << std::endl;
        return;
    }

    auto foundCmd = this->commands_.find(splitCmd[0]);
    if (foundCmd != this->commands_.end()) {
        foundCmd->second->run(this->context_, splitCmd);
    } else {
        std::cerr << "Command: " << cmd << " not recognized." << std::endl;
    }
}