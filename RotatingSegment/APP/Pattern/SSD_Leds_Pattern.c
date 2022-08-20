#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "../../HAL/SSD/SSD_pri.h"
#include "../../HAL/SSD/SSD_cfg.h"
#include "../../HAL/SSD/SSD_int.h"


void SSD_vDisplayPattern(u8 A_u8SsdId,u8 A_u8Val){
	static u8 L_u8SsdPatternArr[8]={
			0b00000001,
			0b00000010,
			0b00000100,
			0b00001000,
			0b00001000,
			0b00010000,
			0b00100000,
			0b00000001,
	};

	switch(A_u8SsdId)
	{
		case SSD0_ID:
		{
#if(SSD_COM==COM_CATHODE)
			DIO_vSetPortVal(SSD0_DATA_PORT,L_u8SsdPatternArr[A_u8Val]);
#else
			DIO_vSetPortVal(SSD0_DATA_PORT,~(L_u8SsdPatternArr[A_u8Val]));
#endif
		break;
		}

		case SSD1_ID:
		{
#if(SSD_COM==COM_CATHODE)
			DIO_vSetPortVal(SSD1_DATA_PORT,L_u8SsdPatternArr[A_u8Val]);
#else
			DIO_vSetPortVal(SSD1_DATA_PORT,~(L_u8SsdPatternArr[A_u8Val]));
#endif
		break;
		}
	}
}
