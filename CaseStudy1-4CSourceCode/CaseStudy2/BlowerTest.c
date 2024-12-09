/*
 * BlowerTest.c
 *
 *  Created on: 26 Sep 2024
 *      Author: thoma
 */

#include "BlowerTest.h"
#include "Dave.h"

#ifdef TESTMODE
void runBlowerTest(void){
	static uint8_t SimBlowerSpeedCmd;
	static uint8_t SimRightTempCmd;
	static uint8_t SimLeftTempCmd;

	uint8_t can_data_arr[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
	int32_t testStatus;


	can_data_arr[4] = SimLeftTempCmd;
	can_data_arr[5] = SimRightTempCmd;
	can_data_arr[6] = SimBlowerSpeedCmd;


	testStatus = (CAN_NODE_STATUS_t)CAN_NODE_MO_UpdateData(&TestNode_LMO_01_Config,can_data_arr);
	if (testStatus == CAN_NODE_STATUS_SUCCESS){
	      CAN_NODE_MO_Transmit(&TestNode_LMO_01_Config);
	}
}

#endif
