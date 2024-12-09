/*
 * main.c
 *
 *  Created on: 2024 Sep 26 15:31:34
 *  Author:
 */




#include "DAVE.h"                 //Declarations from DAVE Code Generation (includes SFR declaration)
#include "BlowerTest.h"
#include "BlowerSpeedCTRL.h"
#include "adcCTRL.h"
#include "ADCCTRL.H"

osThreadId tid_BlowerSpeedCTRLThread;
osThreadId tid_BlowerTestThread;
osThreadId tid_ADCCTRLThread; // creates the thread to allow the os to run the function

osThreadDef (runBlowerSpeedCTRL, osPriorityNormal, 1, 1024);
osThreadDef (runBlowerTest, osPriorityNormal, 1, 1024);
osThreadDef (runAdcCtrl, osPriorityNormal, 1, 1024); // set to normal priority to run otherwise the blowerTest and blowerCtrl will constantly run
/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

int main(void)
{
  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  if (status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }

  tid_BlowerSpeedCTRLThread = osThreadCreate(osThread(runBlowerSpeedCTRL),NULL);
  tid_ADCCTRLThread = osThreadCreate(osThread(runAdcCtrl),NULL);
#ifdef TESTMODE
  tid_BlowerTestThread = osThreadCreate(osThread(runBlowerTest),NULL);
#endif

  osKernelStart();

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {

  }
}

volatile uint32_t g_stat_timer_ticks;

void FreeRtosTraceIsr(void){
	g_stat_timer_ticks++;
}
