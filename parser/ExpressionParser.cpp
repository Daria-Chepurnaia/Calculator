#include "ExpressionParser.h"
#include "../nodes/Value.h"
#include "../nodes/Sum.h"
#include <sstream>
#include <stdexcept>

std::unique_ptr<INode> ExpressionParser::parse(const std::string& input) {
    std::istringstream ss(input);
    double a, b;
    char op;

    ss >> a >> op >> b;

    if (ss.fail() || op != '+') {
        throw std::runtime_error("Only addition like '4 + 5' is supported at this stage.");
    }

    return std::make_unique<Sum>(
        std::make_unique<Value>(a),
        std::make_unique<Value>(b)
    );
}