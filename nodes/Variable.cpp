#include "Variable.h"
#include <stdexcept>

Variable::Variable(const std::string& n) : name(n) {}

void Variable::setValue(double v) {
    value = v;
    valueSet = true;
}

const std::string& Variable::getName() const {
    return name;
}

bool Variable::isSet() const {
    return valueSet;
}

double Variable::calc() const {
    if (!valueSet) throw std::runtime_error("Variable " + name + " not set");
    return value;
}

std::string Variable::print() const {
    return name;
}
