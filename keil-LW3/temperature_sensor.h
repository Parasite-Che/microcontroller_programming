#ifndef __TEMP_SENSE__
#define __TEMP_SENSE__

#define SENSE_ADR 0x20000C00

#define search_ROM() = 0xF0
#define read_ROM() = 0x33
#define match_ROM() = 0x55
#define skip_ROM() = 0xCC
#define alarm_search() = 0xEC
#define convert_T() = 0x44
#define write_scratchpad() = 0x4E
#define read_scratchpad() = 0xBE
#define copy_scratchpad() = 0x48
#define recall_E_cube() = 0xB8
#define read_power_supply() = 0xB4

#define ts (*(( temp_sense*) SENSE_ADR))

/*
#define com(x) if (x == 0xF0) search_ROM()\
	else if (x == 0xF0) \
		read_ROM()
*/		

#include <inttypes.h>


typedef struct temp_sense{
	int16_t temperature;
	int8_t high_border;
	int8_t low_border;
	int8_t configuration;
	int8_t reserved_FFh;
	int8_t reserved;
	int8_t reserved_10h;
	uint8_t CRC;
} temp_sense;

void fill_struct(temp_sense temps);
uint8_t CRC8(temp_sense temps);

#endif
