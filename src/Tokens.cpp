/**
 * @file Tokens.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief A cpp file implementing the functions on hpp
 * @version 0.1
 * @date 2024-04-10
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "../include/Tokens.hpp"

std::map<std::string, OperationValue> const OperationValuesLookup::values_map =
    {
        {"LOAD", OperationValue::LOAD},
        {"ADD", OperationValue::ADD},
        {"PRINT", OperationValue::PRINT},
};

std::optional<OperationValue>
OperationValuesLookup::parse(const std::string crude_operation) {
    std::optional<OperationValue> ret;
    if (values_map.contains(crude_operation)) {
        ret = values_map.at(crude_operation);
    }
    return ret;
}

Operation::Operation(OperationValue v) : value(v) {}

uint32_t Operation::get_value() const { return static_cast<uint32_t>(value); }

bool Operation::can_be_first() const { return true; }

std::vector<std::vector<TokenType>> Operation::should_be_followed_by() const {
    std::vector<std::vector<TokenType>> ret;
    switch (value) {
        case OperationValue::LOAD:
        case OperationValue::ADD:
            ret = {{TokenType::Number}};
            break;
        case OperationValue::PRINT:
            ret = {{}};
            break;
    }
    return ret;
}

TokenType Operation::get_type() const { return TokenType::Operation; }

Number::Number(uint32_t v) : int24_value(v) {}

uint32_t Number::get_value() const { return int24_value; }

bool Number::can_be_first() const { return false; }

std::vector<std::vector<TokenType>> Number::should_be_followed_by() const {
    return {{}};
}

TokenType Number::get_type() const { return TokenType::Number; }
