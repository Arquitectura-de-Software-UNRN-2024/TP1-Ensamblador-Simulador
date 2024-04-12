/**
 * @file tobigendian.cpp
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
 * @version 0.1
 * @date 2024-04-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/tobigendian.hpp"

/**
 * @brief a function to convert a num to big endian
 * 
 * @param num 
 * @param buffer 
 */
void convert_to_Big_Endian(uint32_t num, char buffer[4]){
    buffer[0] = (num >> 24) & 0xFF;
    buffer[1] = (num >> 16) & 0xFF;
    buffer[2] = (num >>  8) & 0xFF;
    buffer[3] = (num >>  0) & 0xFF;
}