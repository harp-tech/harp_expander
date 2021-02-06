#include "app_funcs.h"
#include "app_ios_and_regs.h"
#include "hwbp_core.h"


/************************************************************************/
/* Create pointers to functions                                         */
/************************************************************************/
extern AppRegs app_regs;

void (*app_func_rd_pointer[])(void) = {
	&app_read_REG_AUX_INPUTS,
	&app_read_REG_OUTPUTS_SET,
	&app_read_REG_OUTPUTS_CLEAR,
	&app_read_REG_OUTPUTS_TOGGLE,
	&app_read_REG_OUTPUTS_WRITE,
	&app_read_REG_RESERVED0,
	&app_read_REG_RESERVED1,
	&app_read_REG_EXPANSION_OPTIONS
};

bool (*app_func_wr_pointer[])(void*) = {
	&app_write_REG_AUX_INPUTS,
	&app_write_REG_OUTPUTS_SET,
	&app_write_REG_OUTPUTS_CLEAR,
	&app_write_REG_OUTPUTS_TOGGLE,
	&app_write_REG_OUTPUTS_WRITE,
	&app_write_REG_RESERVED0,
	&app_write_REG_RESERVED1,
	&app_write_REG_EXPANSION_OPTIONS
};


/************************************************************************/
/* REG_AUX_INPUTS                                                       */
/************************************************************************/
void app_read_REG_AUX_INPUTS(void)
{
	// This register should be always up to date due to interrupts
}

bool app_write_REG_AUX_INPUTS(void *a) { return false; }


/************************************************************************/
/* REG_OUTPUTS_SET                                                      */
/************************************************************************/
void app_read_REG_OUTPUTS_SET(void) {}
bool app_write_REG_OUTPUTS_SET(void *a)
{
	uint16_t reg = *((uint16_t*)a);
	
	if (reg & B_OUT0) { set_OUT0; if (core_bool_is_visual_enabled()) set_LED_0; }
	if (reg & B_OUT1) { set_OUT1; if (core_bool_is_visual_enabled()) set_LED_1; }
	if (reg & B_OUT2) { set_OUT2; if (core_bool_is_visual_enabled()) set_LED_2; }
	if (reg & B_OUT3) { set_OUT3; if (core_bool_is_visual_enabled()) set_LED_3; }
	if (reg & B_OUT4) { set_OUT4; if (core_bool_is_visual_enabled()) set_LED_4; }
	if (reg & B_OUT5) { set_OUT5; if (core_bool_is_visual_enabled()) set_LED_5; }
	if (reg & B_OUT6) { set_OUT6; if (core_bool_is_visual_enabled()) set_LED_6; }
	if (reg & B_OUT7) { set_OUT7; if (core_bool_is_visual_enabled()) set_LED_7; }
	if (reg & B_OUT8) { set_OUT8; if (core_bool_is_visual_enabled()) set_LED_8; }
	if (reg & B_OUT9) { set_OUT9; if (core_bool_is_visual_enabled()) set_LED_9; }

	app_regs.REG_OUTPUTS_SET = reg;
	return true;
}


/************************************************************************/
/* REG_OUTPUTS_CLEAR                                                    */
/************************************************************************/
void app_read_REG_OUTPUTS_CLEAR(void) {}
bool app_write_REG_OUTPUTS_CLEAR(void *a)
{
	uint16_t reg = *((uint16_t*)a);
	
	if (reg & B_OUT0) { clr_OUT0; clr_LED_0; }
	if (reg & B_OUT1) { clr_OUT1; clr_LED_1; }
	if (reg & B_OUT2) { clr_OUT2; clr_LED_2; }
	if (reg & B_OUT3) { clr_OUT3; clr_LED_3; }
	if (reg & B_OUT4) { clr_OUT4; clr_LED_4; }
	if (reg & B_OUT5) { clr_OUT5; clr_LED_5; }
	if (reg & B_OUT6) { clr_OUT6; clr_LED_6; }
	if (reg & B_OUT7) { clr_OUT7; clr_LED_7; }
	if (reg & B_OUT8) { clr_OUT8; clr_LED_8; }
	if (reg & B_OUT9) { clr_OUT9; clr_LED_9; }

	app_regs.REG_OUTPUTS_CLEAR = reg;
	return true;
}


/************************************************************************/
/* REG_OUTPUTS_TOGGLE                                                   */
/************************************************************************/
void app_read_REG_OUTPUTS_TOGGLE(void) {}
bool app_write_REG_OUTPUTS_TOGGLE(void *a)
{
	uint16_t reg = *((uint16_t*)a);
	
	if (reg & B_OUT0) { tgl_OUT0; if (core_bool_is_visual_enabled()) tgl_LED_0; }
	if (reg & B_OUT1) { tgl_OUT1; if (core_bool_is_visual_enabled()) tgl_LED_1; }
	if (reg & B_OUT2) { tgl_OUT2; if (core_bool_is_visual_enabled()) tgl_LED_2; }
	if (reg & B_OUT3) { tgl_OUT3; if (core_bool_is_visual_enabled()) tgl_LED_3; }
	if (reg & B_OUT4) { tgl_OUT4; if (core_bool_is_visual_enabled()) tgl_LED_4; }
	if (reg & B_OUT5) { tgl_OUT5; if (core_bool_is_visual_enabled()) tgl_LED_5; }
	if (reg & B_OUT6) { tgl_OUT6; if (core_bool_is_visual_enabled()) tgl_LED_6; }
	if (reg & B_OUT7) { tgl_OUT7; if (core_bool_is_visual_enabled()) tgl_LED_7; }
	if (reg & B_OUT8) { tgl_OUT8; if (core_bool_is_visual_enabled()) tgl_LED_8; }
	if (reg & B_OUT9) { tgl_OUT9; if (core_bool_is_visual_enabled()) tgl_LED_9; }

	app_regs.REG_OUTPUTS_TOGGLE = reg;
	return true;
}


/************************************************************************/
/* REG_OUTPUTS_WRITE                                                    */
/************************************************************************/
void app_read_REG_OUTPUTS_WRITE(void)
{
	app_regs.REG_OUTPUTS_WRITE  = (read_OUT0) ? B_OUT0 : 0;
	app_regs.REG_OUTPUTS_WRITE |= (read_OUT1) ? B_OUT1 : 0;
	app_regs.REG_OUTPUTS_WRITE |= (read_OUT2) ? B_OUT2 : 0;
	app_regs.REG_OUTPUTS_WRITE |= (read_OUT3) ? B_OUT3 : 0;
	app_regs.REG_OUTPUTS_WRITE |= (read_OUT4) ? B_OUT4 : 0;
	app_regs.REG_OUTPUTS_WRITE |= (read_OUT5) ? B_OUT5 : 0;
	app_regs.REG_OUTPUTS_WRITE |= (read_OUT6) ? B_OUT6 : 0;
	app_regs.REG_OUTPUTS_WRITE |= (read_OUT7) ? B_OUT7 : 0;
	app_regs.REG_OUTPUTS_WRITE |= (read_OUT8) ? B_OUT8 : 0;
	app_regs.REG_OUTPUTS_WRITE |= (read_OUT9) ? B_OUT9 : 0;
}

bool app_write_REG_OUTPUTS_WRITE(void *a)
{
	uint16_t reg = *((uint16_t*)a);
	
	if (reg & B_OUT0) { set_OUT0; if (core_bool_is_visual_enabled()) set_LED_0; } else { clr_OUT0; clr_LED_0; }
	if (reg & B_OUT1) { set_OUT1; if (core_bool_is_visual_enabled()) set_LED_1; } else { clr_OUT1; clr_LED_1; }
	if (reg & B_OUT2) { set_OUT2; if (core_bool_is_visual_enabled()) set_LED_2; } else { clr_OUT2; clr_LED_2; }
	if (reg & B_OUT3) { set_OUT3; if (core_bool_is_visual_enabled()) set_LED_3; } else { clr_OUT3; clr_LED_3; }
	if (reg & B_OUT4) { set_OUT4; if (core_bool_is_visual_enabled()) set_LED_4; } else { clr_OUT4; clr_LED_4; }
	if (reg & B_OUT5) { set_OUT5; if (core_bool_is_visual_enabled()) set_LED_5; } else { clr_OUT5; clr_LED_5; }
	if (reg & B_OUT6) { set_OUT6; if (core_bool_is_visual_enabled()) set_LED_6; } else { clr_OUT6; clr_LED_6; }
	if (reg & B_OUT7) { set_OUT7; if (core_bool_is_visual_enabled()) set_LED_7; } else { clr_OUT7; clr_LED_7; }
	if (reg & B_OUT8) { set_OUT8; if (core_bool_is_visual_enabled()) set_LED_8; } else { clr_OUT8; clr_LED_8; }
	if (reg & B_OUT9) { set_OUT9; if (core_bool_is_visual_enabled()) set_LED_9; } else { clr_OUT9; clr_LED_9; }
		
	app_regs.REG_OUTPUTS_WRITE = reg;
	return true;
}


/************************************************************************/
/* REG_RESERVED0                                                        */
/************************************************************************/
void app_read_REG_RESERVED0(void) {}
bool app_write_REG_RESERVED0(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_RESERVED0 = reg;
	return true;
}


/************************************************************************/
/* REG_RESERVED1                                                        */
/************************************************************************/
void app_read_REG_RESERVED1(void) {}
bool app_write_REG_RESERVED1(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_RESERVED1 = reg;
	return true;
}


/************************************************************************/
/* REG_EXPANSION_OPTIONS                                                */
/************************************************************************/
void app_read_REG_EXPANSION_OPTIONS(void) {}
bool app_write_REG_EXPANSION_OPTIONS(void *a)
{
	 uint16_t reg = *((uint16_t*)a);
	 
	 switch (reg)
	 {
		 case MSK_BREAKOUT:
			break;
		case MSK_MAGNETIC_ENCODER:
			break;
		case MSK_SERVO_MOTOR_1:
			break;
		case MSK_SERVO_MOTOR_2:
			break;
		case MSK_CAMERAS:
			break;
		case MSK_PWM_1:
			break;
		case MSK_PWM_2:
			break;
	 }
	
	app_regs.REG_EXPANSION_OPTIONS = reg;
	return true;
}