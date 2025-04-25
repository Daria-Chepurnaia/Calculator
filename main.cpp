#include <iostream>
#include <string>
#include <memory>

#include "parser/Tokenizer.h"
#include "parser/ExpressionParser.h"
#include "utils/VariableInput.h"
#include "nodes/INode.h"

int main() {
    std::string input;

    while (true) {
        std::cout << "Enter expression (or 'exit'): ";
        std::getline(std::cin, input);

        if (input == "exit")
            break;

        try {
            VariableInput varInput;

            auto tokens = Tokenizer::tokenize(input, varInput);
            auto tree = ExpressionParser::parseFromTokens(tokens);  

            std::cout << "Parsed: " << tree->print() << std::endl;
            std::cout << "Result: " << tree->calc() << std::endl;

        } catch (const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
