/*
 * config.h
 *
 *  Created on: 2023/08/01
 *      Author: taman
 */

#ifndef INC_CONFIG_H_
#define INC_CONFIG_H_

#include "stdint.h"

enum MotorMode{
	Speed,
	Position,
	FreePosition
};




inline const int BASE_ID_High = 0x0;
inline const int BASE_ID = BASE_ID_High<<2;

inline const uint8_t mode = FreePosition;


#endif /* INC_CONFIG_H_ */
