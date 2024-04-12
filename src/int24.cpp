/**
 * @file int24.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief Conversion functions for int24 type.
 * @version 0.1
 * @date 2024-04-10
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "../include/int24.hpp"

int32_t from_int24(uint32_t i24_to_interpret) {
    i24_to_interpret &= 0x00FFFFFF;
    i24_to_interpret -= ((i24_to_interpret & INT24_MIN) << 1);
    return static_cast<int32_t>(i24_to_interpret);
}

uint32_t to_int24(int32_t number_to_format) {
    number_to_format &= 0x00FFFFFF;
    return static_cast<uint32_t>(number_to_format);
}
