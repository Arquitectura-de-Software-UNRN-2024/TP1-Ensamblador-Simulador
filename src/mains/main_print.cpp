#include "../../include/box.hpp"
#include <format>
#include <iostream>

int main() {
    for (int i = 0; i < 8; i++) {
        std::cout << "\n";
    }

    uint32_t ops[10] = {
        0x0200000C, 0x0100002C, 0x0300000C, 0x03000104, 0x01000B12,
        0x02000001, 0x02001000, 0x010001D2, 0x02000CDB, 0x0301BF23,
    };

    Box acumulator(15, 2, 0, 1, "─Acumlator", {});
    OpBox next_operation(15, 7, 0, 3, "─Next", {});

    for (int i = 10; i < 20; i++) {
        acumulator.update_content({std::format("{}", i)});
        next_operation.update_content(ops[i - 10]);
        acumulator.draw();
        next_operation.draw();
        getchar();
    }

    return 0;
}
