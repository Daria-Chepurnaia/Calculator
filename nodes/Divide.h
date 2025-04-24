#pragma once
#include "INode.h"
#include <memory>

class Divide : public INode {
    std::unique_ptr<INode> left, right;
public:
    Divide(std::unique_ptr<INode> l, std::unique_ptr<INode> r);
    double calc() const override;
    std::string print() const override;
};
