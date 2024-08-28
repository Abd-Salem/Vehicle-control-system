 /******************************************************************************
 *
 * File Name: mainprog.c
 *
 * Description: source file of Vehicle Control system
 *
 * Author: Abdallah Ashraf
 *
 *******************************************************************************/


#include <stdio.h>
#include "defines.h"
#include "myfun.h"

/* definition */
#define Quit_System   return 0


extern VecVar g_variables; //global structure for system changes according to sensors in the system

extern VecState g_statements; //global structure readings and states of the system

extern uint8 g_input;  //global variable that get the input from the user





int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);  //resolving print issue in eclipse IDE
	setvbuf(stderr, NULL, _IONBF, 0);

	/* initial values for temperature parameters*/
	g_variables.eng_temp = 50;
	g_variables.room_temp = 25;

	while(1)
	{
		/*system options for user*/
		printf("a- Turn ON the Vehicle Engine\n");
		printf("b- Turn OFF the Vehicle Engine\n");
		printf("c- Quit the System\n");


		printstates(&g_variables,&g_statements);  //print states of the vehicle

		/* get option that the user chose and making sure that the user choose the right option
		 * if user chooses c system will shutdown.
		 * if user chooses b engine will be stopped if it runs
		 * if user chooses a engine will be turned on if it is stopped and show to the user turn on engine options
		 *  */

		scanf(" %c",&g_input);
		while(g_input != 'a' && g_input != 'b' && g_input != 'c')
		{
			printf("Please, enter right option!!\n");
			scanf(" %c",&g_input);
		}
		if(g_input == 'c')
		{
			Quit_System;
		}
		else if(g_input == 'b')
		{
			shutdown_eng(&g_variables,&g_statements);
			continue;   //return to while(1) again
		}
		else if(g_input == 'a')
		{
			turn_on_states();    //states and options when user choose to turn on the engine
		}


	}
	return 0;
}
//END of the file
