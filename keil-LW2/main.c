#include <stdint.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 2
#define COLUMN 10

int8_t arithmetic_mean(int8_t num, ...);
int8_t arithmetic_mean_pointer(int8_t *nums);
int8_t **two_mas(void);
int8_t **change(int8_t **m, unsigned char num_of_change, int8_t num);
int8_t **change2(int8_t **m, unsigned char num_of_change, int8_t num);
int8_t **initialize_double_mas(void);
float func(float x, float y, float z);
float func_pow(float (*f)(float, float, float), float x, float y, float z, int p);

int main(){
	srand(time(NULL));
	int8_t mas[COLUMN];
	int8_t **mases = initialize_double_mas();
	mases = two_mas();
	int8_t **c_mases1 = change(mases, 11, 0x0F);
	int8_t **c_mases2 = change2(mases, 5, 0x0F);
	for (int8_t i = 0; i < COLUMN; i++){
		mas[i] = (unsigned char)rand() % 127;
		//mas[i] = 20;
	}
	
	float fp = func_pow(func, 1, 1, 1, 1);
	int8_t am = arithmetic_mean(COLUMN, mas[0], mas[1], mas[2], mas[3], mas[4], mas[5], mas[6], mas[7], mas[8], mas[9]);
	int8_t amp = arithmetic_mean_pointer(mas);
	
	return 0;
}

int8_t arithmetic_mean(int8_t num, ...){
	int32_t sum = 0;
	int8_t count = 0;
	va_list vl;
	va_start(vl, num);
	//int *p = &first;
	while (num--) {
    sum += va_arg(vl, int);
    //p++;
		count++;
  }
	va_end(vl);
	return (int8_t)(sum / count);
}

int8_t arithmetic_mean_pointer(int8_t *nums){
	int32_t sum = 0;
	int8_t size_mas = 10 /*sizeof(*nums)/ sizeof(int8_t)*/;
	for(int i = 0; i < size_mas; i++){
		sum += nums[i];
	}
	return (int8_t)(sum / size_mas);
}

float func_pow(float (*f)(float, float, float), float x, float y, float z, int p){
	return powf((*f)(x, y, z), (float)p);
}

float func(float x, float y, float z){
	float d = (float)(powf(fabsf(x - 1.f), (1 / 2.f)) - powf(y, 1/4.f));
	d /= (1.f + (powf(x, 2) / 2.f)) + (powf(z, 2.f) / 2.f);
	d += (x * y);
	
	return d;
}


int8_t **two_mas(){
  int8_t **mass = (int8_t**)malloc(ROWS * sizeof(int8_t*));
	for(int i = 0; i < ROWS; i++){
		mass[i] = (int8_t*)malloc(COLUMN * sizeof(int8_t));
	}	
	for (int8_t i = 0; i < ROWS; i++){
		for (int8_t j = 0; j < COLUMN; j++){
			mass[i][j] = rand() % 255;
		}
	}
	return mass;
}

int8_t **change(int8_t **m, unsigned char num_of_change, int8_t num){
	int8_t **mass = initialize_double_mas();
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 10; j++){
			mass[i][j] = m[i][j];
		}
	}
	int8_t num_mass = rand() % 2;
	if(num_of_change < 10/*(int8_t)(sizeof(mass[num_mass]) / sizeof(int8_t))*/){
		mass[num_mass][num_of_change] = num;
	}
	else{
		mass[num_mass ^ 1][rand() % 10] = (int8_t)0xFF;
	}
	return mass;
}

int8_t **change2(int8_t **m, unsigned char num_of_change, int8_t num){
	int8_t **mass = initialize_double_mas();
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 10; j++){
			mass[i][j] = m[i][j];
		}
	}
	int8_t num_mass = rand() % 2;
	if(num_of_change + 1 < 10/*(int8_t)(sizeof(mass[num_mass]) / sizeof(int8_t))*/){
		*(*(mass + num_mass) + num_of_change) = num;
	}
	else{
		*(*(mass + (num_mass ^ 1)) + (rand() % 10)) = (int8_t)0xFF;
	}
	return mass;
}

int8_t **initialize_double_mas(){
	int8_t **mases = NULL;
	
	mases = (int8_t**)malloc(2 * sizeof(int8_t*));
	for (int i = 0; i < 2; i++){
		mases[i] = (int8_t*)malloc(10 * sizeof(int8_t));
	}
	return mases;
}
