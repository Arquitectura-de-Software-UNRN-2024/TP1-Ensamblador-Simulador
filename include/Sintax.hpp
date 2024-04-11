/**
 * @file Sintax.hpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief ESte es el hpp para 
 * @version 0.1
 * @date 2024-04-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once
#include "Tokens.hpp"
#include <memory>

namespace Sintax{
    uint32_t parse(std::vector<std::unique_ptr<Token>>);
    
}; //namespace Sintax