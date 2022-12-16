#include "bit_operations.h"
#include <math.h>
#include <stdio.h>

int main() {
  unsigned char num = 0xAA;
	int mask = ~(1 << 8);
	unsigned int count = 3;
	int bto = bit_to_one(num, mask, sizeof(num));
	int btz = bit_to_zero(num, mask, sizeof(num));
	int bi = bit_inversion(num, mask, sizeof(num));
	int lmr = logical_move_r(num, count, sizeof(num));
	int lml = logical_move_l(num, count, sizeof(num));
	int cmr = cyclic_move_r(num, count, sizeof(num));
	int cml = cyclic_move_l(num, count, sizeof(num));
	return 0;
}
