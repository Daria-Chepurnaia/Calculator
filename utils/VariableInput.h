#pragma once
#include <unordered_map>
#include <string>

class VariableInput {
public:
    double getValue(const std::string& name);
    void set(const std::string& name, double value);
    
    void clear();

private:
    std::unordered_map<std::string, double> values;
};
