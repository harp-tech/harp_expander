#include "app_funcs.h"
#include "app_ios_and_regs.h"
#include "hwbp_core.h"


/************************************************************************/
/* Create pointers to functions                                         */
/************************************************************************/
extern AppRegs app_regs;

void (*app_func_rd_pointer[])(void) = {
	&app_read_REG_AUX_INPUTS,
	&app_read_REG_AUX_INPUTS_RISING_EDGE_ENABLE,
	&app_read_REG_AUX_INPUTS_FALLING_EDGE_ENABLE,
	&app_read_REG_INPUTS,
	&app_read_REG_RISING_EDGE_ENABLE,
	&app_read_REG_FALLING_EDGE_ENABLE,
	&app_read_REG_INPUT_MODE,
	&app_read_REG_ENCODER_MODE,
	&app_read_REG_ENCODER,
	&app_read_REG_EXPANSION_OPTIONS
};

bool (*app_func_wr_pointer[])(void*) = {
	&app_write_REG_AUX_INPUTS,
	&app_write_REG_AUX_INPUTS_RISING_EDGE_ENABLE,
	&app_write_REG_AUX_INPUTS_FALLING_EDGE_ENABLE,
	&app_write_REG_INPUTS,
	&app_write_REG_RISING_EDGE_ENABLE,
	&app_write_REG_FALLING_EDGE_ENABLE,
	&app_write_REG_INPUT_MODE,
	&app_write_REG_ENCODER_MODE,
	&app_write_REG_ENCODER,
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
/* REG_AUX_INPUTS_RISING_EDGE_ENABLE                                    */
/************************************************************************/
void app_read_REG_AUX_INPUTS_RISING_EDGE_ENABLE(void) {}
bool app_write_REG_AUX_INPUTS_RISING_EDGE_ENABLE(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_AUX_INPUTS_RISING_EDGE_ENABLE = reg;
	return true;
}


/************************************************************************/
/* REG_AUX_INPUTS_FALLING_EDGE_ENABLE                                   */
/************************************************************************/
void app_read_REG_AUX_INPUTS_FALLING_EDGE_ENABLE(void) {}
bool app_write_REG_AUX_INPUTS_FALLING_EDGE_ENABLE(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_AUX_INPUTS_FALLING_EDGE_ENABLE = reg;
	return true;
}


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
			
			/* Enable all the interrupts */
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
	
			/* Disable interrupts on PORTD N=0, PORTC N=0 and PORTE N=1*/
			io_set_int(&PORTD, INT_LEVEL_OFF, 0, 0, true);
			io_set_int(&PORTC, INT_LEVEL_OFF, 0, 0, true);
			io_set_int(&PORTE, INT_LEVEL_OFF, 1, 0, true);
	
			break;
	
		default:
			return false;
	}

	app_regs.REG_EXPANSION_OPTIONS = reg;
	return true;
}


/************************************************************************/
/* REG_ENCODER_MODE                                                     */
/************************************************************************/
extern uint8_t aux_inputs_previous_read;

// https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-8331-8-and-16-bit-AVR-Microcontroller-XMEGA-AU_Manual.pdf

void app_read_REG_ENCODER_MODE(void) {}
bool app_write_REG_ENCODER_MODE(void *a)
{
	uint8_t reg = *((uint8_t*)a);
	
	if (reg & ~(GM_ENC_MODE))
		return false;
	
	if (reg & GM_ENC_MODE)
	{
		/* Disable interrupts on PORTE N=0 */
		io_set_int(&PORTE, INT_LEVEL_OFF, 0, 0, true);

		/* Set up quadrature decoding event */
		EVSYS_CH0MUX = EVSYS_CHMUX_PORTE_PIN4_gc;                           // P. 77 of above manual
		EVSYS_CH0CTRL = EVSYS_QDEN_bm | EVSYS_DIGFILT_2SAMPLES_gc;          // P. 78 of above manual
			
		/* Stop and reset timer */
		TCE1_CTRLA = TC_CLKSEL_OFF_gc;
		TCE1_CTRLFSET = TC_CMD_RESET_gc;
			
		/* Configure timer */
		TCE1_CTRLD = TC_EVACT_QDEC_gc | TC_EVSEL_CH0_gc;	                // P. 176-177 of above manual
		TCE1_PER = 0xFFFF;
		TCE1_CNT = 0x8000;
			
		/* Start timer */
		TCE1_CTRLA = TC_CLKSEL_DIV1_gc;		
	}
	else
	{
		/* Stop timer */
		/* Do not reset to preserve last encoder */
		TCE1_CTRLA = TC_CLKSEL_OFF_gc;
		
		/* Read current state of aux inputs */
		aux_inputs_previous_read = (read_AUX_INPUT0 ? B_AUX_IN0 : 0) | (read_AUX_INPUT1 ? B_AUX_IN1 : 0);
			
		/* Enable interrupts on pins AUX_INPUT0 and AUX_INPUT1 */
		io_set_int(&PORTE, INT_LEVEL_LOW, 0, (1<<2), false);	// AUX_INPUT0
		io_set_int(&PORTE, INT_LEVEL_LOW, 0, (1<<5), false);	// AUX_INPUT1
	}

	app_regs.REG_ENCODER_MODE = reg;
	return true;
}


/************************************************************************/
/* REG_ENCODER                                                          */
/************************************************************************/
void app_read_REG_ENCODER(void)
{
	int16_t timer_cnt = TCE1_CNT;
	
	if (timer_cnt > 32768)
	{
		app_regs.REG_ENCODER = 0xFFFF - timer_cnt;
	}
	else
	{
		app_regs.REG_ENCODER = (32768 - timer_cnt) * -1;
	}
}
bool app_write_REG_ENCODER(void *a)
{
	int16_t reg = *((int16_t*)a);
	
	if (app_regs.REG_ENCODER_MODE & GM_ENC_MODE)
	{
		if (reg > 32768)
		{
			TCE1_CNT = 0xFFFF - reg;
		}
		else
		{
			TCE1_CNT = (32768 - reg) * -1;
		}
	}

	app_regs.REG_ENCODER = reg;
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