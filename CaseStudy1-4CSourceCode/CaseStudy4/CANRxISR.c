/* BlowerSpeedCTRL.c
 *
 *  Created on: 26 Sep 2024
 *      Author: thoma
 */

#include "CANRxISR.h"
#include "Dave.h"

void CANRxISR(void *arg){
	static uint8_t CANRxBlowerSpeed;
	static uint8_t CANRxLeftTempCmd;
	static uint8_t CANRxRightTempCmd;
	extern osMessageQId message_q_id;
	int32_t CANstatus;


	CANstatus = CAN_NODE_MO_GetStatus(&BCMNode_LMO_01_Config);
	if(CANstatus & XMC_CAN_MO_STATUS_RX_PENDING){
		CAN_NODE_MO_ClearStatus(&BCMNode_LMO_01_Config,XMC_CAN_MO_RESET_STATUS_RX_PENDING);
		CAN_NODE_MO_Receive(&BCMNode_LMO_01_Config);

		CANRxBlowerSpeed = BCMNode_LMO_01_Config.mo_ptr->can_data_byte[6] & 0x0f;
		CANRxRightTempCmd = BCMNode_LMO_01_Config.mo_ptr->can_data_byte[5] & 0x3f;
		CANRxLeftTempCmd = BCMNode_LMO_01_Config.mo_ptr->can_data_byte[4] & 0x3f;

		osMessagePut(message_q_id, CANRxBlowerSpeed,0);
	}
}
