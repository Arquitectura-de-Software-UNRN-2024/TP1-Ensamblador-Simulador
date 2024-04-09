#include <fstream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define BOLDWHITE "\033[1m\033[37m"

namespace cli {

extern const char *help_str;

bool needs_help(int argc, const char *argv[]);

struct Files {
    std::ifstream ifile;
    std::ofstream ofile;
};

struct Files parse_args(int argc, const char *argv[]);

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

} // namespace cli
