#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/LED/LED_int.h"
#include "../HAL/BTN/BTN_int.h"
#include "../HAL/SSD/SSD_int.h"
#include "../HAL/SWITCH/SWITCH_int.h"

#include "../APP/Pattern/Pattern_int.h"

#include <util/delay.h>

u8 stopBit=0;

int main (){

	SWITCH_vInitAll();
	SSD_vInitBoth();

	int i,iterate;

	while(1){

		iterate=1;
		if(SWITCH_u8GetState(SWITCH2_ID)==0 && SWITCH_u8GetState(SWITCH1_ID)==1){	// clockWise
			while(1){
				for(i=stopBit;i<=7;i++){

					if(i<4){	SSD_vTurnOn(SSD0_ID);	SSD_vDisplayPattern(SSD0_ID,i);	_delay_ms(500);	SSD_vTurnOff(SSD0_ID);	}
					else   {	SSD_vTurnOn(SSD1_ID);	SSD_vDisplayPattern(SSD1_ID,i);	_delay_ms(500);	SSD_vTurnOff(SSD1_ID);	}

					if(SWITCH_u8GetState(SWITCH2_ID)==1 && SWITCH_u8GetState(SWITCH1_ID)==0){ stopBit=i; iterate=0; break; }
				}
				if(iterate!=0) stopBit=0;
				else 			break;
			}
		}

		iterate=1;

		if(SWITCH_u8GetState(SWITCH2_ID)==1 && SWITCH_u8GetState(SWITCH1_ID)==0){		// antiClockWise
			while(1){
				for(i=stopBit;i>=0;i--){

					if(i>3){	SSD_vTurnOn(SSD1_ID);	SSD_vDisplayPattern(SSD1_ID,i);	_delay_ms(500);	SSD_vTurnOff(SSD1_ID);	}
					else   {	SSD_vTurnOn(SSD0_ID);	SSD_vDisplayPattern(SSD0_ID,i);	_delay_ms(500);	SSD_vTurnOff(SSD0_ID);	}

					if (SWITCH_u8GetState(SWITCH2_ID)==0 && SWITCH_u8GetState(SWITCH1_ID)==1){ stopBit=i;  iterate=0;  break; }
				}
				if(iterate!=0) stopBit=7;
				else 			break;
			}
		}

	}

	return 0;
}
