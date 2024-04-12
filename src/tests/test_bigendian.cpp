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
#include "../../include/bigendian.hpp"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <cstdint>

Test(to_big_endian, test) {
    char result[4];
    to_big_endian(0x12345678, result);
    char expected[4] = {0x12, 0x34, 0x56, 0x78};
    for (int i = 0; i < 4; ++i) {
        cr_assert_eq(result[i], expected[i]);
    }
}

Test(from_big_endian, test) {
    char bigendian[4] = {0x12, 0x34, 0x56, 0x78};
    uint32_t result = from_big_endian(bigendian);
    uint32_t expected = 0x12345678;
    cr_assert_eq(result, expected);
}
