#include "../include/int24.hpp"

int32_t from_int24(uint32_t i24_to_interpret){
	i24_to_interpret &= 0x00FFFFFF;
	i24_to_interpret -= ((i24_to_interpret & INT24_MIN) << 1);
	return i24_to_interpret;
}

uint32_t to_int24(int32_t number_to_format){
	number_to_format &= 0x00FFFFFF;
	return number_to_format;
}
