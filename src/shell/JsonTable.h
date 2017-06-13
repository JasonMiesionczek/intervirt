#ifndef JSONTABLE_H
#define JSONTABLE_H

#include <common/util.h>
#include <json/json.h>
#include <shell/colors.h>

class JsonTable {
public:
    JsonTable(std::map<std::string, std::string> headers, Json::Value data);

    void draw();

private:
    std::map<std::string, std::string> headers_;
    Json::Value data_;
};

#endif /* JSONTABLE_H */
