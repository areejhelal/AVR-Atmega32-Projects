/*******************************/
/* Author  : Areej Ayman Helal */
/* Version : V01               */
/* Date    : 29 Jan 2020       */
/*******************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"


#include "Switch_interface.h"
#include "Switch_config.h"
#include "Switch_private.h"


u8 getSwitchState(void)
{
	u8 Result;
	Result = DIO_getPinValue(Switch_Port , Switch_Pin  );
	#if RELEASE_STATE == 0 
	
		return Result;
	
	#else
	
		return Result ^ 1 ; /*or we can Toggle to reverse the result */
	#endif
}

