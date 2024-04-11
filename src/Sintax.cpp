/**
 * @file Sintax.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/Sintax.hpp"

uint32_t Sintax::parse(std::vector<std::unique_ptr<Token>> tokens){

    if (!tokens[0]->can_be_first()){
        return -1; //cambiar por exception
    }
    std::vector<std::vector<TokenType>> types = tokens[0]->should_be_followed_by();
    for (int i = 0; i < types.size(); i++){
        
    }
    
    /* {Number} v {Nada}*/

    uint32_t ret = 0;
    for (int i=0;i<tokens.size();++i){
        ret |= tokens[i]->get_value();
    }
    return ret;

}

