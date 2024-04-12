#pragma once
#include <cstdint>
#include <fstream>

class Emulator {
  public:
    Emulator();
    Emulator(Emulator &&) = default;
    Emulator(const Emulator &) = default;
    Emulator &operator=(Emulator &&) = default;
    Emulator &operator=(const Emulator &) = default;
    virtual ~Emulator() = default;

    virtual void run(std::ifstream);

  protected:
    int32_t accumulator;

    void exec(uint32_t);

  private:
    void add(int32_t);
    void load(int32_t);
    virtual void print() const;
};

class DebugEmulator : public Emulator {
  public:
    using Emulator::Emulator;
    virtual ~DebugEmulator() = default;
    virtual void run(std::ifstream) override;

  private:
    virtual void print() const override;
};
