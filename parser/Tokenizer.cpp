#include "Tokenizer.h"
#include <cctype>
#include <stdexcept>

std::vector<Token> Tokenizer::tokenize(const std::string& input, VariableInput& varInput) {
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
            bool hasDigit = false;
            bool hasDot = false;
        
            while (i < input.length()) {
                if (std::isdigit(input[i])) {
                    hasDigit = true;
                    ++i;
                } else if (input[i] == '.') {
                    if (hasDot) {
                        throw std::runtime_error("Invalid number: multiple decimal points");
                    }
                    hasDot = true;
                    ++i;
                } else {
                    break;
                }
            }
        
            std::string numberStr = input.substr(start, i - start);
        
            if (!hasDigit) {
                throw std::runtime_error("Invalid number: '.' without digits");
            }
        
            tokens.push_back({TokenType::Number, numberStr});
            continue;
        }

        if (std::isalpha(ch)) {
            size_t start = i;
            while (i < input.length() && std::isalpha(input[i])) ++i;
            std::string varName = input.substr(start, i - start);
            double val = varInput.getValue(varName);
            tokens.push_back({TokenType::Number, std::to_string(val)});
            continue;
        }

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

    tokens.push_back({TokenType::End, ""});
    return tokens;
}