/**
 * @file main.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "../../include/Lexer.hpp"
#include "../../include/cli.hpp"
#include <cstdlib>
#include <iostream>

// Include temporal
#include "../../include/int24.hpp"

int main(int argc, const char *argv[]) {
    if (cli::needs_help(argc, argv)) {
        std::cout << cli::help_str << std::endl;
        exit(0);
    }
    struct cli::Files files;
    try {
        files = cli::parse_args(argc, argv);
    } catch (const std::exception &e) {
        std::cerr << BOLDWHITE "ensamblador: " RED "error fatal: " RESET
                  << e.what() << "\ncompilación terminada." << std::endl;
        exit(-1);
    }
    unsigned int line_number = 0;
    for (std::string line; std::getline(files.ifile, line);) {
        std::vector<std::unique_ptr<Token>> tokens;
        try {
            tokens = Lexer::tokenize(line);
        } catch (const std::exception &e) {
            std::cerr << BOLDWHITE "ensamblador: " RED "error fatal: " RESET
                      << e.what() << " in line " << line_number << "\n"
                      << line << "\ncompilación terminada." << std::endl;
            exit(-1);
        }
        // Aca iria el parser, esto es temporal
        for (int i = 0; i < tokens.size(); ++i) {
            switch (tokens[i]->get_type()) {
                case TokenType::Nothing:
                    std::cout << "Nothing ";
                    break;
                case TokenType::Operation:
                    std::cout << "Operation(";
                    switch (tokens[i]->get_value()) {
                        case (uint32_t)OperationValue::LOAD:
                            std::cout << "LOAD";
                            break;
                        case (uint32_t)OperationValue::ADD:
                            std::cout << "ADD";
                            break;
                        case (uint32_t)OperationValue::PRINT:
                            std::cout << "PRINT";
                            break;
                    }
                    std::cout << ") ";
                    break;
                case TokenType::Number:
                    std::cout << "Number(" << from_int24(tokens[i]->get_value())
                              << ") ";
                    break;
            }
        }
        std::cout << std::endl;
        // Fin de lo temporal
        ++line_number;
    }
    // TODO: Escribir a files.ofile
    return 0;
}
