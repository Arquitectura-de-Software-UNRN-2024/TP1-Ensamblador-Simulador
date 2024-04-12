/**
 * @file cli.hpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief  Header file for command-line interface functions and exceptions.
 * @version 0.1
 * @date 2024-04-10
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <fstream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define BOLDWHITE "\033[1m\033[37m"

namespace cli {

/**
 * @brief Checks if the user needs help based on command-line arguments.
 * @param argc Number of arguments passed to the program.
 * @param argv Array of argument strings.
 * @return True if help is requested, false otherwise.
 */
bool needs_help(int argc, const char *argv[]);

namespace assembler {

extern const char *help_str;

struct Files {
    std::ifstream ifile;
    std::ofstream ofile;
};

/**
 * @brief Parses command-line arguments and returns an object containing
 * input/output files.
 * @param argc Number of arguments passed to the program.
 * @param argv Array of argument strings.
 * @return A Files struct containing the parsed input and output files.
 * @throws TooManyArgs If there are too many arguments.
 * @throws NoInFile If no input file is specified.
 * @throws BadOUse If -o flag is used incorrectly.
 * @throws FailToOpenInFile If the input file cannot be opened.
 * @throws FailToOpenOutFile If the output file cannot be opened.
 */
struct Files parse_args(int argc, const char *argv[]);

} // namespace assembler

class NoInFile : public std::exception {
  public:
    NoInFile() = default;
    ~NoInFile() = default;
    NoInFile(NoInFile &&) = default;
    NoInFile(const NoInFile &) = default;
    const char *what() const noexcept(true) override;

  private:
    const char *msg = "no hay ficheros de entrada";
};

class TooManyArgs : public std::exception {
  public:
    TooManyArgs() = default;
    ~TooManyArgs() = default;
    TooManyArgs(TooManyArgs &&) = default;
    TooManyArgs(const TooManyArgs &) = default;
    const char *what() const noexcept(true) override;

  private:
    const char *msg = "demasiados argumentos";
};

class BadOUse : public std::exception {
  public:
    BadOUse() = default;
    ~BadOUse() = default;
    BadOUse(BadOUse &&) = default;
    BadOUse(const BadOUse &) = default;
    const char *what() const noexcept(true) override;

  private:
    const char *msg = "uso incorrecto de -o, falta <fichero>";
};

class FailToOpenInFile : public std::exception {
  public:
    FailToOpenInFile() = default;
    ~FailToOpenInFile() = default;
    FailToOpenInFile(FailToOpenInFile &&) = default;
    FailToOpenInFile(const FailToOpenInFile &) = default;
    const char *what() const noexcept(true) override;

  private:
    const char *msg = "problema abriendo el archivo de entrada";
};

class FailToOpenOutFile : public std::exception {
  public:
    FailToOpenOutFile() = default;
    ~FailToOpenOutFile() = default;
    FailToOpenOutFile(FailToOpenOutFile &&) = default;
    FailToOpenOutFile(const FailToOpenOutFile &) = default;
    const char *what() const noexcept(true) override;

  private:
    const char *msg = "problema abriendo el archivo de salida";
};

class ImposibleDebugIndex : public std::exception {
  public:
    ImposibleDebugIndex() = default;
    ~ImposibleDebugIndex() = default;
    ImposibleDebugIndex(ImposibleDebugIndex &&) = default;
    ImposibleDebugIndex(const ImposibleDebugIndex &) = default;
    const char *what() const noexcept(true) override;

  private:
    const char *msg = "El flag de debug está en un indice impesible";
};
namespace emulator {

extern const char *help_str;

/**
 * @brief Parses command-line arguments and extracts the debug flag index.
 * @param argc Number of arguments passed to the program.
 * @param argv Array of argument strings.
 * @return The index of the debug flag (-d), or -1 if not present.
 * @throws TooManyArgs If there are too many arguments.
 */
int debug_index(int argc, const char *argv[]);

std::ifstream parse_args(int argc, const char *argv[], int debug_index);

} // namespace emulator

} // namespace cli
