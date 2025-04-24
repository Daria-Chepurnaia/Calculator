#include "Substr.h"

Substr::Substr(std::unique_ptr<INode> l, std::unique_ptr<INode> r)
    : left(std::move(l)), right(std::move(r)) {}

double Substr::calc() const {
    return left->calc() - right->calc();
}

std::string Substr::print() const {
    return "(" + left->print() + " - " + right->print() + ")";
}
