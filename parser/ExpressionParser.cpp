#include "ExpressionParser.h"
#include "Token.h"

#include "../nodes/Value.h"
#include "../nodes/Sum.h"
#include "../nodes/Substr.h"
#include "../nodes/Multipl.h"
#include "../nodes/Divide.h"
#include "../nodes/Negate.h"

#include <stdexcept>
#include <memory>

class Parser {
    const std::vector<Token>& tokens;
    size_t pos = 0;

public:
    explicit Parser(const std::vector<Token>& tks) : tokens(tks) {}

    const Token& current() const {
        if (pos >= tokens.size()) {
            throw std::runtime_error("Unexpected end of input");
        }
        return tokens[pos];
    }

    void advance() {
        if (pos < tokens.size()) ++pos;
    }

    std::unique_ptr<INode> parseExpression() {
        auto node = parseTerm();
        while (current().type == TokenType::Plus || current().type == TokenType::Minus) {
            TokenType op = current().type;
            advance();
            auto right = parseTerm();
            if (op == TokenType::Plus)
                node = std::make_unique<Sum>(std::move(node), std::move(right));
            else
                node = std::make_unique<Substr>(std::move(node), std::move(right));
        }
        return node;
    }

    std::unique_ptr<INode> parseTerm() {
        auto node = parseFactor();
        while (current().type == TokenType::Multiply || current().type == TokenType::Divide) {
            TokenType op = current().type;
            advance();
            auto right = parseFactor();
            if (op == TokenType::Multiply)
                node = std::make_unique<Multipl>(std::move(node), std::move(right));
            else
                node = std::make_unique<Divide>(std::move(node), std::move(right));
        }
        return node;
    }

    std::unique_ptr<INode> parseFactor() {
        if (current().type == TokenType::Minus) {
            advance();
            return std::make_unique<Negate>(parseFactor());
        }

        if (current().type == TokenType::LeftParen) {
            advance();
            auto expr = parseExpression();
            if (current().type != TokenType::RightParen)
                throw std::runtime_error("Expected ')'");
            advance();
            return expr;
        }

        if (current().type == TokenType::Number) {
            double val = std::stod(current().text);
            advance();
            return std::make_unique<Value>(val);
        }

        throw std::runtime_error("Unexpected token: " + current().text);
    }
};

std::unique_ptr<INode> ExpressionParser::parseFromTokens(const std::vector<Token>& tokens) {
    Parser parser(tokens);
    auto result = parser.parseExpression();

    if (parser.current().type != TokenType::End) {
        throw std::runtime_error("Unexpected tokens after valid expression");
    }

    return result;
}
