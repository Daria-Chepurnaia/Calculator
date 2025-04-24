#pragma once
#include "INode.h"
#include <memory>

class Substr : public INode {
    std::unique_ptr<INode> left, right;
public:
    Substr(std::unique_ptr<INode> l, std::unique_ptr<INode> r);
    double calc() const override;
    std::string print() const override;
};
