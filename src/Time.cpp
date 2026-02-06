#include "Time.h"
#include <stdexcept>
#include <map>

double Time::convert(double value, const std::string& startUnit, const std::string& endUnit) {
    std::map<std::string, double> units = {
        {"ns", 1e-9}, 
        {"ms", 0.001}, 
        {"s", 1.0},   
        {"min", 60.0},   
        {"hour", 3600.0} 
    };

    if (units.find(startUnit) == units.end() || units.find(endUnit) == units.end()) {
        throw std::invalid_argument("Unit not supported in Time converter.");
    }

    double valueInSeconds = value * units[startUnit];
    return valueInSeconds / units[endUnit];
}


