#ifndef LISTCOMMAND_H
#define LISTCOMMAND_H

#include <common/util.h>
#include <shell/ICommand.h>
#include <shell/JsonTable.h>
#include <shell/ShellContext.h>

class ListCommand : public ICommand {
public:
    ListCommand();

    virtual void run(SHRDPTR(ShellContext) context,
                     std::vector<std::string> params);
};

#endif /* LISTCOMMAND_H */
