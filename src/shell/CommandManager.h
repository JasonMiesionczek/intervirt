#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

#include <common/util.h>
#include <shell/ShellContext.h>
#include <shell/colors.h>
#include "ICommand.h"

class CommandManager
{
public:
  CommandManager(SHRDPTR(ShellContext) context);
  void registerCommand(std::string name, SHRDPTR(ICommand) cmd);
  void runCommand(std::string cmd);

private:
  void showHelp();

  std::map<std::string, SHRDPTR(ICommand)> commands_;
  SHRDPTR(ShellContext) context_;
};

#endif /* COMMANDMANAGER_H */
