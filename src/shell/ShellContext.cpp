#include "ShellContext.h"

ShellContext::ShellContext(Connection::ConnectionPtr conn)
    : conn_(conn), connId_(std::string()) {}