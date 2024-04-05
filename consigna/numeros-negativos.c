/**
 * @file numeros-negativos.c
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

int main() {
    int i;

    for(i = 0; i < 5; i++) {
        printf("%d : %08X\n", i, i);
    }
    printf("\n");

    for(i = 0; i > -5; i--) {
        printf("%d : %08X\n", i, i);
    }
    printf("\n");

    return 0;
}