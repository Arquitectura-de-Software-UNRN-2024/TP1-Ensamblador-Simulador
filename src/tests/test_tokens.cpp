/**
 * @file test_tokens.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-04-05
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "../../include/Tokens.hpp"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

Test(parse_op, test) {
    OperationValue result = OperationValuesLookup::parse("LOAD").value();
    OperationValue expected = OperationValue::LOAD;
    cr_assert_eq(result, expected);
}

Test(parse_op_fail, test) {
    bool result = OperationValuesLookup::parse("RESTA").has_value();
    bool expected = false;
    cr_assert_eq(result, expected);
}

Test(should_be_followed_number, test) {
    Operation op(OperationValue::LOAD);
    std::vector<std::vector<TokenType>> result = op.should_be_followed_by();
    int expected_size = 1;
    cr_assert_eq(result.size(), expected_size);
    int inner_expected_size = 1;
    cr_assert_eq(result[0].size(), inner_expected_size);
    TokenType expected_value = TokenType::Number;
    cr_assert_eq(result[0][0], expected_value);
}

Test(should_be_followed_nothing, test) {
    Operation op(OperationValue::PRINT);
    std::vector<std::vector<TokenType>> result = op.should_be_followed_by();
    int expected_size = 1;
    cr_assert_eq(result.size(), expected_size);
    int inner_expected_size = 0;
    cr_assert_eq(result[0].size(), inner_expected_size);
}

Test(Op_type, test) {
    TokenType result = Operation(OperationValue::LOAD).get_type();
    TokenType expected = TokenType::Operation;
    cr_assert_eq(result, expected);
}

Test(Num_type, test) {
    TokenType result = Number(0).get_type();
    TokenType expected = TokenType::Number;
    cr_assert_eq(result, expected);
}
