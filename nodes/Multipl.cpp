#include "Multipl.h"

Multipl::Multipl(std::unique_ptr<INode> l, std::unique_ptr<INode> r)
    : left(std::move(l)), right(std::move(r)) {}

double Multipl::calc() const {
    return left->calc() * right->calc();
}

std::string Multipl::print() const {
    return "(" + left->print() + " * " + right->print() + ")";
}
