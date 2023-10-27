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

__IO int test_dir = 1;
__IO MotorMode motorMode = Stop;

int get_dirction(){
	return (HAL_GPIO_ReadPin(DIR_GPIO_Port, DIR_Pin)==GPIO_PIN_SET)? 1:-1;
}


int get_position(){
	return htim2.Instance->CNT * get_dirction() + last_position;
}


void set_speed(int inv_speed){

	htim1.Instance->PSC = inv_speed -1;
}

void set_direction(int dir){
	test_dir = dir;
	HAL_GPIO_WritePin(DIR_GPIO_Port, DIR_Pin, (dir==1)?GPIO_PIN_SET:GPIO_PIN_RESET);
}


void init(){
	HAL_TIM_Base_Start_IT(&htim2);
}
void deinit(){
	HAL_TIM_Base_Stop_IT(&htim2);
}


// set power save pin
void activate(){
	HAL_GPIO_WritePin(POWER_SAVE_GPIO_Port, POWER_SAVE_Pin, GPIO_PIN_SET);
}
void diactivate(){
	HAL_GPIO_WritePin(POWER_SAVE_GPIO_Port, POWER_SAVE_Pin, GPIO_PIN_RESET);
}


void move_async(int target_position){
	int move =  target_position - get_position();
	if(move==0)return;
	init();
	activate();
	HAL_GPIO_WritePin(ENABLE_GPIO_Port, ENABLE_Pin, GPIO_PIN_SET);

	//if it is negative.
	set_direction((move>0)?1:-1);

	htim2.Instance->CNT = 0;
	htim2.Instance->ARR = abs(move);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);


}

void move_sync(int speed){
	if(speed == 0){
		stop();
		return;
	}
	set_speed(abs(1000000/speed));
	set_direction(speed>0?1:-1);

	activate();
	HAL_TIM_Base_Stop_IT(&htim2);
	HAL_GPIO_WritePin(ENABLE_GPIO_Port, ENABLE_Pin, GPIO_PIN_SET);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
}

void aysnc_callback(){
	if(motorMode == SimpleMove)return;
	stop();
}

void limit_switch_callback(){
	stop();
}

void stop(){
	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);

	last_position += get_position();
	htim2.Instance->CNT = 0;
	switch(motorMode){
	case SimpleMove:
	{
		break;
	}
	case FreePosition:
	{
		HAL_GPIO_WritePin(ENABLE_GPIO_Port,ENABLE_Pin, GPIO_PIN_RESET);
		break;
	}

	case Position:
	{
		HAL_GPIO_WritePin(ENABLE_GPIO_Port,ENABLE_Pin, GPIO_PIN_RESET);
		break;
	}

		default:
		Error_Handler();
		break;
	}

}

