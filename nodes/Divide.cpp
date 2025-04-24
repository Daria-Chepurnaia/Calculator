#include "Divide.h"
#include <stdexcept>

Divide::Divide(std::unique_ptr<INode> l, std::unique_ptr<INode> r)
    : left(std::move(l)), right(std::move(r)) {}

double Divide::calc() const {
    double denominator = right->calc();
    if (denominator == 0) throw std::runtime_error("Division by zero");
    return left->calc() / denominator;
}

std::string Divide::print() const {
    return "(" + left->print() + " / " + right->print() + ")";
}
