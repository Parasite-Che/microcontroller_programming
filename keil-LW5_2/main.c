#include <stdlib.h>
#include <inttypes.h>
#include <time.h>

uint16_t bitwise_CRC(uint16_t *message, size_t len);
uint16_t tabular_CRC(uint16_t *message, size_t len);
void GenerateCrc16Table(uint16_t poly,uint8_t **crcTable);

int main(){
	srand(time(NULL));
	uint16_t message[2] = {0x1234, 0x5678, 0x9ABC};
	uint16_t result1 = bitwise_CRC(message, 3);
	uint16_t result2 = tabular_CRC(message, 3);
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
	
	return ~crc;
}

uint16_t tabular_CRC(uint16_t *message, size_t len){
	uint16_t poly = 0x8005;
	uint8_t crcHi = 0xFF;
	uint8_t crcLo = 0xFF;
	uint8_t index;
	uint16_t crc;
	uint8_t **crcTable;
  crcTable = (uint8_t**)malloc(2 * sizeof(uint8_t*));
	for(size_t i = 0; i < 256; i++)
		crcTable[i] = (uint8_t*)malloc(256 * sizeof(uint8_t));
	
	GenerateCrc16Table(poly, **crcTable);
	
  size_t i, j;
	if(message == NULL){
		
	}
  else {
		for (i = 0; i < len; i++) {
			for(j = 0; j < 2; j++){
				index = /* crcLo ^ */(uint8_t)(message[i] >> (j*8));
				crcLo = crcHi ^ crcTable[0][index];
				crcHi = crcTable[1][index];
			}
    }
  }
	crc = (uint16_t) ((crcHi << 8) | (crcLo));
	return ~crc;
}


void GenerateCrc16Table(uint16_t poly, uint8_t **crcTable)  
{
	uint16_t crc = 0;
	
  size_t i, j;
  for(j = 0; j<256 ;j++)
  {
    crc = j;
    for (i = 0; i < 8; i++)             
    {
			if ((crc & 0x8000) != 0)
					crc = (uint8_t)((crc << 1) ^ poly);
      else
					crc <<= 1;                    
    }
		crcTable[0][j] = (uint8_t) (crc & 0xff); // low border
		crcTable[1][j] = (uint8_t) ((crc >> 8) & 0xff); // high border
	}
}
