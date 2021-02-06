#include "app_funcs.h"
#include "app_ios_and_regs.h"
#include "hwbp_core.h"


/************************************************************************/
/* Create pointers to functions                                         */
/************************************************************************/
extern AppRegs app_regs;

void (*app_func_rd_pointer[])(void) = {
	&app_read_REG_AUX_INPUTS,
	&app_read_REG_INPUTS,
	&app_read_REG_RISING_EDGE_ENABLE,
	&app_read_REG_FALLING_EDGE_ENABLE,
	&app_read_REG_INPUT_MODE,
	&app_read_REG_RESERVED0,
	&app_read_REG_RESERVED1,
	&app_read_REG_EXPANSION_OPTIONS
};

bool (*app_func_wr_pointer[])(void*) = {
	&app_write_REG_AUX_INPUTS,
	&app_write_REG_INPUTS,
	&app_write_REG_RISING_EDGE_ENABLE,
	&app_write_REG_FALLING_EDGE_ENABLE,
	&app_write_REG_INPUT_MODE,
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
/* REG_INPUTS                                                           */
/************************************************************************/
// This register is an array with 2 positions
void app_read_REG_INPUTS(void)
{
	// This register should be always up to date due to interrupts
}

bool app_write_REG_INPUTS(void *a) { return false; }


/************************************************************************/
/* REG_RISING_EDGE_ENABLE                                               */
/************************************************************************/
void app_read_REG_RISING_EDGE_ENABLE(void) {}
bool app_write_REG_RISING_EDGE_ENABLE(void *a)
{
	uint16_t reg = *((uint16_t*)a);

	app_regs.REG_RISING_EDGE_ENABLE = reg;
	return true;
}


/************************************************************************/
/* REG_FALLING_EDGE_ENABLE                                              */
/************************************************************************/
void app_read_REG_FALLING_EDGE_ENABLE(void) {}
bool app_write_REG_FALLING_EDGE_ENABLE(void *a)
{
	uint16_t reg = *((uint16_t*)a);

	app_regs.REG_FALLING_EDGE_ENABLE = reg;
	return true;
}


/************************************************************************/
/* REG_INPUT_MODE                                                       */
/************************************************************************/
extern uint16_t inputs_previous_read;

void app_read_REG_INPUT_MODE(void) {}
bool app_write_REG_INPUT_MODE(void *a)
{
	uint8_t reg = *((uint8_t*)a);
	
	switch (reg)
	{
		case MSK_ON_INTERRUPTS:
			inputs_previous_read  = (read_IN0 ? B_IN0 : 0) | (read_IN1 ? B_IN1 : 0) | (read_IN2 ? B_IN2 : 0) | (read_IN3 ? B_IN3 : 0) | (read_IN4 ? B_IN4 : 0);
			inputs_previous_read |= (read_IN5 ? B_IN5 : 0) | (read_IN6 ? B_IN6 : 0) | (read_IN7 ? B_IN7 : 0) | (read_IN8 ? B_IN8 : 0) | (read_IN9 ? B_IN9 : 0);
	
			io_set_int(&PORTD, INT_LEVEL_LOW, 0, (1<<4), false);                 // IN0
			io_set_int(&PORTD, INT_LEVEL_LOW, 0, (1<<3), false);                 // IN1
			io_set_int(&PORTD, INT_LEVEL_LOW, 0, (1<<2), false);                 // IN2
			io_set_int(&PORTD, INT_LEVEL_LOW, 0, (1<<1), false);                 // IN3
			io_set_int(&PORTD, INT_LEVEL_LOW, 0, (1<<0), false);                 // IN4
			io_set_int(&PORTC, INT_LEVEL_LOW, 0, (1<<0), false);                 // IN5
			io_set_int(&PORTC, INT_LEVEL_LOW, 0, (1<<1), false);                 // IN6
			io_set_int(&PORTC, INT_LEVEL_LOW, 0, (1<<2), false);                 // IN7
			io_set_int(&PORTC, INT_LEVEL_LOW, 0, (1<<3), false);                 // IN8
			io_set_int(&PORTE, INT_LEVEL_LOW, 1, (1<<0), false);                 // IN9
	
			break;
	
		case MSK_AT_1000FPS:
		case MSK_AT_2000FPS:
			/* Don't use the change mask */
			app_regs.REG_INPUTS[1]  = 0;
	
			/* Disable interrupts */
			io_set_int(&PORTD, INT_LEVEL_OFF, 0, (1<<4), false);                 // IN0
			io_set_int(&PORTD, INT_LEVEL_OFF, 0, (1<<3), false);                 // IN1
			io_set_int(&PORTD, INT_LEVEL_OFF, 0, (1<<2), false);                 // IN2
			io_set_int(&PORTD, INT_LEVEL_OFF, 0, (1<<1), false);                 // IN3
			io_set_int(&PORTD, INT_LEVEL_OFF, 0, (1<<0), false);                 // IN4
			io_set_int(&PORTC, INT_LEVEL_OFF, 0, (1<<0), false);                 // IN5
			io_set_int(&PORTC, INT_LEVEL_OFF, 0, (1<<1), false);                 // IN6
			io_set_int(&PORTC, INT_LEVEL_OFF, 0, (1<<2), false);                 // IN7
			io_set_int(&PORTC, INT_LEVEL_OFF, 0, (1<<3), false);                 // IN8
			io_set_int(&PORTE, INT_LEVEL_OFF, 1, (1<<0), false);                 // IN9
	
			break;
	
		default:
			return false;
	}

	app_regs.REG_EXPANSION_OPTIONS = reg;
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
	uint8_t reg = *((uint8_t*)a);
	
	switch (reg)
	{
		case MSK_BREAKOUT:
			break;
	}

	app_regs.REG_EXPANSION_OPTIONS = reg;
	return true;
}