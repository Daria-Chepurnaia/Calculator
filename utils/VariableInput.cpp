#include "VariableInput.h"
#include <iostream>
#include <stdexcept>

double VariableInput::getValue(const std::string& name) {
    if (values.find(name) != values.end()) {
        return values[name];
    }

    std::cout << "Enter value for variable '" << name << "': ";
    std::string input;
    std::getline(std::cin, input);

    try {
        double val = std::stod(input);
        values[name] = val;
        return val;
    } catch (...) {
        throw std::runtime_error("Invalid value for variable '" + name + "'");
    }
} 

void VariableInput::set(const std::string& name, double value) {
    values[name] = value;
}

void VariableInput::clear() {
    values.clear();
}

