/**
 * @file bigendian.hpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief the hpp file to the function to convert a num to big endian and from
 * big endian
 * @version 0.1
 * @date 2024-04-11
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <cstdint>

/**
 * @brief a function to convert a num to big endian
 *
 * @param num
 * @param buffer
 */
void to_big_endian(uint32_t num, char buffer[4]);

/**
 * @brief a function to convert a big endian to num
 *
 * @param buffer
 * @return uint32_t
 */
uint32_t from_big_endian(char buffer[4]);