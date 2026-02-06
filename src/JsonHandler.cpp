#include "JsonHandler.h"
#include <fstream>
#include <iostream>

std::vector<std::vector<std::string>> JsonHandler::read(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<std::string>> data;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open JSON file " << filename << std::endl;
        return data;
    }

    try {
        json j;
        file >> j;

        for (const auto& row : j) {
            std::vector<std::string> rowData;
            for (const auto& item : row) {
                rowData.push_back(item.is_string() ? item.get<std::string>() : item.dump());
            }
            data.push_back(rowData);
        }
    } catch (const json::parse_error& e) {
        std::cerr << "JSON Parse Error: " << e.what() << std::endl;
    }

    return data;
}

void JsonHandler::write(const std::string& filename, const std::vector<std::vector<std::string>>& data) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not write to JSON file " << filename << std::endl;
        return;
    }

    json j = data; 
    file << j.dump(4);
}


