#pragma once
#include "INode.h"
#include <string>

class Variable : public INode {
    std::string name;
    double value;
    bool valueSet = false;
public:
    explicit Variable(const std::string& n);
    void setValue(double v);
    const std::string& getName() const;
    bool isSet() const;
    double calc() const override;
    std::string print() const override;
};
