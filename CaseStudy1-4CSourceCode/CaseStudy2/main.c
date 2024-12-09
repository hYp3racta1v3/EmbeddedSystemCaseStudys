/*
 * main.c
 *
 *  Created on: 2024 Sep 26 15:31:34
 *  Author: thoma
 */




#include "DAVE.h"                 //Declarations from DAVE Code Generation (includes SFR declaration)
#include "BlowerTest.h"
#include "BlowerSpeedCTRL.h"
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
  uint32_t TimerId;
  uint32_t timerStatus;



  status = DAVE_Init(); /* Initialization of DAVE APPs  */


  if (status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }

#ifdef TESTMODE
  TimerId = SYSTIMER_CreateTimer(SYSTIMER_TICK_PERIOD_US,SYSTIMER_MODE_PERIODIC,(void*)runBlowerTest,NULL);
  if(TimerId != 0U){
	  timerStatus = SYSTIMER_StartTimer(TimerId);
	  if(timerStatus == SYSTIMER_STATUS_SUCCESS){
		  // success
	  }
	  else{
		  //error
	  }
	 }
#endif

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {
	  __WFI();
  }
}
