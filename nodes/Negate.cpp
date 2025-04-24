#include "Negate.h"

Negate::Negate(std::unique_ptr<INode> inner) : expr(std::move(inner)) {}

double Negate::calc() const {
    return -expr->calc();
}

std::string Negate::print() const {
    return "-(" + expr->print() + ")";
}

