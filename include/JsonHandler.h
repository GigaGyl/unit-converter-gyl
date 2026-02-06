#ifndef JSONHANDLER_H
#define JSONHANDLER_H

#include "FileHandler.h"
#include <nlohmann/json.hpp>
#include <vector>
#include <string>

using json = nlohmann::json;

class JsonHandler : public FileHandler {
public:
    virtual ~JsonHandler() {}

    std::vector<std::vector<std::string>> read(const std::string& filename) override;
    void write(const std::string& filename, const std::vector<std::vector<std::string>>& data) override;
};

#endif


