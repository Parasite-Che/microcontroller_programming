#ifndef __BIT_OPERATION__
#define __BIT_OPERATION__

int bit_to_one(int num, int mask, int size);
int bit_to_zero(int num, int mask, int size);
int bit_inversion(int num, int mask, int size);
int logical_move_r(int num, unsigned int count, int size);
int logical_move_l(int num, unsigned int count, int size);
int cyclic_move_r(int num, unsigned int count, int size);
int cyclic_move_l(int num, unsigned int count, int size);

#endif
