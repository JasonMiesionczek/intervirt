#include "ICommand.h"

ICommand::ICommand(std::string name, std::string category, std::string desc)
    : name_(name), category_(category), desc_(desc) {}
