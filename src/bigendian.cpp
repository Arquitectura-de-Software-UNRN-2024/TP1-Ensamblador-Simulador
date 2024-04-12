/**
 * @file bigendian.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief This file implement the function that converts a line to big endian
 * 32-bit integer
 * [0 x 0A 0B 0C 0D]
 * in memory:
 * a+0[0A]
 * a+1[0B]
 * a+2[0C]
 * a+3[0D]
 * and viceverse
 * @version 0.1
 * @date 2024-04-11
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/bigendian.hpp"

void to_big_endian(uint32_t num, char buffer[4]) {
    buffer[0] = static_cast<char>((num >> 24) & 0xFF);
    buffer[1] = static_cast<char>((num >> 16) & 0xFF);
    buffer[2] = static_cast<char>((num >> 8) & 0xFF);
    buffer[3] = static_cast<char>((num >> 0) & 0xFF);
}

uint32_t from_big_endian(char buffer[4]) {
    return (static_cast<uint32_t>(buffer[0] & 0xFF) << 24) |
           (static_cast<uint32_t>(buffer[1] & 0xFF) << 16) |
           (static_cast<uint32_t>(buffer[2] & 0xFF) <<  8) |
           (static_cast<uint32_t>(buffer[3] & 0xFF) <<  0);
}
