/*
 * adcCTRL.c
 *
 *  Created on: 26 Sep 2024
 *      Author:
 */

#include "adcCTRL.h"
#include "Dave.h"

XMC_VADC_RESULT_SIZE_t inADCValue; // defines a variable of size result, in this case an uint 16

void runAdcCtrl(void *arg){

	while(1){
	inADCValue = ADC_MEASUREMENT_GetResult(&ADC_MEASUREMENT_Channel_A); //0-4096 receives the value from potentiometer from 0 to 4096

	if(inADCValue <= 1365){// sets the left LED on or off dependent on value received from potentiometer
		DIGITAL_IO_SetOutputLow(&DIGITAL_IO_0);// value at 1365 to evenly split the values into three equal parts eg. low mid high
						}
	else{
		DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_0);

	}
	if(inADCValue >= 2731){// sets the right LED on or off dependent on value received from potentiometer
		DIGITAL_IO_SetOutputLow(&DIGITAL_IO_1);
	}
	else{
		DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_1);
	}
	osDelay(100);
	}
}
