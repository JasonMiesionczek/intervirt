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
    auto splitCmd = split(cmd, ' ');
    
    if (splitCmd[0] == "help") {
        this->showHelp();
        return;
    }

    auto foundCmd = this->commands_.find(splitCmd[0]);
    if (foundCmd != this->commands_.end()) {
        foundCmd->second->run(this->context_, splitCmd);
    } else {
        std::cerr << "Command: " << cmd << " not recognized." << std::endl;
    }
}