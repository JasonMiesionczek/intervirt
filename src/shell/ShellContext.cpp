#include "ShellContext.h"

ShellContext::ShellContext(Connection::ConnectionPtr conn)
        : conn_(conn), connId_(std::string()) {}

std::string ShellContext::getPrompt() {
    Color::Modifier lgreen(Color::FG_LIGHT_GREEN);
    Color::Modifier lblue(Color::FG_LIGHT_BLUE);
    Color::Modifier dgray(Color::FG_DARK_GRAY);
    Color::Modifier white(Color::FG_WHITE);
    Color::Modifier def(Color::FG_DEFAULT);
    Color::Modifier bold(Color::BOLD);
    Color::Modifier reset(Color::RESET);
    std::stringstream ss;
    if (this->conn_ == nullptr) {
        ss << "[" << bold << lgreen << "NC" << reset << dgray << "|" << lblue
           << "No connection" << def << "] " << dgray << ">" << def << ">" << white
           << "> " << def;
    } else {
        ss << "[" << bold << lgreen << this->conn_->getProtocol() << reset << dgray
           << "|" << lblue << this->conn_->getHost() << def << "] " << dgray << ">"
           << def << ">" << white << "> " << def;
    }

    return ss.str();
}
