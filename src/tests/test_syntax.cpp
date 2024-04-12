/**
 * @file test_syntax.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <memory>
#include "../../include/Syntax.hpp"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

/**
 * @brief Test for invalid token: load expects a number
 * 
 */
Test(parser_invalid_token_O, test) {
    bool exception = false;
    std::vector<std::unique_ptr<Token>> expression;
    expression.push_back(std::unique_ptr<Token>(new Operation(OperationValue::LOAD)));
    try {
        Syntax::parse(std::move(expression));
    } catch (Syntax::SyntaxError) {
        exception = true;
    }
    cr_assert(exception);
}

/**
 * @brief Test for invalid token: too many tokens
 * 
 */
Test(parser_invalid_token_O_N_N, test) {
    bool exception = false;
    std::vector<std::unique_ptr<Token>> expression;
    expression.push_back(std::unique_ptr<Token>(new Operation(OperationValue::LOAD)));
    expression.push_back(std::unique_ptr<Token>(new Number(0)));
    expression.push_back(std::unique_ptr<Token>(new Number(0)));
    try {
        Syntax::parse(std::move(expression));
    } catch (Syntax::SyntaxError) {
        exception = true;
    }
    cr_assert(exception);
}

/**
 * @brief Test for invalid token: number cant be first
 * 
 */
Test(parser_invalid_token_N_N, test) {
    bool exception = false;
    std::vector<std::unique_ptr<Token>> expression;
    expression.push_back(std::unique_ptr<Token>(new Number(0)));
    expression.push_back(std::unique_ptr<Token>(new Number(0)));
    try {
        Syntax::parse(std::move(expression));
    } catch (Syntax::SyntaxError) {
        exception = true;
    }
    cr_assert(exception);
}

/**
 * @brief Test for invalid token: operation operation not valid
 * 
 */
Test(parser_invalid_token_O_O, test) {
    bool exception = false;
    std::vector<std::unique_ptr<Token>> expression;
    expression.push_back(std::unique_ptr<Token>(new Operation(OperationValue::LOAD)));
    expression.push_back(std::unique_ptr<Token>(new Operation(OperationValue::PRINT)));
    try {
        Syntax::parse(std::move(expression));
    } catch (Syntax::SyntaxError) {
        exception = true;
    }
    cr_assert(exception);
}

/**
 * @brief Test for valid token: operation print must be unique
 * 
 */
Test(parser_valid_token_O, test) {
    uint32_t expected = 0x03000000;
    std::vector<std::unique_ptr<Token>> expression;
    expression.push_back(std::unique_ptr<Token>(new Operation(OperationValue::PRINT)));
    uint32_t result = Syntax::parse(std::move(expression));
    cr_assert_eq(expected,result);
}

/**
 * @brief Test for valid token: operation add must recieve a number
 *  * 
 */
Test(parser_valid_token_O_N, test) {
    uint32_t expected = 0x0200000A;
    std::vector<std::unique_ptr<Token>> expression;
    expression.push_back(std::unique_ptr<Token>(new Operation(OperationValue::ADD)));
    expression.push_back(std::unique_ptr<Token>(new Number(10)));
    uint32_t result = Syntax::parse(std::move(expression));
    cr_assert_eq(expected,result);
}