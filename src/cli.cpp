#include "../include/cli.hpp"
#include <cstring>
#include <utility>

const char *cli::help_str =
    "Modo de empleo: gcc [opciones] "
    "fichero...\nOpciones:\n--help | -h              "
    "Muestra esta información.\n-o <fichero>             "
    "Coloca la salida en el <fichero>.";

bool cli::needs_help(int argc, const char *argv[]) {
    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "--help") == 0 ||
            std::strcmp(argv[i], "-h") == 0) {
            return true;
        }
    }
    return false;
}

struct cli::Files cli::parse_args(int argc, const char *argv[]) {
    if (argc < 2) {
        NoInFile e;
        throw e;
    }
    if (argc > 4) {
        TooManyArgs e;
        throw e;
    }
    int o_index = -1;
    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "-o") == 0) {
            o_index = i;
        }
    }
    if (o_index == -1) {
        if (argc > 2) {
            TooManyArgs e;
            throw e;
        }
    }
    if (o_index != -1 && (o_index > 2 || argc != 4)) {
        BadOUse e;
        throw e;
    }
    // --- ifile	 -o	ofile
    //  0    1 	  2	  3
    // ---  -o		ofile ifile
    int i_index = o_index == 2 || o_index == -1 ? 1 : 3;
    std::string of_name = o_index == -1 ? "out_" + std::string(argv[i_index])
                                        : argv[o_index + 1];
    std::ifstream ifile(argv[i_index]);
    if (!ifile.is_open()) {
        FailToOpenInFile e;
        throw e;
    }
    std::ofstream ofile(of_name);
    if (!ofile.is_open()) {
        FailToOpenOutFile e;
        throw e;
    }
    return cli::Files{std::move(ifile), std::move(ofile)};
}

const char *cli::NoInFile::what() const noexcept(true) { return msg; }

const char *cli::TooManyArgs::what() const noexcept(true) { return msg; }

const char *cli::BadOUse::what() const noexcept(true) { return msg; }

const char *cli::FailToOpenInFile::what() const noexcept(true) { return msg; }

const char *cli::FailToOpenOutFile::what() const noexcept(true) { return msg; }
