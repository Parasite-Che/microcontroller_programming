#include <stdlib.h>
#include "temperature_sensor.h"

int main(){
	temp_sense *ts = (temp_sense*)0x20000C00;
	int size = sizeof(*ts);
	int64_t *adress;
  adress = ts;
	fill_struct(ts);
	return 0;
}
