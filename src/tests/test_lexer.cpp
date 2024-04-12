/**
 * @file test_lexer.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-04-05
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "../../include/Lexer.hpp"
#include "../../include/Tokens.hpp"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

Test(split, test) {
    std::vector<std::string> result =
        Lexer::split(" Hola  esto\n es\n\run test  \r \n");
    std::vector<std::string> expected = {"Hola", "esto", "es", "un", "test"};
    cr_assert_eq(result, expected);
}

Test(tokenizer, test) {
    std::vector<std::unique_ptr<Token>> result = Lexer::tokenize("LOAD 3");
    std::vector<std::unique_ptr<Token>> expected;
    expected.push_back(
        std::unique_ptr<Token>(new Operation(OperationValue::LOAD)));
    expected.push_back(std::unique_ptr<Token>(new Number(3)));
    cr_assert_eq(result.size(), expected.size());
    for (size_t i = 0; i < result.size(); ++i) {
        cr_assert_eq(result[i]->get_value(), expected[i]->get_value());
    }
}

Test(tokenizer_out_of_range, test) {
    // 2²⁵ = 33554432
    bool exception = false;
    try {
        Lexer::tokenize("LOAD 33554432");
    } catch (Lexer::OutOfRange) {
        exception = true;
    }
    cr_assert(exception);
}

Test(tokenizer_invalid_token, test) {
    bool exception = false;
    try {
        Lexer::tokenize("LOADi 3");
    } catch (Lexer::LexicalError) {
        exception = true;
    }
    cr_assert(exception);
}
