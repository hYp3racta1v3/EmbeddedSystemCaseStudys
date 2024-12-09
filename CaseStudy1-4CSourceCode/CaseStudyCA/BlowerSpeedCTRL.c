/*
 * BlowerSpeedCTRL.c
 *
 *  Created on: 26 Sep 2024
 *      Author:
 */

#include "BlowerSpeedCTRL.h"

void runBlowerSpeedCTRL(void *arg){
	static uint8_t inBlowerSpeedCmd;
	static uint8_t inRightTempCmd;
	static uint8_t inLeftTempCmd;
	int32_t CANstatus;

	while(1){
	CANstatus = CAN_NODE_MO_GetStatus(&BCMNode_LMO_01_Config);
	if(CANstatus & XMC_CAN_MO_STATUS_RX_PENDING){
		CAN_NODE_MO_ClearStatus(&BCMNode_LMO_01_Config,XMC_CAN_MO_RESET_STATUS_RX_PENDING);
		CAN_NODE_MO_Receive(&BCMNode_LMO_01_Config);

		inBlowerSpeedCmd = BCMNode_LMO_01_Config.mo_ptr->can_data_byte[6] & 0x0f;
		inRightTempCmd = BCMNode_LMO_01_Config.mo_ptr->can_data_byte[5] & 0x3f;
		inLeftTempCmd = BCMNode_LMO_01_Config.mo_ptr->can_data_byte[4] & 0x3f;

	}
	}
}
