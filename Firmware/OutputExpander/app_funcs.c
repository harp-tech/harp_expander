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
	&app_read_REG_EXPANSION_OPTIONS,
	&app_read_REG_RESERVED2,
	&app_read_REG_RESERVED3,
	&app_read_REG_MAG_ENCODER_READ,
	&app_read_REG_MAG_ENCODER_MODE,
	&app_read_REG_RESERVED4,
	&app_read_REG_RESERVED5,
	&app_read_REG_SERVO_PERIOD_US,
	&app_read_REG_SERVO0_PULSE_US,
	&app_read_REG_SERVO1_PULSE_US,
	&app_read_REG_SERVO2_PULSE_US
};

bool (*app_func_wr_pointer[])(void*) = {
	&app_write_REG_AUX_INPUTS,
	&app_write_REG_OUTPUTS_SET,
	&app_write_REG_OUTPUTS_CLEAR,
	&app_write_REG_OUTPUTS_TOGGLE,
	&app_write_REG_OUTPUTS_WRITE,
	&app_write_REG_RESERVED0,
	&app_write_REG_RESERVED1,
	&app_write_REG_EXPANSION_OPTIONS,
	&app_write_REG_RESERVED2,
	&app_write_REG_RESERVED3,
	&app_write_REG_MAG_ENCODER_READ,
	&app_write_REG_MAG_ENCODER_MODE,
	&app_write_REG_RESERVED4,
	&app_write_REG_RESERVED5,
	&app_write_REG_SERVO_PERIOD_US,
	&app_write_REG_SERVO0_PULSE_US,
	&app_write_REG_SERVO1_PULSE_US,
	&app_write_REG_SERVO2_PULSE_US
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
#define PINS_MASK_BREAKOUT         B_OUT0 | B_OUT1 | B_OUT2 | B_OUT3 | B_OUT4 | B_OUT5 | B_OUT6 | B_OUT7 | B_OUT8 | B_OUT9
#define PINS_MASK_MAGNETIC_ENCODER B_OUT0 | B_OUT1 | B_OUT2 | B_OUT3 | B_OUT4 |                   B_OUT7 | B_OUT8
#define PINS_MASK_SERVO_MOTOR_1    B_OUT0 | B_OUT1 | B_OUT2 | B_OUT3 | B_OUT4 |          B_OUT6 | B_OUT7 | B_OUT8 | B_OUT9
#define PINS_MASK_SERVO_MOTOR_2    B_OUT0 | B_OUT1 | B_OUT2 | B_OUT3 | B_OUT4 |                   B_OUT7 | B_OUT8 | B_OUT9
#define PINS_MASK_SERVO_MOTOR_3    B_OUT0 | B_OUT1 | B_OUT2 | B_OUT3 | B_OUT4 |                            B_OUT8 | B_OUT9

void app_read_REG_OUTPUTS_SET(void) {}
bool app_write_REG_OUTPUTS_SET(void *a)
{
	uint16_t reg = *((uint16_t*)a);
	
	uint16_t mask = 0;
	
	switch (app_regs.REG_EXPANSION_OPTIONS)
	{
		case MSK_BREAKOUT: mask = PINS_MASK_BREAKOUT; break;		
		case MSK_MAGNETIC_ENCODER: mask = PINS_MASK_MAGNETIC_ENCODER; break;		
		case MSK_SERVO_MOTOR_1: mask = PINS_MASK_SERVO_MOTOR_1; break;		
		case MSK_SERVO_MOTOR_2: mask = PINS_MASK_SERVO_MOTOR_2; break;		
		case MSK_SERVO_MOTOR_3: mask = PINS_MASK_SERVO_MOTOR_3; break;
	}
	
	if ((reg & B_OUT0) & mask) { set_OUT0; if (core_bool_is_visual_enabled()) set_LED_0; }
	if ((reg & B_OUT1) & mask) { set_OUT1; if (core_bool_is_visual_enabled()) set_LED_1; }
	if ((reg & B_OUT2) & mask) { set_OUT2; if (core_bool_is_visual_enabled()) set_LED_2; }
	if ((reg & B_OUT3) & mask) { set_OUT3; if (core_bool_is_visual_enabled()) set_LED_3; }
	if ((reg & B_OUT4) & mask) { set_OUT4; if (core_bool_is_visual_enabled()) set_LED_4; }
	if ((reg & B_OUT5) & mask) { set_OUT5; if (core_bool_is_visual_enabled()) set_LED_5; }
	if ((reg & B_OUT6) & mask) { set_OUT6; if (core_bool_is_visual_enabled()) set_LED_6; }
	if ((reg & B_OUT7) & mask) { set_OUT7; if (core_bool_is_visual_enabled()) set_LED_7; }
	if ((reg & B_OUT8) & mask) { set_OUT8; if (core_bool_is_visual_enabled()) set_LED_8; }
	if ((reg & B_OUT9) & mask) { set_OUT9; if (core_bool_is_visual_enabled()) set_LED_9; }
		
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
	
	uint16_t mask = 0;
	
	switch (app_regs.REG_EXPANSION_OPTIONS)
	{
		case MSK_BREAKOUT: mask = PINS_MASK_BREAKOUT; break;
		case MSK_MAGNETIC_ENCODER: mask = PINS_MASK_MAGNETIC_ENCODER; break;
		case MSK_SERVO_MOTOR_1: mask = PINS_MASK_SERVO_MOTOR_1; break;
		case MSK_SERVO_MOTOR_2: mask = PINS_MASK_SERVO_MOTOR_2; break;
		case MSK_SERVO_MOTOR_3: mask = PINS_MASK_SERVO_MOTOR_3; break;
	}
	
	if ((reg & B_OUT0) & mask) { clr_OUT0; clr_LED_0; }
	if ((reg & B_OUT1) & mask) { clr_OUT1; clr_LED_1; }
	if ((reg & B_OUT2) & mask) { clr_OUT2; clr_LED_2; }
	if ((reg & B_OUT3) & mask) { clr_OUT3; clr_LED_3; }
	if ((reg & B_OUT4) & mask) { clr_OUT4; clr_LED_4; }
	if ((reg & B_OUT5) & mask) { clr_OUT5; clr_LED_5; }
	if ((reg & B_OUT6) & mask) { clr_OUT6; clr_LED_6; }
	if ((reg & B_OUT7) & mask) { clr_OUT7; clr_LED_7; }
	if ((reg & B_OUT8) & mask) { clr_OUT8; clr_LED_8; }
	if ((reg & B_OUT9) & mask) { clr_OUT9; clr_LED_9; }

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
	
	uint16_t mask = 0;
	
	switch (app_regs.REG_EXPANSION_OPTIONS)
	{
		case MSK_BREAKOUT: mask = PINS_MASK_BREAKOUT; break;
		case MSK_MAGNETIC_ENCODER: mask = PINS_MASK_MAGNETIC_ENCODER; break;
		case MSK_SERVO_MOTOR_1: mask = PINS_MASK_SERVO_MOTOR_1; break;
		case MSK_SERVO_MOTOR_2: mask = PINS_MASK_SERVO_MOTOR_2; break;
		case MSK_SERVO_MOTOR_3: mask = PINS_MASK_SERVO_MOTOR_3; break;
	}
	
	if ((reg & B_OUT0) & mask) { tgl_OUT0; if (core_bool_is_visual_enabled()) tgl_LED_0; }
	if ((reg & B_OUT1) & mask) { tgl_OUT1; if (core_bool_is_visual_enabled()) tgl_LED_1; }
	if ((reg & B_OUT2) & mask) { tgl_OUT2; if (core_bool_is_visual_enabled()) tgl_LED_2; }
	if ((reg & B_OUT3) & mask) { tgl_OUT3; if (core_bool_is_visual_enabled()) tgl_LED_3; }
	if ((reg & B_OUT4) & mask) { tgl_OUT4; if (core_bool_is_visual_enabled()) tgl_LED_4; }
	if ((reg & B_OUT5) & mask) { tgl_OUT5; if (core_bool_is_visual_enabled()) tgl_LED_5; }
	if ((reg & B_OUT6) & mask) { tgl_OUT6; if (core_bool_is_visual_enabled()) tgl_LED_6; }
	if ((reg & B_OUT7) & mask) { tgl_OUT7; if (core_bool_is_visual_enabled()) tgl_LED_7; }
	if ((reg & B_OUT8) & mask) { tgl_OUT8; if (core_bool_is_visual_enabled()) tgl_LED_8; }
	if ((reg & B_OUT9) & mask) { tgl_OUT9; if (core_bool_is_visual_enabled()) tgl_LED_9; }

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
	
	uint16_t mask = 0;
	
	switch (app_regs.REG_EXPANSION_OPTIONS)
	{
		case MSK_BREAKOUT: mask = PINS_MASK_BREAKOUT; break;
		case MSK_MAGNETIC_ENCODER: mask = PINS_MASK_MAGNETIC_ENCODER; break;
		case MSK_SERVO_MOTOR_1: mask = PINS_MASK_SERVO_MOTOR_1; break;
		case MSK_SERVO_MOTOR_2: mask = PINS_MASK_SERVO_MOTOR_2; break;
		case MSK_SERVO_MOTOR_3: mask = PINS_MASK_SERVO_MOTOR_3; break;
	}
	
	if ((reg & B_OUT0) & mask) { set_OUT0; if (core_bool_is_visual_enabled()) set_LED_0; } else { clr_OUT0; clr_LED_0; }
	if ((reg & B_OUT1) & mask) { set_OUT1; if (core_bool_is_visual_enabled()) set_LED_1; } else { clr_OUT1; clr_LED_1; }
	if ((reg & B_OUT2) & mask) { set_OUT2; if (core_bool_is_visual_enabled()) set_LED_2; } else { clr_OUT2; clr_LED_2; }
	if ((reg & B_OUT3) & mask) { set_OUT3; if (core_bool_is_visual_enabled()) set_LED_3; } else { clr_OUT3; clr_LED_3; }
	if ((reg & B_OUT4) & mask) { set_OUT4; if (core_bool_is_visual_enabled()) set_LED_4; } else { clr_OUT4; clr_LED_4; }
	if ((reg & B_OUT5) & mask) { set_OUT5; if (core_bool_is_visual_enabled()) set_LED_5; } else { clr_OUT5; clr_LED_5; }
	if ((reg & B_OUT6) & mask) { set_OUT6; if (core_bool_is_visual_enabled()) set_LED_6; } else { clr_OUT6; clr_LED_6; }
	if ((reg & B_OUT7) & mask) { set_OUT7; if (core_bool_is_visual_enabled()) set_LED_7; } else { clr_OUT7; clr_LED_7; }
	if ((reg & B_OUT8) & mask) { set_OUT8; if (core_bool_is_visual_enabled()) set_LED_8; } else { clr_OUT8; clr_LED_8; }
	if ((reg & B_OUT9) & mask) { set_OUT9; if (core_bool_is_visual_enabled()) set_LED_9; } else { clr_OUT9; clr_LED_9; }
		
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
	 uint8_t reg = *((uint8_t*)a);
	 
	 switch (reg)
	 {
		 case MSK_BREAKOUT:
			io_set_int(&PORTE, INT_LEVEL_LOW, 0, (1<<2), false);	// Add AUX_INPUT0 to interrupt on PORTE INT N=0
			io_set_int(&PORTE, INT_LEVEL_LOW, 0, (1<<5), false);	// Add AUX_INPUT1 to interrupt on PORTE INT N=0
			
			timer_type0_stop(&TCC0);	// Terminate servo motors timer
			
			/* Clear all the outputs available in the breakout */
			clr_OUT5; clr_LED_5;
			clr_OUT6; clr_LED_6;
			clr_OUT7; clr_LED_7;
			clr_OUT8; clr_LED_8;
			clr_OUT9; clr_LED_9;
			break;
			
		case MSK_MAGNETIC_ENCODER:
			io_set_int(&PORTE, INT_LEVEL_LOW, 0, (1<<5), true);		// Enable only AUX_INPUT1 interrupt on PORTE INT N=0
			
			timer_type0_stop(&TCC0);	// Terminate servo motors timer
			
			/* Turn LEDs ON to show that they are being used */
			if (core_bool_is_visual_enabled())
			{
				set_OUT5;	// CS
				set_LED_5;	// CS
				set_LED_6;	// CLK
				set_LED_9;	// MOSI
				if (app_regs.REG_EXPANSION_OPTIONS == MSK_SERVO_MOTOR_3)    { clr_LED_7; }
			}
			break;
				
		case MSK_SERVO_MOTOR_1:		
			if (core_bool_is_visual_enabled())
			{
				set_LED_5;	// PWM servo 0
				if (app_regs.REG_EXPANSION_OPTIONS == MSK_MAGNETIC_ENCODER) { clr_LED_6; clr_LED_9; }
				if (app_regs.REG_EXPANSION_OPTIONS == MSK_SERVO_MOTOR_2)    { clr_LED_6;}
				if (app_regs.REG_EXPANSION_OPTIONS == MSK_SERVO_MOTOR_3)    { clr_LED_6; clr_LED_7; }
			}				
			TCC0_CTRLA = TC_CLKSEL_OFF_gc;							// Make sure timer is stopped to make reset
			TCC0_CTRLFSET = TC_CMD_RESET_gc;						// Timer reset (registers to initial value)			
			TCC0_PER = (app_regs.REG_SERVO_PERIOD_US >> 1) - 1;		// Set up target
			TCC0_CCA = (app_regs.REG_SERVO0_PULSE_US >> 1) - 1;		// Set duty cycle A			
			TCC0_CTRLB = TC0_CCAEN_bm | TC_WGMODE_SINGLESLOPE_gc;	// Enable channel A and single slope mode
			TCC0_CTRLA = TIMER_PRESCALER_DIV64;						// Start timer			
			break;
		
		case MSK_SERVO_MOTOR_2:		
			if (core_bool_is_visual_enabled())
			{
				set_LED_5;	// PWM servo 0
				set_LED_6;	// PWM servo 1
				if (app_regs.REG_EXPANSION_OPTIONS == MSK_MAGNETIC_ENCODER) { clr_LED_9; }
				if (app_regs.REG_EXPANSION_OPTIONS == MSK_SERVO_MOTOR_3)    { clr_LED_7; }
			}				
			TCC0_CTRLA = TC_CLKSEL_OFF_gc;							// Make sure timer is stopped to make reset
			TCC0_CTRLFSET = TC_CMD_RESET_gc;						// Timer reset (registers to initial value)			
			TCC0_PER = (app_regs.REG_SERVO_PERIOD_US >> 1) - 1;		// Set up target
			TCC0_CCA = (app_regs.REG_SERVO0_PULSE_US >> 1) - 1;		// Set duty cycle A
			TCC0_CCB = (app_regs.REG_SERVO1_PULSE_US >> 1) - 1;		// Set duty cycle B			
			TCC0_CTRLB = TC0_CCAEN_bm | TC_WGMODE_SINGLESLOPE_gc;	// Enable channel A and single slope mode
			TCC0_CTRLB |= TC0_CCBEN_bm;								// Enable channel B			
			TCC0_CTRLA = TIMER_PRESCALER_DIV64;						// Start timer			
			break;
		
		case MSK_SERVO_MOTOR_3:		
			if (core_bool_is_visual_enabled())
			{
				set_LED_5;	// PWM servo 0
				set_LED_6;	// PWM servo 1
				set_LED_7;	// PWM servo 2
				if (app_regs.REG_EXPANSION_OPTIONS == MSK_MAGNETIC_ENCODER) { clr_LED_9; }
			}				
			TCC0_CTRLA = TC_CLKSEL_OFF_gc;							// Make sure timer is stopped to make reset
			TCC0_CTRLFSET = TC_CMD_RESET_gc;						// Timer reset (registers to initial value)			
			TCC0_PER = (app_regs.REG_SERVO_PERIOD_US >> 1) - 1;		// Set up target
			TCC0_CCA = (app_regs.REG_SERVO0_PULSE_US >> 1) - 1;		// Set duty cycle A
			TCC0_CCB = (app_regs.REG_SERVO1_PULSE_US >> 1) - 1;		// Set duty cycle B
			TCC0_CCC = (app_regs.REG_SERVO2_PULSE_US >> 1) - 1;		// Set duty cycle C			
			TCC0_CTRLB = TC0_CCAEN_bm | TC_WGMODE_SINGLESLOPE_gc;	// Enable channel A and single slope mode
			TCC0_CTRLB |= TC0_CCBEN_bm;								// Enable channel B
			TCC0_CTRLB |= TC0_CCCEN_bm;								// Enable channel C			
			TCC0_CTRLA = TIMER_PRESCALER_DIV64;						// Start timer			
			break;			
		
		case MSK_CAMERAS:
			break;
			
		case MSK_PWM_1:
			break;
		
		default:
			return false;
	 }
	
	app_regs.REG_EXPANSION_OPTIONS = reg;
	return true;
}


/************************************************************************/
/* REG_RESERVED2                                                        */
/************************************************************************/
void app_read_REG_RESERVED2(void) {}
bool app_write_REG_RESERVED2(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_RESERVED2 = reg;
	return true;
}


/************************************************************************/
/* REG_RESERVED3                                                        */
/************************************************************************/
void app_read_REG_RESERVED3(void) {}
bool app_write_REG_RESERVED3(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_RESERVED3 = reg;
	return true;
}


/************************************************************************/
/* REG_MAG_ENCODER_READ                                                 */
/************************************************************************/
void app_read_REG_MAG_ENCODER_READ(void) {}
bool app_write_REG_MAG_ENCODER_READ(void *a) { return false; }


/************************************************************************/
/* REG_MAG_ENCODER_MODE                                                 */
/************************************************************************/
extern uint8_t magnetic_counter_divider;

void app_read_REG_MAG_ENCODER_MODE(void) {}
bool app_write_REG_MAG_ENCODER_MODE(void *a)
{
	uint8_t reg = *((uint8_t*)a);
	
	switch (reg)
	{
		case MSK_AT_50SPS:   magnetic_counter_divider = 1000/50;   break;
		case MSK_AT_100SPS:  magnetic_counter_divider = 1000/100;  break;
		case MSK_AT_200SPS:  magnetic_counter_divider = 1000/200;  break;
		case MSK_AT_250SPS:  magnetic_counter_divider = 1000/250;  break;
		case MSK_AT_500SPS:  magnetic_counter_divider = 1000/500;  break;
		case MSK_AT_1000SPS: magnetic_counter_divider = 1000/1000; break;
	}

	app_regs.REG_MAG_ENCODER_MODE = reg;
	return true;
}


/************************************************************************/
/* REG_RESERVED4                                                        */
/************************************************************************/
void app_read_REG_RESERVED4(void) {}
bool app_write_REG_RESERVED4(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_RESERVED4 = reg;
	return true;
}


/************************************************************************/
/* REG_RESERVED5                                                        */
/************************************************************************/
void app_read_REG_RESERVED5(void) {}
bool app_write_REG_RESERVED5(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_RESERVED5 = reg;
	return true;
}


/************************************************************************/
/* REG_SERVO_PERIOD_US                                                  */
/************************************************************************/
void app_read_REG_SERVO_PERIOD_US(void) {}
bool app_write_REG_SERVO_PERIOD_US(void *a)
{
	uint16_t reg = *((uint16_t*)a);
	
	if ((app_regs.REG_EXPANSION_OPTIONS == MSK_SERVO_MOTOR_1) ||
	    (app_regs.REG_EXPANSION_OPTIONS == MSK_SERVO_MOTOR_2) ||
	    (app_regs.REG_EXPANSION_OPTIONS == MSK_SERVO_MOTOR_3))
		{
			TCC0_PER = (reg >> 1) - 1;
		}

	app_regs.REG_SERVO_PERIOD_US = reg;
	return true;
}


/************************************************************************/
/* REG_SERVO0_PULSE_US                                                  */
/************************************************************************/
void app_read_REG_SERVO0_PULSE_US(void) {}
bool app_write_REG_SERVO0_PULSE_US(void *a)
{
	uint16_t reg = *((uint16_t*)a);
	
	if (app_regs.REG_EXPANSION_OPTIONS == MSK_SERVO_MOTOR_1)
		TCC0_CCA = (reg >> 1) - 1;
	
	app_regs.REG_SERVO0_PULSE_US = reg;
	return true;
}


/************************************************************************/
/* REG_SERVO1_PULSE_US                                                  */
/************************************************************************/
void app_read_REG_SERVO1_PULSE_US(void) {}
bool app_write_REG_SERVO1_PULSE_US(void *a)
{
	uint16_t reg = *((uint16_t*)a);
	
	if (app_regs.REG_EXPANSION_OPTIONS == MSK_SERVO_MOTOR_2)
		TCC0_CCB = (reg >> 1) - 1;

	app_regs.REG_SERVO1_PULSE_US = reg;
	return true;
}


/************************************************************************/
/* REG_SERVO2_PULSE_US                                                  */
/************************************************************************/
void app_read_REG_SERVO2_PULSE_US(void) {}
bool app_write_REG_SERVO2_PULSE_US(void *a)
{
	uint16_t reg = *((uint16_t*)a);
	
	if (app_regs.REG_EXPANSION_OPTIONS == MSK_SERVO_MOTOR_3)
		TCC0_CCC = (reg >> 1) - 1;

	app_regs.REG_SERVO2_PULSE_US = reg;
	return true;
}