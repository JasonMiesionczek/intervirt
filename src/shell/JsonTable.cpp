#include "JsonTable.h"

JsonTable::JsonTable(std::map<std::string, std::string> headers,
                     Json::Value data)
    : headers_(headers), data_(data) {}

void JsonTable::draw() {
  std::map<std::string, size_t> maxWidth;
  for (auto &field : this->headers_) {
    size_t fieldMaxWidth = 0;
    for (auto &d : this->data_) {
      auto fieldValue = d[field.first].asString();
      if (fieldValue.length() > fieldMaxWidth) {
        fieldMaxWidth = fieldValue.length();
      }
    }
    maxWidth[field.first] = fieldMaxWidth + 3;
  }

  std::stringstream headerTop;
  std::stringstream headers;
  std::vector<std::string> dataOut;
  headerTop << "+";
  headers << "|";

  for (auto &mw : maxWidth) {
    headerTop << std::setw(mw.second) << std::setfill('-') << "+";
    headers << std::left << std::setw(mw.second - 1) << std::setfill(' ')
            << " " + this->headers_[mw.first] << "|";
  }
  std::cout << headerTop.str() << std::endl;
  std::cout << headers.str() << std::endl;
  std::cout << headerTop.str() << std::endl;

  for (auto &d : this->data_) {
    std::stringstream row;
    row << "|";
    for (auto &mw : maxWidth) {
      row << std::left << std::setw(mw.second - 1) << std::setfill(' ')
          << " " + d[mw.first].asString() + " "
          << "|";
    }
    dataOut.push_back(row.str());
  }

  for (auto &row : dataOut) {
    std::cout << row << std::endl;
  }
  std::cout << headerTop.str() << std::endl << std::endl;
}
