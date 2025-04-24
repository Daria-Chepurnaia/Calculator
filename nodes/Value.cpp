#include "Value.h"
#include <string>

Value::Value(double val) : value(val) {}

double Value::calc() const {
    return value;
}

std::string Value::print() const {
    return std::to_string(value);
}