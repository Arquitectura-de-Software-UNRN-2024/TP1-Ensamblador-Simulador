#include "../include/emulator.hpp"
#include "../include/Tokens.hpp"
#include "../include/bigendian.hpp"
#include "../include/int24.hpp"
#include <cstdint>
#include <format>
#include <iostream>

Emulator::Emulator() : accumulator(0) {}

DebugEmulator::DebugEmulator()
    : accumulator_box(3, 2, 0, 1, "─Acumlator", {}),
      next_operation(3, 7, 0, 3, "─Next", {}) {}

void Emulator::add(int32_t value) { this->accumulator += value; }

void Emulator::load(int32_t value) { this->accumulator = value; }

void Emulator::print() const { std::cout << this->accumulator << std::endl; }

void DebugEmulator::print() const { std::cout << this->accumulator; }

void Emulator::exec(uint32_t operation) {
    switch (operation & 0xFF000000) {
        case static_cast<uint32_t>(OperationValue::ADD):
            this->add(from_int24(operation & 0x00FFFFFF));
            break;
        case static_cast<uint32_t>(OperationValue::LOAD):
            this->load(from_int24(operation & 0x00FFFFFF));
            break;
        case static_cast<uint32_t>(OperationValue::PRINT):
            this->print();
            break;
        default:
            InvalidOperation e;
            throw e;
    }
}

void Emulator::run(std::ifstream file) {
    char buffer[4];
    file.read(buffer, 4);
    while (!file.eof()) {
        uint32_t operation = from_big_endian(buffer);
        this->exec(operation);
        file.read(buffer, 4);
    }
}

void DebugEmulator::run(std::ifstream file) {
    char buffer[4];
    if (!file.eof()) {
        file.read(buffer, 4);
        std::cout << "\r" << MOVE_CURSOR << 27 << FORWARD;
    }
    while (!file.eof()) {
        uint32_t operation = from_big_endian(buffer);
        this->accumulator_box.update_content(
            {std::format("{:>13}", this->accumulator)});
        this->next_operation.update_content(operation);
        this->accumulator_box.draw();
        this->next_operation.draw();
        getchar();
        this->exec(operation);
        std::cout << "\r" << MOVE_CURSOR << 10 << FORWARD << "│ "
                  << this->next_operation.get_content()[2] << " │";
        file.read(buffer, 4);
    }
}
