#include "ExpressionParser.h"
#include "Tokenizer.h"
#include "../nodes/Value.h"
#include "../nodes/Sum.h"
#include "../nodes/Substr.h"
#include "../nodes/Multipl.h"
#include "../nodes/Divide.h"
#include "../nodes/Negate.h"
#include "../nodes/Variable.h"
#include <stdexcept>

class Parser {
    std::vector<Token> tokens;
    size_t pos = 0;

public:
    explicit Parser(const std::vector<Token>& toks) : tokens(toks) {}

    const Token& current() const { return tokens[pos]; }
    void advance() { if (pos < tokens.size()) ++pos; }

    std::unique_ptr<INode> parseExpression() {
        auto node = parseTerm();
        while (current().type == TokenType::Plus || current().type == TokenType::Minus) {
            Token op = current();
            advance();
            auto right = parseTerm();
            if (op.type == TokenType::Plus)
                node = std::make_unique<Sum>(std::move(node), std::move(right));
            else
                node = std::make_unique<Substr>(std::move(node), std::move(right));
        }
        return node;
    }

    std::unique_ptr<INode> parseTerm() {
        auto node = parseFactor();
        while (current().type == TokenType::Multiply || current().type == TokenType::Divide) {
            Token op = current();
            advance();
            auto right = parseFactor();
            if (op.type == TokenType::Multiply)
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
            auto node = parseExpression();
            if (current().type != TokenType::RightParen)
                throw std::runtime_error("Expected ')'");
            advance();
            return node;
        }

        if (current().type == TokenType::Number) {
            double val = std::stod(current().text);
            advance();
            return std::make_unique<Value>(val);
        }

        if (current().type == TokenType::Variable) {
            std::string name = current().text;
            advance();
            return std::make_unique<Variable>(name);  // позже подставим значения
        }

        throw std::runtime_error("Unexpected token: " + current().text);
    }
};

std::unique_ptr<INode> ExpressionParser::parse(const std::string& input) {
    auto tokens = Tokenizer::tokenize(input);
    Parser parser(tokens);
    auto result = parser.parseExpression();

    if (parser.current().type != TokenType::End) {
        throw std::runtime_error("Unexpected characters after end of expression");
    }

    return result;
}
