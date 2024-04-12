/**
 * @file Syntax.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief cpp file for parse
 * @version 0.1
 * @date 2024-04-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/Syntax.hpp"


uint32_t Syntax::parse(std::vector<std::unique_ptr<Token>> tokens) {

    bool is_valid_grammar = false;

    if (!tokens[0]->can_be_first()) {
        SyntaxError e;
        throw e;
    }

    std::vector<std::vector<TokenType>> valid_grammars =
        tokens[0]->should_be_followed_by();

    std::vector<TokenType> tokentypes;
    tokentypes.resize(tokens.size()-1);
    for (int i = 0; i < tokentypes.size(); i++){
        tokentypes[i] = tokens[i+1]->get_type();
    }
    for (std::vector<TokenType> valid_grammar : valid_grammars){
        if (tokentypes == valid_grammar){
            is_valid_grammar = true;
        }
    }
    if (!is_valid_grammar){
        SyntaxError e;
        throw e; 
    }

    uint32_t ret = 0;
    for (int i = 0; i < tokens.size(); ++i) {
        ret |= tokens[i]->get_value();
    }
    return ret;
}

const char *Syntax::SyntaxError::what() const noexcept(true) { return msg; }
