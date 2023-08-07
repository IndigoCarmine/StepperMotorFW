/*
 * user_it.c
 *
 *  Created on: 2023/08/01
 *      Author: IndigoCarmine
 */

#include "can.h"


void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan){
    CAN_RxHeaderTypeDef RxHeader;
    uint8_t RxData[8];
    if (HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, RxData) == HAL_OK)
    {


    }
}
