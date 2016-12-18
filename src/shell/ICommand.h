#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <shell/ShellContext.h>

class ICommand {
public:
  ICommand(std::string name, std::string category, std::string desc);
  virtual void run(SHRDPTR(ShellContext) context,
                   std::vector<std::string> params) = 0;
  std::string getName() { return this->name_; }
  std::string getCategory() { return this->category_; }
  std::string getDesc() { return this->desc_; }

private:
  std::string name_;
  std::string category_;
  std::string desc_;
};

#endif /* ICOMMAND_H */
