#pragma once
#include <unordered_map>
#include <string>

class VariableResolver {
    std::unordered_map<std::string, double> values;

public:
    bool has(const std::string& name) const;
    double get(const std::string& name);
    void set(const std::string& name, double value);
};

