/**
 * @file Tokens.hpp
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
#include <cstdint>
#include <map>
#include <optional>
#include <string>
#include <vector>

enum class TokenType { Nothing, Operation, Number };

enum class OperationValue {
  LOAD = 0x01000000,
  ADD = 0x02000000,
  PRINT = 0x03000000,
};

class Token {
public:
  virtual uint32_t get_value() const = 0;
  virtual bool can_be_first() const = 0;
  virtual std::vector<std::vector<TokenType>> should_be_followed_by() const = 0;
  virtual TokenType get_type() const = 0;
};

class Operation : public Token {
public:
  Operation(OperationValue);
  virtual uint32_t get_value() const override;
  virtual bool can_be_first() const override;
  virtual std::vector<std::vector<TokenType>> should_be_followed_by() const override;
  virtual TokenType get_type() const override;

private:
  OperationValue value;
};

class Number : public Token {
public:
  Number(uint32_t);
  virtual uint32_t get_value() const override;
  virtual bool can_be_first() const override;
  virtual std::vector<std::vector<TokenType>> should_be_followed_by() const override;
  virtual TokenType get_type() const override;

private:
  uint32_t int24_value;
};

class OperationValuesLookup {
public:
  static std::optional<OperationValue> parse(const std::string);

private:
  static const std::map<std::string, OperationValue> values_map;
};
