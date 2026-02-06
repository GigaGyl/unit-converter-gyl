#ifndef TIME_H
#define TIME_H

#include "Converter.h"
#include <string>

class Time : public Converter {
public:
    double convert(double value, const std::string& fromUnit, const std::string& toUnit) override;
};

#endif

