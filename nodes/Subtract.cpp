#include "Subtract.h"

Subtract::Subtract(std::unique_ptr<INode> l, std::unique_ptr<INode> r)
    : left(std::move(l)), right(std::move(r)) {}

double Subtract::calc() const {
    return left->calc() - right->calc();
}

std::string Subtract::print() const {
    return "(" + left->print() + " - " + right->print() + ")";
}
