#include <stdlib.h>
#include "temperature_sensor.h"



int main(){
	//ts = (temp_sense*)malloc(sizeof(temp_sense));
	//temp_sense *ts2 = (temp_sense*)malloc(sizeof(temp_sense));
	//ts = *ts2;
	int size = sizeof(ts);
	int64_t *adress;
  adress = &ts;
	fill_struct(ts);
	return 0;
}
