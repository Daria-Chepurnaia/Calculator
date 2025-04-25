#pragma once
#include <string>
#include <vector>
#include "Token.h"
#include "../utils/VariableInput.h"

class Tokenizer {
public:
    static std::vector<Token> tokenize(const std::string& input, VariableInput& varInput);
};