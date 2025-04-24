#pragma once
#include <string>

enum class TokenType {
    Number,
    Variable,
    Plus,
    Minus,
    Multiply,
    Divide,
    LeftParen,
    RightParen,
    End
};

struct Token {
    TokenType type;
    std::string text;  // raw text (e.g. "x", "42", etc.)
};