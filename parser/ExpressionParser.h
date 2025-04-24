#pragma once
#include <memory>
#include <vector>
#include <string>
#include "../nodes/INode.h"
#include "Token.h"

class ExpressionParser {
public:
    static std::unique_ptr<INode> parse(const std::string& input);
};


