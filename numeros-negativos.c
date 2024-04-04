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