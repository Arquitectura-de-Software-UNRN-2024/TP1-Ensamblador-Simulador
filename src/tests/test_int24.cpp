/**
 * @file test_operation_methods.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-04-05
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "../../include/int24.hpp"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <cstdint>

Test(to_int24_binmax, test) {
    uint32_t result = to_int24(-1);
    uint32_t expected = 0x00FFFFFF;
    cr_assert_eq(result, expected);
}

Test(to_int24_binmin, test) {
    uint32_t result = to_int24(0);
    uint32_t expected = 0x00000000;
    cr_assert_eq(result, expected);
}

Test(to_int24_min, test) {
    uint32_t result = to_int24(INT24_MIN);
    uint32_t expected = 0x00800000;
    cr_assert_eq(result, expected);
}

Test(to_int24_max, test) {
    uint32_t result = to_int24(INT24_MAX);
    uint32_t expected = 0x007FFFFF;
    cr_assert_eq(result, expected);
}

Test(to_int24_pos, test) {
    uint32_t result = to_int24(147);
    uint32_t expected = 147;
    cr_assert_eq(result, expected);
}

Test(to_int24_neg, test) {
    uint32_t result = to_int24(-147);
    uint32_t expected = 0x00FFFF6D;
    cr_assert_eq(result, expected);
}
