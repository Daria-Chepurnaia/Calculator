#pragma once
#include <string>

class INode {
public:
    virtual ~INode() = default;
    virtual double calc() const = 0;
    virtual std::string print() const = 0;
};