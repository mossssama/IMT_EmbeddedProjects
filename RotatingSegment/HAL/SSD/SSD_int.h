/*
 * SVN_int.h
 *
 *  Created on: 17 Aug 2022
 *      Author: Mohamed Osama
 */

#ifndef HAL_SSD_SSD_INT_H_
#define HAL_SSD_SSD_INT_H_

#define SSD0_ID 0
#define SSD1_ID 1



void SSD_vInit(u8 A_u8SsdId);

void SSD_vTurnOn(u8 A_u8SsdId);

void SSD_vTurnOff(u8 A_u8SsdId);

void SSD_vDisplayNum(u8 A_u8SsdId,u8 A_u8Val);

void SSD_vInitBoth();

#endif /* HAL_SSD_SSD_INT_H_ */




//what is the features
