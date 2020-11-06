#ifndef _APP_FUNCTIONS_H_
#define _APP_FUNCTIONS_H_
#include <avr/io.h>


/************************************************************************/
/* Define if not defined                                                */
/************************************************************************/
#ifndef bool
	#define bool uint8_t
#endif
#ifndef true
	#define true 1
#endif
#ifndef false
	#define false 0
#endif


/************************************************************************/
/* Prototypes                                                           */
/************************************************************************/
void app_read_REG_AUX_INPUTS(void);
void app_read_REG_INPUTS(void);

bool app_write_REG_AUX_INPUTS(void *a);
bool app_write_REG_INPUTS(void *a);


#endif /* _APP_FUNCTIONS_H_ */