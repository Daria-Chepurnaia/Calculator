#include "VariableResolver.h"
#include <iostream>

bool VariableResolver::has(const std::string& name) const {
    return values.find(name) != values.end();
}

double VariableResolver::get(const std::string& name) {
    if (!has(name)) {
        std::cout << "Enter value for variable '" << name << "': ";
        double val;
        std::cin >> val;
        values[name] = val;
    }
    return values[name];
}

void VariableResolver::set(const std::string& name, double value) {
    values[name] = value;
}
