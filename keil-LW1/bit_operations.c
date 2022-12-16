#include "bit_operations.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
		
int bit_to_one(int num, int mask, int size){
	if(size == 1){
		char number = (char)num;
		number |= (char)mask;
		return number;
	}
	else if(size == 2){
		short number = (short)num;
		number |= (short)mask;
		return number;
	}
	else{
		num |= mask;
		return num;
	}
}

int bit_to_zero(int num, int mask, int size){
	if(size == 1){
		char number = (char)num;
		number &= bit_inversion(mask, 0xFF, size);
		return number;
	}
	else if(size == 2){
		short number = (short)num;
		number &= bit_inversion(mask, 0xFFFF, size);
		return number;
	}
	else{
		num &= bit_inversion(mask, (int)0xFFFFFFFF, size);
		return num;
	}
}

int bit_inversion(int num, int mask, int size){
	if(size == 1){
		char number = (char)num;
		number ^= (char)mask;
		return number;
	}
	else if(size == 2){
		short number = (short)num;
		number ^= (short)mask;
		return number;
	}
	else{
		num ^= mask;
		return num;
	}
}

int logical_move_r(int num, unsigned int count, int size){
	if(size == 1){
		char number = (char)num;
		number >>= count;
		return number;
	}
	else if(size == 2){
		short number = (short)num;
		number >>= count;
		return number;
	}
	else{
		num >>= count;
		return num;
	}
}

int logical_move_l(int num, unsigned int count, int size){
	if(size == 1){
		char number = (char)num;
		number <<= count;
		return number;
	}
	else if(size == 2){
		short number = (short)num;
		number <<= count;
		return number;
	}
	else{
		num <<= count;
		return num;
	}
}

int cyclic_move_r(int num , unsigned int count, int size){
	if(size == 1){
		char number = (char)num;
		number = (number >> count) | (char)(number << ((size * 8) - (char)count));
		return number;
	}
	else if(size == 2){
		short number = (short)num;
		number = (number >> count) | (short)(number << ((size * 8) - (short)count));
		return number;
	}
	else{
		num = (num >> count) | (num << ((size * 8) - (int)count));
		return num;
	}
}

int cyclic_move_l(int num, unsigned int count, int size){
	if(size == 1){
		char number = (char)num;
		number = (char)(number << count) | (number >> ((size * 8) - (char)count));
		return number;
	}
	else if(size == 2){
		short number = (short)num;
		number = (short)(number << count) | (number >> ((size * 8) - (short)count));
		return number;
	}
	else{
		num = (num << count) | (num >> ((size * 8) - (int)count));
		return num;
	}
}
