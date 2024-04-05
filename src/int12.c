#include "int12.h"
#include <stdint.h>

int16_t from_int12(uint16_t i12){
	i12 &= 0x0FFF;
	i12 -= ((i12 & 0x0800) << 1);
	return i12;
}

void clamp(int16_t *target, const int16_t min, const int16_t max){
	*target = *target>min? *target:min;
	*target = *target<max? *target:max;
}

