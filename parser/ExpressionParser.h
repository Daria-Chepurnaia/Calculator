#pragma once
#include <memory>
#include <string>
#include "../nodes/INode.h"

class ExpressionParser {
public:
    static std::unique_ptr<INode> parse(const std::string& input);
};

