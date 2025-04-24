#include "Tokenizer.h"
#include <cctype>
#include <stdexcept>

std::vector<Token> Tokenizer::tokenize(const std::string& input) {
    std::vector<Token> tokens;
    size_t i = 0;

    while (i < input.length()) {
        char ch = input[i];

        if (std::isspace(ch)) {
            ++i;
            continue;
        }

        if (std::isdigit(ch) || ch == '.') {
            size_t start = i;
            while (i < input.length() && (std::isdigit(input[i]) || input[i] == '.')) ++i;
            tokens.push_back({TokenType::Number, input.substr(start, i - start)});
        } else if (std::isalpha(ch)) {
            size_t start = i;
            while (i < input.length() && std::isalpha(input[i])) ++i;
            tokens.push_back({TokenType::Variable, input.substr(start, i - start)});
        } else {
            switch (ch) {
                case '+': tokens.push_back({TokenType::Plus, "+"}); break;
                case '-': tokens.push_back({TokenType::Minus, "-"}); break;
                case '*': tokens.push_back({TokenType::Multiply, "*"}); break;
                case '/': tokens.push_back({TokenType::Divide, "/"}); break;
                case '(': tokens.push_back({TokenType::LeftParen, "("}); break;
                case ')': tokens.push_back({TokenType::RightParen, ")"}); break;
                default:
                    throw std::runtime_error(std::string("Unknown character: ") + ch);
            }
            ++i;
        }
    }

    tokens.push_back({TokenType::End, ""});
    return tokens;
}