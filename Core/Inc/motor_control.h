/*
 * motor_control.h
 *
 *  Created on: 2023/08/01
 *      Author: taman
 */

#ifndef INC_MOTOR_CONTROL_H_
#define INC_MOTOR_CONTROL_H_

#include "main.h"

typedef enum _MotorMode{
	Stop,
	SimpleMove,
	Position,
	FreePosition
}MotorMode;



extern __IO MotorMode motorMode;


void set_speed(int inv_speed);


//Init timers
void init();


// set power save pin
void activate();
void diactivate();


void move_async(int target_position);
void move_sync(int speed);

void aysnc_callback();

void limit_switch_callback();


void stop();



#endif /* INC_MOTOR_CONTROL_H_ */
