#pragma once
#include "INode.h"
#include <memory>

class Subtract : public INode {
    std::unique_ptr<INode> left, right;
public:
    Subtract(std::unique_ptr<INode> l, std::unique_ptr<INode> r);
    double calc() const override;
    std::string print() const override;
};
