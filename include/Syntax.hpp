/**
 * @file Syntax.hpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief Header file for syntax analysis functions.
 * @version 0.1
 * @date 2024-04-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once
#include "Tokens.hpp"
#include <memory>

/**
 * @brief Parses a vector of tokens and performs syntax analysis.
 * @param tokens The vector of tokens to parse.
 * @return The result of the syntax analysis (implementation specific).
 * @throws SyntaxError If a syntax error is encountered.
 */
namespace Syntax {
    uint32_t parse(std::vector<std::unique_ptr<Token>>);

    class SyntaxError : public std::exception {
    public:
        SyntaxError() = default;
        ~SyntaxError() = default;
        SyntaxError(SyntaxError &&) = default;
        SyntaxError(const SyntaxError &) = default;
        const char *what() const noexcept(true) override;

    private:
        const char *msg = "SyntaxError: found invalid grammar";
    };

}; // namespace Syntax