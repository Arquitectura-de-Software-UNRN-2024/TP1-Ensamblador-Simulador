#ifndef INT12
#define INT12
#include <stdint.h>

int16_t from_int12(uint16_t i12);
void clamp(int16_t *target, const int16_t min, const int16_t max);

#endif  // !INT12
