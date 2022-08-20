/*
 * SWITCH_int.h
 *
 *  Created on: 19 Aug 2022
 *      Author: Mohamed Osama
 */


#define SWITCH0_ID 0
#define SWITCH1_ID 1
#define SWITCH2_ID 2


#define SWITCH_ON  1
#define SWITCH_OFF 0


void SWITCH_vInit(u8 A_u8SwitchId);

void SWITCH_vInitAll();

u8 SWITCH_u8GetState(u8 A_u8SwitchId);


