/**
 * @file bigendian.hpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief the hpp file to the function to convert a num to big endian and from big endian
 * @version 0.1
 * @date 2024-04-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <cstdint>

void to_big_endian(uint32_t num, char buffer[4]);

uint32_t from_big_endian(char buffer[4]);