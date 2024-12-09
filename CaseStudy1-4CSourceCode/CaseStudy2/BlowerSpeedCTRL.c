/*
 * BlowerSpeedCTRL.c
 *
 *  Created on: 26 Sep 2024
 *      Author: thoma
 */

#include "BlowerSpeedCTRL.h"

void runBlowerSpeedCTRL(void){

	static uint8_t inBlowerSpeedCmd;
	static uint8_t inRightTempCmd;
	static uint8_t inLeftTempCmd;
	int32_t CANstatus;

	CANstatus = CAN_NODE_MO_GetStatus(&BCMNode_LMO_01_Config);
	if(CANstatus & XMC_CAN_MO_STATUS_RX_PENDING){
		CAN_NODE_MO_ClearStatus(&BCMNode_LMO_01_Config,XMC_CAN_MO_RESET_STATUS_RX_PENDING);
		CAN_NODE_MO_Receive(&BCMNode_LMO_01_Config);

		inBlowerSpeedCmd = BCMNode_LMO_01_Config.mo_ptr->can_data_byte[6] & 0x0f;
		inRightTempCmd = BCMNode_LMO_01_Config.mo_ptr->can_data_byte[5] & 0x3f;
		inLeftTempCmd = BCMNode_LMO_01_Config.mo_ptr->can_data_byte[4] & 0x3f;

		if((inBlowerSpeedCmd & 0x01) == 1){
			   DIGITAL_IO_SetOutputLow(&DIGITAL_IO_0);
			}
		else{
				DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_0);
			}
		if((inBlowerSpeedCmd & 0x02) == 2){
					   DIGITAL_IO_SetOutputLow(&DIGITAL_IO_1);
					}
				else{
						DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_1);
					}
		if((inBlowerSpeedCmd & 0x04) == 4){
					   DIGITAL_IO_SetOutputLow(&DIGITAL_IO_2);
					}
				else{
						DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_2);
					}
	}

	PWM_SetDutyCycle(&PWM_0, 1400*(inBlowerSpeedCmd));
}