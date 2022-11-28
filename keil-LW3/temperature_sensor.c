#include <time.h>
#include "temperature_sensor.h"
void fill_struct(temp_sense* ts){
	srand(time(NULL));
	if(rand() % 2 == 1){
		ts->temperature = (int16_t)((rand() % 0xFFFF) | 0xF800);
	}
	else{
		ts->temperature = (int16_t)((rand() % 0xFFFF) & 0x07FF);
	}
	ts->high_border =  (int8_t)rand() % 0xFF;
	ts->low_border =  (int8_t)rand() % 0xFF;
	ts->configuration = (int8_t)((rand() % 4) << 5) + 0x1F;
	ts->reserved_FFh = (int8_t)rand() % 0xFF;
	ts->reserved_10h = (int8_t)rand() % 0xFF;
	ts->reserved = (int8_t)rand() % 0xFF;
	ts->CRC = CRC8(ts);
}

int8_t CRC8(temp_sense* ts){
	int64_t *adress;
  adress = ts;
	int8_t crc = 0;
	crc += *adress & 0xFFFF;
	for(int i = 2; i < sizeof(*adress) - 1; i++){
		crc += (*adress >> (i * 8)) & 0xFF;
	}
	return crc;
}

void search_ROM(){
	
}

void read_ROM();
void match_ROM();
void skip_ROM();
void alarm_search();
void convert_T();
void write_scratchpad();
void read_scratchpad();
void copy_scratchpad();
void recall_E_cube();
void read_power_supply();
