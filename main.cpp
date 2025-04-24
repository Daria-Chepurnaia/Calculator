#include <iostream>
#include <string>
#include <memory>
#include "parser/ExpressionParser.h"   
#include "nodes/INode.h"               

int main() {
    std::string input;

    while (true) {
        std::cout << "Enter expression (e.g. 4 + 5), or 'exit' to quit: ";
        std::getline(std::cin, input);

        if (input == "exit")
            break;

        try {
            std::unique_ptr<INode> exprTree = ExpressionParser::parse(input);
            std::cout << "Formatted expression: " << exprTree->print() << std::endl;
            std::cout << "Result: " << exprTree->calc() << std::endl;
        } catch (const std::exception& ex) {
            std::cerr << "Invalid input: " << ex.what() << std::endl;
        }
    }

    return 0;
}