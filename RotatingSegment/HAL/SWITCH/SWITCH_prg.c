#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "SWITCH_pri.h"
#include "SWITCH_cfg.h"
#include "SWITCH_int.h"


void SWITCH_vInit(u8 A_u8SwitchId){
	switch(A_u8SwitchId){
			case SWITCH0_ID:	DIO_vSetPinDir(SWITCH0_PORT,SWITCH0_PIN,DIR_INPUT);	break;
			case SWITCH1_ID: 	DIO_vSetPinDir(SWITCH1_PORT,SWITCH1_PIN,DIR_INPUT);	break;
			case SWITCH2_ID:	DIO_vSetPinDir(SWITCH2_PORT,SWITCH2_PIN,DIR_INPUT);	break;
	}
#if (BTN_PULLING==INTERNAL_PULLUP)				// will be in code only if BTN_PULLING==INTERNAL_PULLIP
		switch(A_u8SwitchId){
			case SWITCH0_ID:	DIO_vSetPinVal(SWITCH0_PORT,SWITCH0_PIN,VAL_HIGH);	break;
			case SWITCH1_ID: 	DIO_vSetPinVal(SWITCH1_PORT,SWITCH1_PIN,VAL_HIGH);	break;
			case SWITCH2_ID:	DIO_vSetPinVal(SWITCH2_PORT,SWITCH2_PIN,VAL_HIGH);	break;
#endif
		}
}

void SWITCH_vInitAll(){
	DIO_vSetPinDir(SWITCH0_PORT,SWITCH0_PIN,DIR_INPUT);
	DIO_vSetPinDir(SWITCH1_PORT,SWITCH1_PIN,DIR_INPUT);
	DIO_vSetPinDir(SWITCH2_PORT,SWITCH2_PIN,DIR_INPUT);
#if (BTN_PULLING==INTERNAL_PULLUP)				// will be in code only if BTN_PULLING==INTERNAL_PULLIP
	DIO_vSetPinVal(SWITCH0_PORT,SWITCH0_PIN,VAL_HIGH);
	DIO_vSetPinVal(SWITCH1_PORT,SWITCH1_PIN,VAL_HIGH);
	DIO_vSetPinVal(SWITCH2_PORT,SWITCH2_PIN,VAL_HIGH);
#endif
}

u8 SWITCH_u8GetState(u8 A_u8SwitchId){
	u8 L_u8SwitchState;
	u8 L_u8ResState;
		switch(A_u8SwitchId){
			case SWITCH0_ID:	L_u8SwitchState = DIO_u8GetPinVal(SWITCH0_PORT,SWITCH0_PIN);	break;
			case SWITCH1_ID:	L_u8SwitchState = DIO_u8GetPinVal(SWITCH1_PORT,SWITCH1_PIN);	break;
			case SWITCH2_ID:	L_u8SwitchState = DIO_u8GetPinVal(SWITCH2_PORT,SWITCH2_PIN);	break;
		}
		if(L_u8SwitchState==0){	L_u8ResState=SWITCH_ON;	}
		else				  {	L_u8ResState=SWITCH_OFF;}
	return L_u8ResState;
}
