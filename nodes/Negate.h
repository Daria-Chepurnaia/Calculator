#pragma once
#include "INode.h"
#include <memory>

class Negate : public INode {
    std::unique_ptr<INode> expr;
public:
    explicit Negate(std::unique_ptr<INode> inner);
    double calc() const override;
    std::string print() const override;
};
