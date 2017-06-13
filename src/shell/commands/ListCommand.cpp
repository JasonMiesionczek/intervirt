#include "ListCommand.h"

ListCommand::ListCommand()
        : ICommand("list", "General", "list all VMs on the host") {}

void ListCommand::run(SHRDPTR(ShellContext) context,
                      std::vector<std::string> params) {
    auto client = context->getClient();
    auto id = context->getConnId();
    auto vms = client->getAllVirtualMachines(id);

    JsonTable table({{"name",  "Name"},
                     {"id",    "ID"},
                     {"state", "State"}}, vms);
    table.draw();
}
