/**
 * @file int24.hpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include <stdint.h>

#define INT24_MAX 0x007FFFFF
#define INT24_MIN 0xFF800000

/**
 * @brief Converts a 32bit buffer representing a 24 bit signed number into a
 * 32bit signed integer with the corresponding value.
 *
 * @param i24_to_interpret is the 32bit buffer with the 24 bit signed number to
 * convert into a signed 32bit integer.
 * @pre is properly formated as 24 bit signed integer with 2's compliment.
 *
 * @returns a singed 32bit integer with the proper value represented by
 * `i24_to_interpret`.
 */
int32_t from_int24(uint32_t i24_to_interpret);

/**
 * @brief Converts a
 * 32bit signed integer
 * into a
 * 32bit buffer representing a 24 bit signed number
 * with the corresponding value.
 *
 * @param number_to_format is the signed 32bit integer to convert into a
 * 32bit buffer with the 24 bit signed number.
 * @pre it's value is within the representable limits of a 24 bit signed
 * integer (INT24_MIN <= number_to_format <= INT24_MAX).
 *
 * @returns a 32bit buffer representing the value of `number_to_format` as a 24
 * bit signed integer with 2's compliment.
 */
uint32_t to_int24(int32_t number_to_format);
