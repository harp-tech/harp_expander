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
	&app_read_REG_OUTPUTS_SET,
	&app_read_REG_OUTPUTS_CLEAR,
	&app_read_REG_OUTPUTS_TOGGLE,
	&app_read_REG_OUTPUTS_WRITE,
	&app_read_REG_RESERVED0,
	&app_read_REG_RESERVED1,
	&app_read_REG_PWM_AND_STIM_ENABLE,
	&app_read_REG_PWM0_FREQ,
	&app_read_REG_PWM0_DUTYCYCLE,
	&app_read_REG_PWM0_COUNT,
	&app_read_REG_PWM0_REAL_FREQ,
	&app_read_REG_PWM0_REAL_DUTYCYCLE,
	&app_read_REG_PWM0_MODE,
	&app_read_REG_PWM0_TRIG,
	&app_read_REG_PWM0_CONF_EVENT,
	&app_read_REG_PWM1_FREQ,
	&app_read_REG_PWM1_DUTYCYCLE,
	&app_read_REG_PWM1_COUNT,
	&app_read_REG_PWM1_REAL_FREQ,
	&app_read_REG_PWM1_REAL_DUTYCYCLE,
	&app_read_REG_PWM1_MODE,
	&app_read_REG_PWM1_TRIG,
	&app_read_REG_PWM1_CONF_EVENT,
	&app_read_REG_PWM2_FREQ,
	&app_read_REG_PWM2_DUTYCYCLE,
	&app_read_REG_PWM2_COUNT,
	&app_read_REG_PWM2_REAL_FREQ,
	&app_read_REG_PWM2_REAL_DUTYCYCLE,
	&app_read_REG_PWM2_MODE,
	&app_read_REG_PWM2_TRIG,
	&app_read_REG_PWM2_CONF_EVENT,
	&app_read_REG_PWM_START,
	&app_read_REG_PWM_STOP,
	&app_read_REG_PWM_RISE_EVENT,
	&app_read_REG_STIM0_T_ON,
	&app_read_REG_STIM0_T_OFF,
	&app_read_REG_STIM0_COUNT,
	&app_read_REG_STIM0_MODE,
	&app_read_REG_STIM0_TRIG,
	&app_read_REG_STIM_START,
	&app_read_REG_STIM_STOP,
	&app_read_REG_PULSE_ENABLE,
	&app_read_REG_PULSE_OUT0,
	&app_read_REG_PULSE_OUT1,
	&app_read_REG_PULSE_OUT2,
	&app_read_REG_PULSE_OUT3,
	&app_read_REG_PULSE_OUT4,
	&app_read_REG_PULSE_OUT5,
	&app_read_REG_PULSE_OUT6,
	&app_read_REG_PULSE_OUT7,
	&app_read_REG_PULSE_OUT8,
	&app_read_REG_PULSE_OUT9,
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
	&app_write_REG_AUX_INPUTS_RISING_EDGE_ENABLE,
	&app_write_REG_AUX_INPUTS_FALLING_EDGE_ENABLE,
	&app_write_REG_OUTPUTS_SET,
	&app_write_REG_OUTPUTS_CLEAR,
	&app_write_REG_OUTPUTS_TOGGLE,
	&app_write_REG_OUTPUTS_WRITE,
	&app_write_REG_RESERVED0,
	&app_write_REG_RESERVED1,
	&app_write_REG_PWM_AND_STIM_ENABLE,
	&app_write_REG_PWM0_FREQ,
	&app_write_REG_PWM0_DUTYCYCLE,
	&app_write_REG_PWM0_COUNT,
	&app_write_REG_PWM0_REAL_FREQ,
	&app_write_REG_PWM0_REAL_DUTYCYCLE,
	&app_write_REG_PWM0_MODE,
	&app_write_REG_PWM0_TRIG,
	&app_write_REG_PWM0_CONF_EVENT,
	&app_write_REG_PWM1_FREQ,
	&app_write_REG_PWM1_DUTYCYCLE,
	&app_write_REG_PWM1_COUNT,
	&app_write_REG_PWM1_REAL_FREQ,
	&app_write_REG_PWM1_REAL_DUTYCYCLE,
	&app_write_REG_PWM1_MODE,
	&app_write_REG_PWM1_TRIG,
	&app_write_REG_PWM1_CONF_EVENT,
	&app_write_REG_PWM2_FREQ,
	&app_write_REG_PWM2_DUTYCYCLE,
	&app_write_REG_PWM2_COUNT,
	&app_write_REG_PWM2_REAL_FREQ,
	&app_write_REG_PWM2_REAL_DUTYCYCLE,
	&app_write_REG_PWM2_MODE,
	&app_write_REG_PWM2_TRIG,
	&app_write_REG_PWM2_CONF_EVENT,
	&app_write_REG_PWM_START,
	&app_write_REG_PWM_STOP,
	&app_write_REG_PWM_RISE_EVENT,
	&app_write_REG_STIM0_T_ON,
	&app_write_REG_STIM0_T_OFF,
	&app_write_REG_STIM0_COUNT,
	&app_write_REG_STIM0_MODE,
	&app_write_REG_STIM0_TRIG,
	&app_write_REG_STIM_START,
	&app_write_REG_STIM_STOP,
	&app_write_REG_PULSE_ENABLE,
	&app_write_REG_PULSE_OUT0,
	&app_write_REG_PULSE_OUT1,
	&app_write_REG_PULSE_OUT2,
	&app_write_REG_PULSE_OUT3,
	&app_write_REG_PULSE_OUT4,
	&app_write_REG_PULSE_OUT5,
	&app_write_REG_PULSE_OUT6,
	&app_write_REG_PULSE_OUT7,
	&app_write_REG_PULSE_OUT8,
	&app_write_REG_PULSE_OUT9,
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
/* Get decimal divider from prescaler                                   */
/************************************************************************/
uint16_t get_divider(uint8_t prescaler)
{
	switch(prescaler)
	{
		case TIMER_PRESCALER_DIV1: return 1;
		case TIMER_PRESCALER_DIV2: return 2;
		case TIMER_PRESCALER_DIV4: return 4;
		case TIMER_PRESCALER_DIV8: return 8;
		case TIMER_PRESCALER_DIV64: return 64;
		case TIMER_PRESCALER_DIV256: return 256;
		case TIMER_PRESCALER_DIV1024: return 1024;
		default: return 0;
	}
}

uint8_t prescaler0, prescaler1, prescaler2;
uint16_t target_count0, target_count1, target_count2;
uint16_t duty_cycle0, duty_cycle1, duty_cycle2;

uint16_t tcount0, tcount1, tcount2;
uint16_t pwm_and_stim_enable = 0;

bool stop_pwm0, stop_pwm1, stop_pwm2;

/************************************************************************/
/* Calculate real values (frequency and duty cycle)                     */
/************************************************************************/
void update_reals_pwm0(void)
{
	if (calculate_timer_16bits(32000000, app_regs.REG_PWM0_FREQ, &prescaler0, &target_count0))
	{
		app_regs.REG_PWM0_REAL_FREQ = 32000000.0 / ((uint32_t)(get_divider(prescaler0)) * (uint32_t)target_count0);
		app_regs.REG_PWM0_REAL_DUTYCYCLE = 100.0 * ((float)((uint16_t)(app_regs.REG_PWM0_DUTYCYCLE/100.0 * target_count0 + 0.5)) / target_count0);
		duty_cycle0 = app_regs.REG_PWM0_DUTYCYCLE/100.0 * target_count0 + 0.5;
	}
	else
	{
		app_regs.REG_PWM0_REAL_FREQ = 0;
		app_regs.REG_PWM0_REAL_DUTYCYCLE = 0;
	}
}

void update_reals_pwm1(void)
{
	if (calculate_timer_16bits(32000000, app_regs.REG_PWM1_FREQ, &prescaler1, &target_count1))
	{
		app_regs.REG_PWM1_REAL_FREQ = 32000000.0 / ((uint32_t)(get_divider(prescaler1)) * (uint32_t)target_count1);
		app_regs.REG_PWM1_REAL_DUTYCYCLE = 100.0 * ((float)((uint16_t)(app_regs.REG_PWM1_DUTYCYCLE/100.0 * target_count1 + 0.5)) / target_count1);
		duty_cycle1 = app_regs.REG_PWM1_DUTYCYCLE/100.0 * target_count1 + 0.5;
	}
	else
	{
		app_regs.REG_PWM1_REAL_FREQ = 0;
		app_regs.REG_PWM1_REAL_DUTYCYCLE = 0;
	}
}

void update_reals_pwm2(void)
{
	if (calculate_timer_16bits(32000000, app_regs.REG_PWM2_FREQ, &prescaler2, &target_count2))
	{
		app_regs.REG_PWM2_REAL_FREQ = 32000000.0 / ((uint32_t)(get_divider(prescaler2)) * (uint32_t)target_count2);
		app_regs.REG_PWM2_REAL_DUTYCYCLE = 100.0 * ((float)((uint16_t)(app_regs.REG_PWM2_DUTYCYCLE/100.0 * target_count2 + 0.5)) / target_count2);
		duty_cycle2 = app_regs.REG_PWM2_DUTYCYCLE/100.0 * target_count2 + 0.5;
	}
	else
	{
		app_regs.REG_PWM2_REAL_FREQ = 0;
		app_regs.REG_PWM2_REAL_DUTYCYCLE = 0;
	}
}

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
/* REG_PWM_AND_STIM_ENABLE                                              */
/************************************************************************/
void app_read_REG_PWM_AND_STIM_ENABLE(void) {}
bool app_write_REG_PWM_AND_STIM_ENABLE(void *a)
{
	app_regs.REG_PWM_AND_STIM_ENABLE = *((uint16_t*)a);;
	return true;
}


/************************************************************************/
/* REG_PWM0_FREQ                                                        */
/************************************************************************/
void app_read_REG_PWM0_FREQ(void) {}

bool app_write_REG_PWM0_FREQ(void *a)
{
	float reg = *((float*)a);
	
	if (reg > 1000) return false;
	if (reg < 0.5)  return false;	

	app_regs.REG_PWM0_FREQ = reg;
	update_reals_pwm0();
	
	return true;
}


/************************************************************************/
/* REG_PWM0_DUTYCYCLE                                                   */
/************************************************************************/
void app_read_REG_PWM0_DUTYCYCLE(void) {}
bool app_write_REG_PWM0_DUTYCYCLE(void *a)
{
	float reg = *((float*)a);

	if (reg > 100) return false;
	if (reg < 1)   return false;
	
	app_regs.REG_PWM0_DUTYCYCLE = reg;
	update_reals_pwm0();
	
	return true;
}


/************************************************************************/
/* REG_PWM0_COUNT                                                       */
/************************************************************************/
void app_read_REG_PWM0_COUNT(void) {}
bool app_write_REG_PWM0_COUNT(void *a)
{
	uint16_t reg = *((uint16_t*)a);
	
	if (reg < 1) return false;

	app_regs.REG_PWM0_COUNT = reg;
	return true;
}


/************************************************************************/
/* REG_PWM0_REAL_FREQ                                                   */
/************************************************************************/
void app_read_REG_PWM0_REAL_FREQ(void) {}
bool app_write_REG_PWM0_REAL_FREQ(void *a) { return false; }


/************************************************************************/
/* REG_PWM0_REAL_DUTYCYCLE                                              */
/************************************************************************/
void app_read_REG_PWM0_REAL_DUTYCYCLE(void) {}
bool app_write_REG_PWM0_REAL_DUTYCYCLE(void *a) { return false; }


/************************************************************************/
/* REG_PWM0_MODE                                                        */
/************************************************************************/
void app_read_REG_PWM0_MODE(void) {}
bool app_write_REG_PWM0_MODE(void *a)
{
	uint8_t reg = *((uint8_t*)a);
	
	if (~reg & GM_PWM_MODE) return false;

	app_regs.REG_PWM0_MODE = reg;
	return true;
}


/************************************************************************/
/* REG_PWM0_TRIG                                                        */
/************************************************************************/
void app_read_REG_PWM0_TRIG(void) {}
bool app_write_REG_PWM0_TRIG(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_PWM0_TRIG = reg;
	return true;
}


/************************************************************************/
/* REG_PWM0_CONF_EVENT                                                  */
/************************************************************************/
void app_read_REG_PWM0_CONF_EVENT(void) {}
bool app_write_REG_PWM0_CONF_EVENT(void *a)
{
	uint8_t reg = *((uint8_t*)a);
	
	if (~reg & GM_PWM_EVENT) return false;

	app_regs.REG_PWM0_CONF_EVENT = reg;
	return true;
}


/************************************************************************/
/* REG_PWM1_FREQ                                                        */
/************************************************************************/
void app_read_REG_PWM1_FREQ(void) {}
bool app_write_REG_PWM1_FREQ(void *a)
{
	float reg = *((float*)a);
	
	if (reg > 1000) return false;
	if (reg < 0.5)  return false;

	app_regs.REG_PWM1_FREQ = reg;
	update_reals_pwm1();
	
	return true;
}


/************************************************************************/
/* REG_PWM1_DUTYCYCLE                                                   */
/************************************************************************/
void app_read_REG_PWM1_DUTYCYCLE(void) {}
bool app_write_REG_PWM1_DUTYCYCLE(void *a)
{
	float reg = *((float*)a);
	
	if (reg > 100) return false;
	if (reg < 1)   return false;
	
	app_regs.REG_PWM1_DUTYCYCLE = reg;
	update_reals_pwm1();
	
	return true;
}


/************************************************************************/
/* REG_PWM1_COUNT                                                       */
/************************************************************************/
void app_read_REG_PWM1_COUNT(void) {}
bool app_write_REG_PWM1_COUNT(void *a)
{
	uint16_t reg = *((uint16_t*)a);
	
	if (reg < 1) return false;

	app_regs.REG_PWM1_COUNT = reg;
	return true;
}


/************************************************************************/
/* REG_PWM1_REAL_FREQ                                                   */
/************************************************************************/
void app_read_REG_PWM1_REAL_FREQ(void) {}
bool app_write_REG_PWM1_REAL_FREQ(void *a) { return false; }


/************************************************************************/
/* REG_PWM1_REAL_DUTYCYCLE                                              */
/************************************************************************/
void app_read_REG_PWM1_REAL_DUTYCYCLE(void) {}
bool app_write_REG_PWM1_REAL_DUTYCYCLE(void *a) { return false; }


/************************************************************************/
/* REG_PWM1_MODE                                                        */
/************************************************************************/
void app_read_REG_PWM1_MODE(void) {}
bool app_write_REG_PWM1_MODE(void *a)
{
	uint8_t reg = *((uint8_t*)a);
	
	if (~reg & GM_PWM_MODE) return false;

	app_regs.REG_PWM1_MODE = reg;
	return true;
}


/************************************************************************/
/* REG_PWM1_TRIG                                                        */
/************************************************************************/
void app_read_REG_PWM1_TRIG(void) {}
bool app_write_REG_PWM1_TRIG(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_PWM1_TRIG = reg;
	return true;
}


/************************************************************************/
/* REG_PWM1_CONF_EVENT                                                  */
/************************************************************************/
void app_read_REG_PWM1_CONF_EVENT(void) {}
bool app_write_REG_PWM1_CONF_EVENT(void *a)
{
	uint8_t reg = *((uint8_t*)a);
	
	if (~reg & GM_PWM_EVENT) return false;

	app_regs.REG_PWM1_CONF_EVENT = reg;
	return true;
}


/************************************************************************/
/* REG_PWM2_FREQ                                                        */
/************************************************************************/
void app_read_REG_PWM2_FREQ(void) {}
bool app_write_REG_PWM2_FREQ(void *a)
{
	float reg = *((float*)a);
	
	if (reg > 1000) return false;
	if (reg < 0.5)  return false;

	app_regs.REG_PWM2_FREQ = reg;
	update_reals_pwm2();
	
	return true;
}


/************************************************************************/
/* REG_PWM2_DUTYCYCLE                                                   */
/************************************************************************/
void app_read_REG_PWM2_DUTYCYCLE(void) {}
bool app_write_REG_PWM2_DUTYCYCLE(void *a)
{
	float reg = *((float*)a);
	
	if (reg > 100) return false;
	if (reg < 1)   return false;

	app_regs.REG_PWM2_DUTYCYCLE = reg;
	update_reals_pwm2();
	
	return true;
}


/************************************************************************/
/* REG_PWM2_COUNT                                                       */
/************************************************************************/
void app_read_REG_PWM2_COUNT(void) {}
bool app_write_REG_PWM2_COUNT(void *a)
{
	uint16_t reg = *((uint16_t*)a);
	
	if (reg < 1) return false;
	
	app_regs.REG_PWM2_COUNT = reg;
	return true;
}


/************************************************************************/
/* REG_PWM2_REAL_FREQ                                                   */
/************************************************************************/
void app_read_REG_PWM2_REAL_FREQ(void) {}
bool app_write_REG_PWM2_REAL_FREQ(void *a) { return false; }


/************************************************************************/
/* REG_PWM2_REAL_DUTYCYCLE                                              */
/************************************************************************/
void app_read_REG_PWM2_REAL_DUTYCYCLE(void) {}
bool app_write_REG_PWM2_REAL_DUTYCYCLE(void *a) { return false; }


/************************************************************************/
/* REG_PWM2_MODE                                                        */
/************************************************************************/
void app_read_REG_PWM2_MODE(void) {}
bool app_write_REG_PWM2_MODE(void *a)
{
	uint8_t reg = *((uint8_t*)a);
	
	if (~reg & GM_PWM_MODE) return false;

	app_regs.REG_PWM2_MODE = reg;
	return true;
}


/************************************************************************/
/* REG_PWM2_TRIG                                                        */
/************************************************************************/
void app_read_REG_PWM2_TRIG(void) {}
bool app_write_REG_PWM2_TRIG(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_PWM2_TRIG = reg;
	return true;
}


/************************************************************************/
/* REG_PWM2_CONF_EVENT                                                  */
/************************************************************************/
void app_read_REG_PWM2_CONF_EVENT(void) {}
bool app_write_REG_PWM2_CONF_EVENT(void *a)
{
	uint8_t reg = *((uint8_t*)a);
	
	if (~reg & GM_PWM_EVENT) return false;

	app_regs.REG_PWM2_CONF_EVENT = reg;
	return true;
}


/************************************************************************/
/* REG_PWM_START                                                        */
/************************************************************************/
void app_read_REG_PWM_START(void) {}
bool app_write_REG_PWM_START(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	bool start_pwm0 = false;
	bool start_pwm1 = false;
	bool start_pwm2 = false;
		
	if (reg & B_PWM0)
	{
		tcount0 = app_regs.REG_PWM0_COUNT;
			
		TCD0_CTRLA = TC_CLKSEL_OFF_gc;		// Make sure timer is stopped to make reset
		TCD0_CTRLFSET = TC_CMD_RESET_gc;	// Timer reset (registers to initial value)
		TCD0_PER = target_count0 - 1;		// Set up target
		TCD0_CCA = duty_cycle0;				// Set duty cycle A
		TCD0_CCB = duty_cycle0;				// Set duty cycle B
		TCD0_CCC = duty_cycle0;				// Set duty cycle C
		TCD0_CCD = duty_cycle0;				// Set duty cycle D
		TCD0_INTCTRLA = INT_LEVEL_LOW;		// Interrupt overflow
		TCD0_INTCTRLB = INT_LEVEL_LOW;		// Interrupt prescaler A
		TCD0_CTRLB = TC_WGMODE_SINGLESLOPE_gc;	// Enable single slope mode
		
		if (app_regs.REG_PWM_AND_STIM_ENABLE & B_PWM0_EN_OUT1)
		{
			start_pwm0 = true;
			TCD0_CTRLB |= TC0_CCDEN_bm;		// Enable channel D
			pwm_and_stim_enable |= B_PWM0_EN_OUT1;
		}
		if (app_regs.REG_PWM_AND_STIM_ENABLE & B_PWM0_EN_OUT2)
		{
			start_pwm0 = true;
			TCD0_CTRLB |= TC0_CCCEN_bm;		// Enable channel C
			pwm_and_stim_enable |= B_PWM0_EN_OUT2;
		}
		if (app_regs.REG_PWM_AND_STIM_ENABLE & B_PWM0_EN_OUT3)
		{
			start_pwm0 = true;
			TCD0_CTRLB |= TC0_CCBEN_bm;		// Enable channel B
			pwm_and_stim_enable |= B_PWM0_EN_OUT3;
		}
	}
				
	if (reg & B_PWM1)
	{
		tcount1 = app_regs.REG_PWM1_COUNT;
			
		TCC0_CTRLA = TC_CLKSEL_OFF_gc;		// Make sure timer is stopped to make reset
		TCC0_CTRLFSET = TC_CMD_RESET_gc;	// Timer reset (registers to initial value)
		TCC0_PER = target_count1 - 1;		// Set up target
		TCC0_CCA = duty_cycle1;				// Set duty cycle A
		TCC0_CCB = duty_cycle1;				// Set duty cycle B
		TCC0_CCC = duty_cycle1;				// Set duty cycle C
		TCC0_CCD = duty_cycle1;				// Set duty cycle D
		TCC0_INTCTRLA = INT_LEVEL_LOW;		// Interrupt overflow
		TCC0_INTCTRLB = INT_LEVEL_LOW;		// Interrupt prescaler A
		TCC0_CTRLB = TC_WGMODE_SINGLESLOPE_gc;	// Enable single slope mode
				
		if (app_regs.REG_PWM_AND_STIM_ENABLE & B_PWM1_EN_OUT6 && (
			(app_regs.REG_EXPANSION_OPTIONS == MSK_BREAKOUT)
			))
			{
				start_pwm1 = true;
				TCC0_CTRLB |= TC0_CCBEN_bm;	// Enable channel B
				pwm_and_stim_enable |= B_PWM1_EN_OUT6;
			}
		   
		if (app_regs.REG_PWM_AND_STIM_ENABLE & B_PWM1_EN_OUT7 && (
			(app_regs.REG_EXPANSION_OPTIONS == MSK_BREAKOUT) ||
			(app_regs.REG_EXPANSION_OPTIONS == MSK_MAGNETIC_ENCODER)
			))
			{
				start_pwm1 = true;
				TCC0_CTRLB |= TC0_CCCEN_bm;	// Enable channel C
				pwm_and_stim_enable |= B_PWM1_EN_OUT7;
			}
		if (app_regs.REG_PWM_AND_STIM_ENABLE & B_PWM1_EN_OUT8 && (
			(app_regs.REG_EXPANSION_OPTIONS == MSK_BREAKOUT) ||
			(app_regs.REG_EXPANSION_OPTIONS == MSK_MAGNETIC_ENCODER)
			))
			{
				start_pwm1 = true;
				TCC0_CTRLB |= TC0_CCDEN_bm;	// Enable channel D
				pwm_and_stim_enable |= B_PWM1_EN_OUT8;
			}
	}

	if (reg & B_PWM2)
	{
		tcount2 = app_regs.REG_PWM2_COUNT;
			
		TCE0_CTRLA = TC_CLKSEL_OFF_gc;		// Make sure timer is stopped to make reset
		TCE0_CTRLFSET = TC_CMD_RESET_gc;	// Timer reset (registers to initial value)
		TCE0_PER = target_count2 - 1;		// Set up target
		TCE0_CCA = duty_cycle2;				// Set duty cycle A		
		TCE0_INTCTRLA = INT_LEVEL_LOW;		// Interrupt overflow
		TCE0_INTCTRLB = INT_LEVEL_LOW;		// Interrupt prescaler A
		TCE0_CTRLB = TC_WGMODE_SINGLESLOPE_gc;	// Enable single slope mode
		
		if (app_regs.REG_PWM_AND_STIM_ENABLE & B_PWM2_EN_OUT9 && (
			(app_regs.REG_EXPANSION_OPTIONS == MSK_BREAKOUT) ||
			(app_regs.REG_EXPANSION_OPTIONS == MSK_SERVO_MOTOR_1) ||
			(app_regs.REG_EXPANSION_OPTIONS == MSK_SERVO_MOTOR_2) ||
			(app_regs.REG_EXPANSION_OPTIONS == MSK_SERVO_MOTOR_3)
			))
			{
				start_pwm2 = true;
				TCE0_CTRLB |= TC0_CCAEN_bm;	// Enable channel A				
				pwm_and_stim_enable |= B_PWM2_EN_OUT9;
			}
	}
		
	if (start_pwm0) { TCD0_CTRLA = prescaler0; stop_pwm0 = false; }
	if (start_pwm1) { TCC0_CTRLA = prescaler1; stop_pwm1 = false; }
	if (start_pwm2) { TCE0_CTRLA = prescaler2; stop_pwm2 = false; }
	
	app_regs.REG_PWM_START = reg;
	return true;
}


/************************************************************************/
/* REG_PWM_STOP                                                         */
/************************************************************************/
void app_read_REG_PWM_STOP(void) {}
bool app_write_REG_PWM_STOP(void *a)
{
	uint8_t reg = *((uint8_t*)a);
	
	if (reg & B_PWM0) stop_pwm0 = true;
	if (reg & B_PWM1) stop_pwm1 = true;
	if (reg & B_PWM2) stop_pwm2 = true;

	app_regs.REG_PWM_STOP = reg;
	return true;
}


/************************************************************************/
/* REG_PWM_RISE_EVENT                                                   */
/************************************************************************/
void app_read_REG_PWM_RISE_EVENT(void) {}
bool app_write_REG_PWM_RISE_EVENT(void *a) { return false; }


/************************************************************************/
/* REG_STIM0_T_ON                                                */
/************************************************************************/
void app_read_REG_STIM0_T_ON(void) {}
bool app_write_REG_STIM0_T_ON(void *a)
{
	uint16_t reg = *((uint16_t*)a);
	
	if (reg < 1) return false;

	app_regs.REG_STIM0_T_ON = reg;
	return true;
}


/************************************************************************/
/* REG_STIM0_T_OFF                                               */
/************************************************************************/
void app_read_REG_STIM0_T_OFF(void) {}
bool app_write_REG_STIM0_T_OFF(void *a)
{
	uint16_t reg = *((uint16_t*)a);
	
	if (reg < 1) return false;

	app_regs.REG_STIM0_T_OFF = reg;
	return true;
}


/************************************************************************/
/* REG_STIM0_COUNT                                               */
/************************************************************************/
void app_read_REG_STIM0_COUNT(void) {}
bool app_write_REG_STIM0_COUNT(void *a)
{
	uint16_t reg = *((uint16_t*)a);

	if (reg < 1) return false;

	app_regs.REG_STIM0_COUNT = reg;
	return true;
}


/************************************************************************/
/* REG_STIM0_MODE                                                */
/************************************************************************/
void app_read_REG_STIM0_MODE(void) {}
bool app_write_REG_STIM0_MODE(void *a)
{
	uint8_t reg = *((uint8_t*)a);
	
	if (~reg & GM_STIM_MODE) return false;

	app_regs.REG_STIM0_MODE = reg;
	return true;
}


/************************************************************************/
/* REG_STIM0_TRIG                                                */
/************************************************************************/
void app_read_REG_STIM0_TRIG(void) {}
bool app_write_REG_STIM0_TRIG(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_STIM0_TRIG = reg;
	return true;
}


/************************************************************************/
/* REG_STIM_START                                                       */
/************************************************************************/
void app_read_REG_STIM_START(void) {}
bool app_write_REG_STIM_START(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	// Verificar se o app_regs.REG_EXPANSION_OPTIONS permite (apenas no OUT5)
	/*
	STIM0 TCE0
	0
	5
	*/

	app_regs.REG_STIM_START = reg;
	return true;
}


/************************************************************************/
/* REG_STIM_STOP                                                        */
/************************************************************************/
void app_read_REG_STIM_STOP(void) {}
bool app_write_REG_STIM_STOP(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_STIM_STOP = reg;
	return true;
}


/************************************************************************/
/* REG_PULSE_ENABLE                                                     */
/************************************************************************/
void app_read_REG_PULSE_ENABLE(void) {}
bool app_write_REG_PULSE_ENABLE(void *a)
{
	app_regs.REG_PULSE_ENABLE = *((uint16_t*)a);
	return true;
}


/************************************************************************/
/* REG_PULSE_OUT0                                                       */
/************************************************************************/
void app_read_REG_PULSE_OUT0(void) {}
bool app_write_REG_PULSE_OUT0(void *a)
{
	app_regs.REG_PULSE_OUT0 = *((uint16_t*)a);
	return true;
}


/************************************************************************/
/* REG_PULSE_OUT1                                                       */
/************************************************************************/
void app_read_REG_PULSE_OUT1(void) {}
bool app_write_REG_PULSE_OUT1(void *a)
{
	app_regs.REG_PULSE_OUT1 = *((uint16_t*)a);
	return true;
}


/************************************************************************/
/* REG_PULSE_OUT2                                                       */
/************************************************************************/
void app_read_REG_PULSE_OUT2(void) {}
bool app_write_REG_PULSE_OUT2(void *a)
{
	app_regs.REG_PULSE_OUT2 = *((uint16_t*)a);
	return true;
}


/************************************************************************/
/* REG_PULSE_OUT3                                                       */
/************************************************************************/
void app_read_REG_PULSE_OUT3(void) {}
bool app_write_REG_PULSE_OUT3(void *a)
{
	app_regs.REG_PULSE_OUT3 = *((uint16_t*)a);
	return true;
}


/************************************************************************/
/* REG_PULSE_OUT4                                                       */
/************************************************************************/
void app_read_REG_PULSE_OUT4(void) {}
bool app_write_REG_PULSE_OUT4(void *a)
{
	app_regs.REG_PULSE_OUT4 = *((uint16_t*)a);
	return true;
}


/************************************************************************/
/* REG_PULSE_OUT5                                                       */
/************************************************************************/
void app_read_REG_PULSE_OUT5(void) {}
bool app_write_REG_PULSE_OUT5(void *a)
{
	app_regs.REG_PULSE_OUT5 = *((uint16_t*)a);
	return true;
}


/************************************************************************/
/* REG_PULSE_OUT6                                                       */
/************************************************************************/
void app_read_REG_PULSE_OUT6(void) {}
bool app_write_REG_PULSE_OUT6(void *a)
{
	app_regs.REG_PULSE_OUT6 = *((uint16_t*)a);
	return true;
}


/************************************************************************/
/* REG_PULSE_OUT7                                                       */
/************************************************************************/
void app_read_REG_PULSE_OUT7(void) {}
bool app_write_REG_PULSE_OUT7(void *a)
{
	app_regs.REG_PULSE_OUT7 = *((uint16_t*)a);
	return true;
}


/************************************************************************/
/* REG_PULSE_OUT8                                                       */
/************************************************************************/
void app_read_REG_PULSE_OUT8(void) {}
bool app_write_REG_PULSE_OUT8(void *a)
{
	app_regs.REG_PULSE_OUT8 = *((uint16_t*)a);
	return true;
}


/************************************************************************/
/* REG_PULSE_OUT9                                                       */
/************************************************************************/
void app_read_REG_PULSE_OUT9(void) {}
bool app_write_REG_PULSE_OUT9(void *a)
{
	app_regs.REG_PULSE_OUT9 = *((uint16_t*)a);
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
			io_set_int(&PORTE, INT_LEVEL_LOW, 0, (1<<2), false);	// Add AUX_INPUT0 to interrupt on PORTE INT N=0
			io_set_int(&PORTE, INT_LEVEL_LOW, 0, (1<<5), false);	// Add AUX_INPUT1 to interrupt on PORTE INT N=0
		
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
			TCC0_CCA = (app_regs.REG_SERVO0_PULSE_US >> 1);			// Set duty cycle A			
			TCC0_CTRLB = TC0_CCAEN_bm | TC_WGMODE_SINGLESLOPE_gc;	// Enable channel A and single slope mode
			TCC0_CTRLA = TIMER_PRESCALER_DIV64;						// Start timer
			break;
		
		case MSK_SERVO_MOTOR_2:
			io_set_int(&PORTE, INT_LEVEL_LOW, 0, (1<<2), false);	// Add AUX_INPUT0 to interrupt on PORTE INT N=0
			io_set_int(&PORTE, INT_LEVEL_LOW, 0, (1<<5), false);	// Add AUX_INPUT1 to interrupt on PORTE INT N=0
		
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
			TCC0_CCA = (app_regs.REG_SERVO0_PULSE_US >> 1);			// Set duty cycle A
			TCC0_CCB = (app_regs.REG_SERVO1_PULSE_US >> 1);			// Set duty cycle B			
			TCC0_CTRLB = TC0_CCAEN_bm | TC_WGMODE_SINGLESLOPE_gc;	// Enable channel A and single slope mode
			TCC0_CTRLB |= TC0_CCBEN_bm;								// Enable channel B			
			TCC0_CTRLA = TIMER_PRESCALER_DIV64;						// Start timer			
			break;
		
		case MSK_SERVO_MOTOR_3:
			io_set_int(&PORTE, INT_LEVEL_LOW, 0, (1<<2), false);	// Add AUX_INPUT0 to interrupt on PORTE INT N=0
			io_set_int(&PORTE, INT_LEVEL_LOW, 0, (1<<5), false);	// Add AUX_INPUT1 to interrupt on PORTE INT N=0
			
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
			TCC0_CCA = (app_regs.REG_SERVO0_PULSE_US >> 1);		// Set duty cycle A
			TCC0_CCB = (app_regs.REG_SERVO1_PULSE_US >> 1);		// Set duty cycle B
			TCC0_CCC = (app_regs.REG_SERVO2_PULSE_US >> 1);		// Set duty cycle C			
			TCC0_CTRLB = TC0_CCAEN_bm | TC_WGMODE_SINGLESLOPE_gc;	// Enable channel A and single slope mode
			TCC0_CTRLB |= TC0_CCBEN_bm;								// Enable channel B
			TCC0_CTRLB |= TC0_CCCEN_bm;								// Enable channel C			
			TCC0_CTRLA = TIMER_PRESCALER_DIV64;						// Start timer			
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
	
	if ((app_regs.REG_EXPANSION_OPTIONS == MSK_SERVO_MOTOR_1) ||
		(app_regs.REG_EXPANSION_OPTIONS == MSK_SERVO_MOTOR_2) ||
		(app_regs.REG_EXPANSION_OPTIONS == MSK_SERVO_MOTOR_3))
		{
			TCC0_CCA = (reg >> 1);
		}
	
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
	
	if ((app_regs.REG_EXPANSION_OPTIONS == MSK_SERVO_MOTOR_2) ||
		(app_regs.REG_EXPANSION_OPTIONS == MSK_SERVO_MOTOR_3))
		{	
			TCC0_CCB = (reg >> 1);
		}

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
		TCC0_CCC = (reg >> 1);

	app_regs.REG_SERVO2_PULSE_US = reg;
	return true;
}