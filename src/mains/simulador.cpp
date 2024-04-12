#include "../../include/cli.hpp"
#include "../../include/emulator.hpp"
#include <fstream>
#include <iostream>

int main(int argc, const char *argv[]) {
    if (cli::needs_help(argc, argv)) {
        std::cout << cli::emulator::help_str << std::endl;
        exit(0);
    }
    int debug_i = cli::emulator::debug_index(argc, argv);
    std::ifstream file;
    try {
        file = cli::emulator::parse_args(argc, argv, debug_i);
    } catch (const std::exception &e) {
        std::cerr << BOLDWHITE "simulador: " RED "error fatal: " RESET
                  << e.what() << "\nejecucion terminada." << std::endl;
        exit(-1);
    }
    Emulator *cpu;
    if (debug_i == -1) {
        cpu = new Emulator();
    } else {
        for (int i = 0; i < 8; i++) {
            std::cout << "\n";
        }
        cpu = new DebugEmulator();
    }
    try {
        cpu->run(std::move(file));
    } catch (const std::exception &e) {
        std::cerr << "\n" BOLDWHITE "simulador: " RED "error fatal: " RESET
                  << e.what() << "\nejecucion terminada." << std::endl;
        exit(-1);
    }
    delete cpu;
    return 0;
}
