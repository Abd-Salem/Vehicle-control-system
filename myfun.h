 /******************************************************************************
 *
 * File Name: defines.h
 *
 * Description: types for Vehicle Control system
 *
 * Author: Abdallah Ashraf
 *
 *******************************************************************************/


#ifndef MYFUN_H_
#define MYFUN_H_

#include "defines.h"

/*
 * description:
 * structure of variables that represent the states of system
 * */
typedef struct{
	bool Eng_state;
	bool AC;
	bool eng_temp_con_state;
}VecState;



/*
 * description:
 * structure of variables that represent the reading of sensors
 *
 * */

typedef struct{
	uint32 room_temp;
	uint32 eng_temp;
	uint32 vec_speed;
}VecVar;



/* structures that will used in another file  */


/*
 *  description:
 * 	function that check states of the parts of the vehicle system
 * 	print the states to the user
 */
noret printstates(VecVar *var,VecState *state);


/*
 * description:
 * function called when the user turn on the engine
 *
 */
noret Turn_on_options(noarg);



/*
 * description:
 * get the color of the traffic lights
 * checking the color and taking an action on the vehicle speed
 *
 */
noret traffic_lights(VecVar *var);


/*
 * description:
 * get the temperature degree value of the room
 * take action according to the degree
 *
 */
noret room_temp_check(VecVar *var,VecState *state);



/*
 * description:
 * getting engine temperature value
 * take action according to the value
 *
 */
noret eng_temp_check(VecVar *var,VecState *state);



/*
 * description:
 * specific condition for vehicle speed
 * take an action according to a specific speed
 */
noret vec_speed_op(VecVar *var,VecState *state);



/*
 * description:
 * checking the states and handling it according to shutdown option
 */
noret shutdown_eng(VecVar *var,VecState *state);



/*
 * description:
 * if user turn on the engine this function is called
 * complete the turn on state with the user
 *
 */
noret turn_on_states(noarg);

#endif /* MYFUN_H_ */
