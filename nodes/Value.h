#pragma once
#include "INode.h"

class Value : public INode {
    double value;

public:
    explicit Value(double val);
    double calc() const override;
    std::string print() const override;
};