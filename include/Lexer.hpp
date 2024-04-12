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

/**
 * @brief Tokeniza una línea de texto en tokens.
 * @param line La línea de texto.
 * @return Vector de punteros únicos a tokens.
 * @throws LexicalError Si se encuentra un token no válido.
 * @throws OutOfRange Si el valor numérico está fuera del rango válido para
 * int24.
 */
std::vector<std::unique_ptr<Token>> tokenize(std::string);

/**
 * @brief Divide una línea de texto en palabras individuales.
 * @param line La línea de texto.
 * @return Vector de palabras identificadas.
 */
std::vector<std::string> split(std::string line);

class OutOfRange : public std::exception {
  public:
    OutOfRange() = default;
    ~OutOfRange() = default;
    OutOfRange(OutOfRange &&) = default;
    OutOfRange(const OutOfRange &) = default;
    const char *what() const noexcept(true) override;

  private:
    const char *msg = "OutOfRange: Given value out of int24 range";
};

class LexicalError : public std::exception {
  public:
    LexicalError() = default;
    ~LexicalError() = default;
    LexicalError(LexicalError &&) = default;
    LexicalError(const LexicalError &) = default;
    const char *what() const noexcept(true) override;

  private:
    const char *msg = "LexicalError: Found an unrecognized token";
};

}; // namespace Lexer
