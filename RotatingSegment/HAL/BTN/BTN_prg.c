#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "BTN_pri.h"
#include "BTN_cfg.h"
#include "BTN_int.h"


void BTN_vInit(u8 A_u8BtnId){
	switch(A_u8BtnId){
		case BTN0_ID:	DIO_vSetPinDir(BTN0_PORT,BTN0_PIN,DIR_INPUT);	break;
		case BTN1_ID: 	DIO_vSetPinDir(BTN1_PORT,BTN1_PIN,DIR_INPUT);	break;
		case BTN2_ID:	DIO_vSetPinDir(BTN2_PORT,BTN2_PIN,DIR_INPUT);	break;
		case BTN3_ID:	DIO_vSetPinDir(BTN3_PORT,BTN3_PIN,DIR_INPUT);	break;
		case BTN4_ID:	DIO_vSetPinDir(BTN4_PORT,BTN4_PIN,DIR_INPUT);	break;
		case BTN5_ID:	DIO_vSetPinDir(BTN5_PORT,BTN5_PIN,DIR_INPUT);	break;
		case BTN6_ID:	DIO_vSetPinDir(BTN6_PORT,BTN6_PIN,DIR_INPUT);	break;
		case BTN7_ID:	DIO_vSetPinDir(BTN7_PORT,BTN7_PIN,DIR_INPUT);	break;
	}
#if (BTN_PULLING==INTERNAL_PULLUP)				// will be in code only if BTN_PULLING==INTERNAL_PULLIP
	switch(A_u8BtnId){
		case BTN0_ID:	DIO_vSetPinVal(BTN0_PORT,BTN0_PIN,VAL_HIGH);	break;
		case BTN1_ID: 	DIO_vSetPinVal(BTN1_PORT,BTN1_PIN,VAL_HIGH);	break;
		case BTN2_ID:	DIO_vSetPinVal(BTN2_PORT,BTN2_PIN,VAL_HIGH);	break;
		case BTN3_ID:	DIO_vSetPinVal(BTN3_PORT,BTN3_PIN,VAL_HIGH);	break;
		case BTN4_ID:	DIO_vSetPinVal(BTN4_PORT,BTN4_PIN,VAL_HIGH);	break;
		case BTN5_ID:	DIO_vSetPinVal(BTN5_PORT,BTN5_PIN,VAL_HIGH);	break;
		case BTN6_ID:	DIO_vSetPinVal(BTN6_PORT,BTN6_PIN,VAL_HIGH);	break;
		case BTN7_ID:	DIO_vSetPinVal(BTN7_PORT,BTN7_PIN,VAL_HIGH);	break;
#endif
	}
}

u8 BTN_u8GetState(u8 A_u8BtnId){
	u8 L_u8BtnState;
	u8 L_u8ResState;
	switch(A_u8BtnId){
		case BTN0_ID:	L_u8BtnState = DIO_u8GetPinVal(BTN0_PORT,BTN0_PIN);	break;
		case BTN1_ID:	L_u8BtnState = DIO_u8GetPinVal(BTN1_PORT,BTN1_PIN);	break;
		case BTN2_ID:	L_u8BtnState = DIO_u8GetPinVal(BTN2_PORT,BTN2_PIN); break;
		case BTN3_ID:	L_u8BtnState = DIO_u8GetPinVal(BTN3_PORT,BTN3_PIN);	break;
		case BTN4_ID:	L_u8BtnState = DIO_u8GetPinVal(BTN4_PORT,BTN4_PIN);	break;
		case BTN5_ID:	L_u8BtnState = DIO_u8GetPinVal(BTN5_PORT,BTN5_PIN);	break;
		case BTN6_ID:	L_u8BtnState = DIO_u8GetPinVal(BTN6_PORT,BTN6_PIN);	break;
		case BTN7_ID:	L_u8BtnState = DIO_u8GetPinVal(BTN7_PORT,BTN7_PIN);	break;
	}
	if(L_u8BtnState==0){	L_u8ResState=BTN_ON;	}
	else				{	L_u8ResState=BTN_OFF;	}
	return L_u8ResState;
}
