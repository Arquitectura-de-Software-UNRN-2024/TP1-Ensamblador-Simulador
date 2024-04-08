/**
 * @file Lexer.hpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief Contiene las clases encargadas de convertir
 * el archivo de entrada a un arreglo de tokens.
 * @version 0.1
 * @date 2024-04-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once
#include "Tokens.hpp"
#include <memory>
namespace Lexer {

std::vector<std::unique_ptr<Token>> tokenize(std::string);
std::vector<std::string> split(std::string line);

class OutOfRange : public std::exception {
  public:
    OutOfRange() = default;
    ~OutOfRange() = default;
    OutOfRange(OutOfRange &&) = default;
    OutOfRange(const OutOfRange &) = default;
    const char *what() const noexcept(true) override;

  private:
    const char *msg = "OutOfRange: Given value out of int24 range.";
};

class LexicalError : public std::exception {
  public:
    LexicalError() = default;
    ~LexicalError() = default;
    LexicalError(LexicalError &&) = default;
    LexicalError(const LexicalError &) = default;
    const char *what() const noexcept(true) override;

  private:
    const char *msg = "LexicalError: Found an unrecognized token.";
};

}; // namespace Lexer
