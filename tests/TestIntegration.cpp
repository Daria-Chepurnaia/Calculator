#include <gtest/gtest.h>
#include "../parser/Tokenizer.h"
#include "../parser/ExpressionParser.h"
#include "../utils/VariableInput.h"

TEST(ExpressionParserTest, Addition) {
    VariableInput vi;
    auto tokens = Tokenizer::tokenize("3 + 4", vi);
    auto expr = ExpressionParser::parseFromTokens(tokens);
    EXPECT_DOUBLE_EQ(expr->calc(), 7.0);
}

TEST(ExpressionParserTest, Subtraction) {
    VariableInput vi;
    auto tokens = Tokenizer::tokenize("10 - 4", vi);
    auto expr = ExpressionParser::parseFromTokens(tokens);
    EXPECT_DOUBLE_EQ(expr->calc(), 6.0);
}

TEST(ExpressionParserTest, Multiplication) {
    VariableInput vi;
    auto tokens = Tokenizer::tokenize("3 * 5", vi);
    auto expr = ExpressionParser::parseFromTokens(tokens);
    EXPECT_DOUBLE_EQ(expr->calc(), 15.0);
}

TEST(ExpressionParserTest, Division) {
    VariableInput vi;
    auto tokens = Tokenizer::tokenize("15 / 3", vi);
    auto expr = ExpressionParser::parseFromTokens(tokens);
    EXPECT_DOUBLE_EQ(expr->calc(), 5.0);
}

TEST(ExpressionParserTest, SupportsFloatingPointArithmetic) {
    VariableInput vi;
    auto tokens = Tokenizer::tokenize("3.5 * 5.3", vi);
    auto expr = ExpressionParser::parseFromTokens(tokens);
    EXPECT_DOUBLE_EQ(expr->calc(), 18.55);
}

TEST(ExpressionParserTest, MultiplicationBeforeAddition) {
    VariableInput vi;
    auto tokens = Tokenizer::tokenize("2 + 3 * 4", vi);
    auto expr = ExpressionParser::parseFromTokens(tokens);
    EXPECT_DOUBLE_EQ(expr->calc(), 14.0);
}

TEST(ExpressionParserTest, ParenthesesOverridePrecedence) {
    VariableInput vi;
    auto tokens = Tokenizer::tokenize("(2 + 3) * 4", vi);
    auto expr = ExpressionParser::parseFromTokens(tokens);
    EXPECT_DOUBLE_EQ(expr->calc(), 20.0);
}

TEST(ExpressionParserTest, UnaryMinusSimple) {
    VariableInput vi;
    auto tokens = Tokenizer::tokenize("-5", vi);
    auto expr = ExpressionParser::parseFromTokens(tokens);
    EXPECT_DOUBLE_EQ(expr->calc(), -5.0);
}

TEST(ExpressionParserTest, UnaryMinusWithParens) {
    VariableInput vi;
    auto tokens = Tokenizer::tokenize("-(3 + 2)", vi);
    auto expr = ExpressionParser::parseFromTokens(tokens);
    EXPECT_DOUBLE_EQ(expr->calc(), -5.0);
}

TEST(ExpressionParserTest, VariableResolution) {
    VariableInput vi;
    vi.set("x", 5.0);
    auto tokens = Tokenizer::tokenize("x + 2", vi);
    auto expr = ExpressionParser::parseFromTokens(tokens);
    EXPECT_DOUBLE_EQ(expr->calc(), 7.0);
}

TEST(ExpressionParserTest, VariableResolutionVarOccuredTwice) {
    VariableInput vi;
    vi.set("x", 5.0);
    auto tokens = Tokenizer::tokenize("x + 2 + x", vi);
    auto expr = ExpressionParser::parseFromTokens(tokens);
    EXPECT_DOUBLE_EQ(expr->calc(), 12.0);
}

TEST(ExpressionParserTest, VariableResolutionTwoDifferentVars) {
    VariableInput vi;
    vi.set("x", 5.0);
    vi.set("y", 6.0);
    auto tokens = Tokenizer::tokenize("x + 2 + y", vi);
    auto expr = ExpressionParser::parseFromTokens(tokens);
    EXPECT_DOUBLE_EQ(expr->calc(), 13.0);
}

TEST(ExpressionParserTest, UnmatchedParenthesisThrows) {
    VariableInput vi;
    auto tokens = Tokenizer::tokenize("(2 + 3", vi);
    EXPECT_THROW(ExpressionParser::parseFromTokens(tokens), std::runtime_error);
}

TEST(ExpressionParserTest, DivisionByZeroThrows) {
    VariableInput vi;
    auto tokens = Tokenizer::tokenize("5 / (3 - 3)", vi);
    auto expr = ExpressionParser::parseFromTokens(tokens);
    EXPECT_THROW(expr->calc(), std::runtime_error);
}