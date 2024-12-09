/*
 * BlowerTest.c
 *
 *  Created on: 26 Sep 2024
 *      Author: thoma
 */

#include "BlowerTest.h"
#include "Dave.h"

void runBlowerTest(void *arg){
	static uint8_t SimBlowerSpeedCmd;
	static uint8_t SimRightTempCmd;
	static uint8_t SimLeftTempCmd;

	uint8_t can_data_arr[8] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
	int32_t testStatus;

while(1){
	can_data_arr[4] = SimLeftTempCmd;
	can_data_arr[5] = SimRightTempCmd;
	can_data_arr[6] = SimBlowerSpeedCmd;


	testStatus = (CAN_NODE_STATUS_t)CAN_NODE_MO_UpdateData(&TestNode_LMO_01_Config,can_data_arr);
	if (testStatus == CAN_NODE_STATUS_SUCCESS){
	      CAN_NODE_MO_Transmit(&TestNode_LMO_01_Config);
	}
}
}
