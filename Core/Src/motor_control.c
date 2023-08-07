/*
 * motor_control.c
 *
 *  Created on: 2023/08/01
 *      Author: taman
 */


#include "motor_control.h"
#include "config.h"
#include "main.h"
#include "tim.h"
#include <math.h>
#include <stdlib.h>

__IO int target_position = 0;
__IO int last_position = 0;


int get_dirction(){
	return (HAL_GPIO_ReadPin(DIR_GPIO_Port, DIR_Pin)==GPIO_PIN_SET)? 1:-1;
}


int get_position(){
	return htim2.Instance->CNT * get_dirction()-last_position;
}


void set_speed(int inv_speed){

	htim1.Instance->PSC = inv_speed;

	htim2.Instance->PSC = inv_speed*htim1.Instance->CCR1;
}

void set_direction(int dir){
	HAL_GPIO_WritePin(DIR_GPIO_Port, DIR_Pin, (dir==1)?GPIO_PIN_SET:GPIO_PIN_RESET);
}


// set power save pin
void activate(){
	HAL_GPIO_WritePin(POWER_SAVE_GPIO_Port, POWER_SAVE_Pin, GPIO_PIN_SET);
}
void diactivate(){
	HAL_GPIO_WritePin(POWER_SAVE_GPIO_Port, POWER_SAVE_Pin, GPIO_PIN_RESET);
}


void move_async(int target_position){
	int move = get_position()- target_position;
	if(move==0)return;

	activate();
	HAL_GPIO_WritePin(ENABLE_GPIO_Port, ENABLE_Pin, GPIO_PIN_SET);

	//if it is negative.
	if(move<0)HAL_GPIO_TogglePin(DIR_GPIO_Port, DIR_Pin);

	htim2.Instance->CNT = 0;
	htim2.Instance->CCR1 = abs(move);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);


}

void aysnc_callback(){
	stop();
}

void limit_switch_callback(){

}

void stop(){
	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
	HAL_TIM_OnePulse_Stop(&htim2, TIM_CHANNEL_1);

	last_position += get_position()*get_dirction();

	switch(mode){
	case FreePosition:
	{
		HAL_GPIO_WritePin(ENABLE_GPIO_Port,ENABLE_Pin, GPIO_PIN_RESET);
		break;
	}

	default:
		Error_Handler();
		break;
	}

}

