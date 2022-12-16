#include <time.h>
#include "temperature_sensor.h"

void fill_struct(temp_sense temps){
	srand(time(NULL));
	if((rand() % 2) == 1){
		ts.temperature = (int16_t)((rand() % 0xFFFF) | 0xF800);
	}
	else{
		ts.temperature = (int16_t)((rand() % 0xFFFF) & 0x07FF);
	}
	ts.high_border =  (int8_t)rand() % 0xFF;
	ts.low_border =  (int8_t)rand() % 0xFF;
	ts.configuration = (int8_t)((rand() % 4) << 5) | 0x1F;
	ts.reserved_FFh = (int8_t)rand() % 0xFF;
	ts.reserved_10h = (int8_t)rand() % 0xFF;
	ts.reserved = (int8_t)rand() % 0xFF;
	ts.CRC = (int8_t)rand() % 0xFF;
}

/*
uint8_t CRC8(temp_sense* ts){
	int64_t *adress;
  adress = ts;
	uint8_t crc = 0xff;
  size_t i, j;
  for (i = 0; i < 8; i++) {
    crc ^= (*adress >> (i * 8)) & 0xff;
    for (j = 0; j < 8; j++) {
      if ((crc & 0x80) != 0)
					crc = (uint8_t)((crc << 1) ^ 0x31);
      else
					crc <<= 1;
    }
  }
	return crc;
}
*/