#include <stdlib.h>
#include <inttypes.h>
#include <time.h>

uint16_t bitwise_CRC(uint16_t *message, size_t len);
uint16_t tabular_CRC(uint16_t *message, size_t len);

int main(){
	srand(time(NULL));
	uint16_t message = (uint16_t)rand();
	uint16_t result = bitwise_CRC(message, 1);
	return 0;
}

uint16_t bitwise_CRC(uint16_t *message, size_t len){
	uint16_t poly = 0x8005;
	uint16_t crc = 0xFFFF;
	
  size_t i, j;
  for (i = 0; i < len; i++) {
    crc ^= message[i];
    for (j = 0; j < 16; j++) {
      if ((crc & 0x8000) != 0)
					crc = (uint8_t)((crc << 1) ^ poly);
      else
					crc <<= 1;
    }
  }
	
	return (crc ^ (uint16_t)0xFFFF);
} 

uint16_t tabular_CRC(uint16_t *message, size_t len){
	uint16_t poly = 0x8005;
	uint16_t crc = 0xFFFF;
	
  size_t i, j;
  for (i = 0; i < len; i++) {
    crc ^= message[i];
    for (j = 0; j < 16; j++) {
      if ((crc & 0x8000) != 0)
					crc = (uint8_t)((crc << 1) ^ poly);
      else
					crc <<= 1;
    }
  }
	
	return (crc ^ (uint16_t)0xFFFF);
} 
