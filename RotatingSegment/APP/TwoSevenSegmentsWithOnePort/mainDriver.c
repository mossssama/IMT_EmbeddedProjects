/*
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/LED/LED_int.h"
#include "../HAL/BTN/BTN_int.h"
#include "../HAL/SSD/SSD_int.h"

#include <util/delay.h>

int main (){

	int leastSeg,mostSeg,i;

	SSD_vInitBoth();

	while(1){
		leastSeg=0;		mostSeg=0;

		for(i=0;i<=99;i++){
			if(leastSeg>9){ leastSeg=0; mostSeg++; }

			SSD_vTurnOn(SSD0_ID);
			SSD_vDisplayNum(SSD0_ID,leastSeg);
			leastSeg++;	 _delay_ms(10);
			SSD_vTurnOff(SSD0_ID);

			SSD_vTurnOn(SSD1_ID);
			SSD_vDisplayNum(SSD1_ID,mostSeg);
			_delay_ms(10);
			SSD_vTurnOff(SSD1_ID);
		}

	}
	return 0;
}
*/
