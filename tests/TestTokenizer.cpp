
#include <gtest/gtest.h>
#include "../parser/Tokenizer.h"
#include "../utils/VariableInput.h"

TEST(TokenizerTest, ValidInteger) {
    VariableInput vi;
    auto tokens = Tokenizer::tokenize("42", vi);
    ASSERT_EQ(tokens[0].type, TokenType::Number);
    EXPECT_EQ(tokens[0].text, "42");
}

TEST(TokenizerTest, ValidFloat) {
    VariableInput vi;
    auto tokens = Tokenizer::tokenize("3.14", vi);
    ASSERT_EQ(tokens[0].type, TokenType::Number);
    EXPECT_EQ(tokens[0].text, "3.14");
}

TEST(TokenizerTest, ValidLeadingDot) {
    VariableInput vi;
    auto tokens = Tokenizer::tokenize(".3", vi);
    ASSERT_EQ(tokens[0].type, TokenType::Number);
    EXPECT_EQ(tokens[0].text, ".3");
}

TEST(TokenizerTest, ValidTrailingDot) {
    VariableInput vi;
    auto tokens = Tokenizer::tokenize("5.", vi);
    ASSERT_EQ(tokens[0].type, TokenType::Number);
    EXPECT_EQ(tokens[0].text, "5.");
}

TEST(TokenizerTest, InvalidMultipleDots) {
    VariableInput vi;
    EXPECT_THROW(Tokenizer::tokenize("3.8.8", vi), std::runtime_error);
    EXPECT_THROW(Tokenizer::tokenize("3..9", vi), std::runtime_error);
    EXPECT_THROW(Tokenizer::tokenize("..", vi), std::runtime_error);
}

TEST(TokenizerTest, InvalidOnlyDot) {
    VariableInput vi;
    EXPECT_THROW(Tokenizer::tokenize(".", vi), std::runtime_error);
}

TEST(TokenizerTest, RecognizesOperators) {
    VariableInput vi;
    auto tokens = Tokenizer::tokenize("+ - * /", vi);
    ASSERT_EQ(tokens[0].type, TokenType::Plus);
    ASSERT_EQ(tokens[1].type, TokenType::Minus);
    ASSERT_EQ(tokens[2].type, TokenType::Multiply);
    ASSERT_EQ(tokens[3].type, TokenType::Divide);
}

TEST(TokenizerTest, RecognizesParentheses) {
    VariableInput vi;
    auto tokens = Tokenizer::tokenize("(2 + 3)", vi);
    EXPECT_EQ(tokens[0].type, TokenType::LeftParen);
    EXPECT_EQ(tokens[4].type, TokenType::RightParen);
}

TEST(TokenizerTest, IgnoresSpaces) {
    VariableInput vi;
    auto tokens = Tokenizer::tokenize(" 2   +    3 ", vi);
    EXPECT_EQ(tokens.size(), 4); // 2, +, 3, End
    EXPECT_EQ(tokens[0].text, "2");
    EXPECT_EQ(tokens[2].text, "3");
}

TEST(TokenizerTest, RecognizesVariableAndSubstitutesValue) {
    VariableInput vi;
    vi.set("x", 3.0);
    auto tokens = Tokenizer::tokenize("x + 2", vi);
    EXPECT_EQ(tokens[0].type, TokenType::Number);
    EXPECT_EQ(tokens[0].text, "3.000000");
}

TEST(TokenizerTest, ThrowsOnUnknownCharacter) {
    VariableInput vi;
    EXPECT_THROW(Tokenizer::tokenize("2 + #", vi), std::runtime_error);
}

TEST(TokenizerTest, HandlesEmptyInput) {
    VariableInput vi;
    auto tokens = Tokenizer::tokenize("", vi);
    EXPECT_EQ(tokens.size(), 1);
    EXPECT_EQ(tokens[0].type, TokenType::End);
}

TEST(TokenizerTest, MultiLetterVariableName) {
    VariableInput vi;
    vi.set("temp", 42.0);
    auto tokens = Tokenizer::tokenize("temp + 1", vi);
    EXPECT_EQ(tokens[0].text, "42.000000");
}

