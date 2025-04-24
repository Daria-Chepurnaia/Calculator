#pragma once
#include "Token.h"
#include <vector>
#include <iostream>

inline void printTokens(const std::vector<Token>& tokens) {
    for (const auto& token : tokens) {
        std::cout << "Token(";

        switch (token.type) {
            case TokenType::Number: std::cout << "Number"; break;
            case TokenType::Variable: std::cout << "Variable"; break;
            case TokenType::Plus: std::cout << "Plus"; break;
            case TokenType::Minus: std::cout << "Minus"; break;
            case TokenType::Multiply: std::cout << "Multiply"; break;
            case TokenType::Divide: std::cout << "Divide"; break;
            case TokenType::LeftParen: std::cout << "LeftParen"; break;
            case TokenType::RightParen: std::cout << "RightParen"; break;
            case TokenType::End: std::cout << "End"; break;
        }

        std::cout << ", \"" << token.text << "\")" << std::endl;
    }
}
