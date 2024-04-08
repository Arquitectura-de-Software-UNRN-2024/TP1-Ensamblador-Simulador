#include "../include/Lexer.hpp"
#include "../include/int24.hpp"

std::vector<std::unique_ptr<Token>> Lexer::tokenize(std::string line) {
    std::vector<std::unique_ptr<Token>> ret;
    std::vector<std::string> words = Lexer::split(line);
    for (std::string word : words) {
        std::optional<OperationValue> op_val_option =
            OperationValuesLookup::parse(word);
        if (op_val_option.has_value()) {
            ret.push_back(
                std::unique_ptr<Token>(new Operation(op_val_option.value())));
            continue;
        }
        int32_t num;
        try {
            num = stoi(word);
        } catch(...) {
            LexicalError e;
            throw e;
        }
        if (num < (int32_t)INT24_MIN || num > (int32_t)INT24_MAX) {
            OutOfRange e;
            throw e;
        }
        ret.push_back(std::unique_ptr<Token>(new Number(to_int24(num))));
    }
    return ret;
}

std::vector<std::string> Lexer::split(std::string line) {
    std::vector<std::string> ret;
    char prev = ' ';
    for (char &character : line) {
        if (!std::isspace(character)) {
            if (std::isspace(prev)) {
                std::string new_token;
                ret.push_back(new_token);
            }
            ret.back().push_back(character);
        }
        prev = character;
    }
    return ret;
}

const char *Lexer::OutOfRange::what() const noexcept(true) { return msg; }

const char *Lexer::LexicalError::what() const noexcept(true) { return msg; }
