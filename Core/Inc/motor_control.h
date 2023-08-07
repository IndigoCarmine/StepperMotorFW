/*
 * motor_control.h
 *
 *  Created on: 2023/08/01
 *      Author: taman
 */

#ifndef INC_MOTOR_CONTROL_H_
#define INC_MOTOR_CONTROL_H_



void set_speed(int inv_speed);



// set power save pin
void activate();
void diactivate();


void move_async(int target_position);

void aysnc_callback();

void limit_switch_callback();


void stop();



#endif /* INC_MOTOR_CONTROL_H_ */
