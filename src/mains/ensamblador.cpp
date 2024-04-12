/**
 * @file ensamblador.cpp
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
#include "../../include/Syntax.hpp"
#include "../../include/bigendian.hpp"
#include "../../include/cli.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, const char *argv[]) {
    if (cli::needs_help(argc, argv)) {
        std::cout << cli::assembler::help_str << std::endl;
        exit(0);
    }
    struct cli::assembler::Files files;
    try {
        files = cli::assembler ::parse_args(argc, argv);
    } catch (const std::exception &e) {
        std::cerr << BOLDWHITE "ensamblador: " RED "error fatal: " RESET
                  << e.what() << "\ncompilación terminada." << std::endl;
        exit(-1);
    }
    unsigned int line_number = 0;
    for (std::string line; std::getline(files.ifile, line);) {
        std::vector<std::unique_ptr<Token>> tokens;
        uint32_t bin_line;
        try {
            tokens = Lexer::tokenize(line);
            bin_line = Syntax::parse(std::move(tokens));
        } catch (const std::exception &e) {
            std::cerr << BOLDWHITE "ensamblador: " RED "error fatal: " RESET
                      << e.what() << " in line " << line_number << "\n"
                      << line << "\ncompilación terminada." << std::endl;
            exit(-1);
        }
        ++line_number;
        char buffer[4];
        to_big_endian(bin_line, buffer);
        files.ofile.write(buffer, 4);
    }
    return 0;
}
