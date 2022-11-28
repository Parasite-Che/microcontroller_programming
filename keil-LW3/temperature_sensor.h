#ifndef __TEMP_SENSE__
#define __TEMP_SENSE__
#include <inttypes.h>


typedef struct temp_sense{
	int16_t temperature;
	int8_t high_border;
	int8_t low_border;
	int8_t configuration;
	int8_t reserved_FFh;
	int8_t reserved;
	int8_t reserved_10h;
	int8_t CRC;
} temp_sense;

void fill_struct(temp_sense* ts);
int8_t CRC8(temp_sense* ts);
void search_ROM();
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

#endif
