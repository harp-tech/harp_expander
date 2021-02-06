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
void app_read_REG_OUTPUTS_SET(void);
void app_read_REG_OUTPUTS_CLEAR(void);
void app_read_REG_OUTPUTS_TOGGLE(void);
void app_read_REG_OUTPUTS_WRITE(void);
void app_read_REG_RESERVED0(void);
void app_read_REG_RESERVED1(void);
void app_read_REG_EXPANSION_OPTIONS(void);

bool app_write_REG_AUX_INPUTS(void *a);
bool app_write_REG_OUTPUTS_SET(void *a);
bool app_write_REG_OUTPUTS_CLEAR(void *a);
bool app_write_REG_OUTPUTS_TOGGLE(void *a);
bool app_write_REG_OUTPUTS_WRITE(void *a);
bool app_write_REG_RESERVED0(void *a);
bool app_write_REG_RESERVED1(void *a);
bool app_write_REG_EXPANSION_OPTIONS(void *a);


#endif /* _APP_FUNCTIONS_H_ */