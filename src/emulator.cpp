#include "../include/emulator.hpp"
#include "../include/Tokens.hpp"
#include "../include/int24.hpp"
#include "../include/box.hpp"
#include <cstdint>
#include <iostream>

Emulator::Emulator() : accumulator(0) {}

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
    while (!file.eof()) {
        file.read(buffer, 4);
		  uint32_t operation = from_big_endian(buffer);
		  this->exec(operation);
    }
}

void DebugEmulator::run(std::ifstream file) {
    char buffer[4];
    while (!file.eof()) {
        file.read(buffer, 4);
		  uint32_t operation = from_big_endian(buffer);
		  this->exec(operation);
		  std::cout << "\r"; 
	 }
}
