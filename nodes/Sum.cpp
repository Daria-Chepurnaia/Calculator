#include "Sum.h"

Sum::Sum(std::unique_ptr<INode> l, std::unique_ptr<INode> r)
    : left(std::move(l)), right(std::move(r)) {}

double Sum::calc() const {
    return left->calc() + right->calc();
}

std::string Sum::print() const {
    return "(" + left->print() + " + " + right->print() + ")";
}