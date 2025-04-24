#include <iostream>
#include <string>
#include "parser/ExpressionParser.h"
#include "nodes/INode.h"

int main() {
    std::string input;
    std::cout << "Enter expression (or 'exit'): ";

    while (std::getline(std::cin, input)) {
        if (input == "exit") break;

        try {
            auto root = ExpressionParser::parse(input);

            std::cout << "Parsed: " << root->print() << std::endl;
            std::cout << "Result: " << root->calc() << std::endl;
        } catch (const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
        }

        std::cout << "\nEnter expression (or 'exit'): ";
    }

    return 0;
}
