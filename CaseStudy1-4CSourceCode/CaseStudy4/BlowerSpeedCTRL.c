/* BlowerSpeedCTRL.c
 *
 *  Created on: 26 Sep 2024
 *      Author: thoma
 */

#include "BlowerSpeedCTRL.h"
#include "Dave.h"

void runBlowerSpeedCTRL(void *arg){
	static uint8_t inBlowerSpeedCmd;
	static uint8_t inRightTempCmd;
	static uint8_t inLeftTempCmd;
	osEvent event;
	extern osMessageQId message_q_id;


	while(1){
		event = osMessageGet(message_q_id, osWaitForever);
		inBlowerSpeedCmd = event.value.v;

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

		PWM_SetDutyCycle(&PWM_0, 1400*(inBlowerSpeedCmd));

		osDelay(100);
	}
}
