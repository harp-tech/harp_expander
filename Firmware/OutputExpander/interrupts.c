#include "cpu.h"
#include "hwbp_core_types.h"
#include "app_ios_and_regs.h"
#include "app_funcs.h"
#include "hwbp_core.h"

/************************************************************************/
/* Declare application registers                                        */
/************************************************************************/
extern AppRegs app_regs;

/************************************************************************/
/* Interrupts from Timers                                               */
/************************************************************************/
// ISR(TCC0_OVF_vect, ISR_NAKED)
// ISR(TCD0_OVF_vect, ISR_NAKED)
// ISR(TCE0_OVF_vect, ISR_NAKED)
// ISR(TCF0_OVF_vect, ISR_NAKED)
// 
// ISR(TCC0_CCA_vect, ISR_NAKED)
// ISR(TCD0_CCA_vect, ISR_NAKED)
// ISR(TCE0_CCA_vect, ISR_NAKED)
// ISR(TCF0_CCA_vect, ISR_NAKED)
// 
// ISR(TCD1_OVF_vect, ISR_NAKED)
// 
// ISR(TCD1_CCA_vect, ISR_NAKED)

/************************************************************************/ 
/* AUX_INPUT0-1                                                         */
/************************************************************************/
uint8_t aux_inputs_previous_read = 0;

#define startPWM(a) app_regs.REG_PWM_START = a; \
                    app_write_REG_PWM_START(&app_regs.REG_PWM_START)
					
#define stopPWM(a)  app_regs.REG_PWM_STOP  = a; \
                    app_write_REG_PWM_STOP(&app_regs.REG_PWM_STOP)

ISR(PORTE_INT0_vect, ISR_NAKED)
{
	uint8_t aux_inputs_current_read = (read_AUX_INPUT0 ? B_AUX_IN0 : 0) | (read_AUX_INPUT1 ? B_AUX_IN1 : 0);
	
	app_regs.REG_AUX_INPUTS = 0;
	
	if ((aux_inputs_current_read ^ aux_inputs_previous_read) & B_AUX_IN0) { app_regs.REG_AUX_INPUTS |= B_AUX_IN0_CHANGE_MSK; }
	if ((aux_inputs_current_read ^ aux_inputs_previous_read) & B_AUX_IN1) { app_regs.REG_AUX_INPUTS |= B_AUX_IN1_CHANGE_MSK; }
	
	if (app_regs.REG_AUX_INPUTS)
	{
		app_regs.REG_AUX_INPUTS |= (aux_inputs_current_read & (B_AUX_IN0 | B_AUX_IN1));
						
		if ((app_regs.REG_PWM0_TRIG & GM_PWM_TRIG_AUX0) && (app_regs.REG_AUX_INPUTS & B_AUX_IN0_CHANGE_MSK)) {
			if (app_regs.REG_AUX_INPUTS & B_AUX_IN0) {
				switch (app_regs.REG_PWM0_TRIG) {
					case MSK_STIM_TRIG_AUX0_RISE_START:
					case MSK_STIM_TRIG_AUX0_ON_WHILE_HIGH: startPWM(B_PWM0); break;						
					case MSK_STIM_TRIG_AUX0_ON_WHILE_LOW:  stopPWM (B_PWM0); break;
				}
			} else {
				switch (app_regs.REG_PWM0_TRIG) {
					case MSK_STIM_TRIG_AUX0_FALL_START:
					case MSK_STIM_TRIG_AUX0_ON_WHILE_LOW:  startPWM(B_PWM0); break;
					case MSK_STIM_TRIG_AUX0_ON_WHILE_HIGH: stopPWM (B_PWM0); break;
		}	}	}
			
		if ((app_regs.REG_PWM0_TRIG & GM_PWM_TRIG_AUX1) && (app_regs.REG_AUX_INPUTS & B_AUX_IN1_CHANGE_MSK)) {
			if (app_regs.REG_AUX_INPUTS & B_AUX_IN1) {
				switch (app_regs.REG_PWM0_TRIG) {
					case MSK_STIM_TRIG_AUX1_RISE_START:
					case MSK_STIM_TRIG_AUX1_ON_WHILE_HIGH: startPWM(B_PWM0); break;						
					case MSK_STIM_TRIG_AUX1_ON_WHILE_LOW:  stopPWM (B_PWM0); break;
				}
			} else {
				switch (app_regs.REG_PWM0_TRIG) {
					case MSK_STIM_TRIG_AUX1_FALL_START:
					case MSK_STIM_TRIG_AUX1_ON_WHILE_LOW:  startPWM(B_PWM0); break;
					case MSK_STIM_TRIG_AUX1_ON_WHILE_HIGH: stopPWM (B_PWM0); break;
		}	}	}
			
		if ((app_regs.REG_PWM1_TRIG & GM_PWM_TRIG_AUX0) && (app_regs.REG_AUX_INPUTS & B_AUX_IN0_CHANGE_MSK)) {
			if (app_regs.REG_AUX_INPUTS & B_AUX_IN0) {
				switch (app_regs.REG_PWM1_TRIG) {
					case MSK_STIM_TRIG_AUX0_RISE_START:
					case MSK_STIM_TRIG_AUX0_ON_WHILE_HIGH: startPWM(B_PWM1); break;						
					case MSK_STIM_TRIG_AUX0_ON_WHILE_LOW:  stopPWM (B_PWM1); break;
				}
			} else {
				switch (app_regs.REG_PWM1_TRIG) {
					case MSK_STIM_TRIG_AUX0_FALL_START:
					case MSK_STIM_TRIG_AUX0_ON_WHILE_LOW:  startPWM(B_PWM1); break;
					case MSK_STIM_TRIG_AUX0_ON_WHILE_HIGH: stopPWM (B_PWM1); break;
		}	}	}
			
		if ((app_regs.REG_PWM1_TRIG & GM_PWM_TRIG_AUX1) && (app_regs.REG_AUX_INPUTS & B_AUX_IN1_CHANGE_MSK)) {
			if (app_regs.REG_AUX_INPUTS & B_AUX_IN1) {
				switch (app_regs.REG_PWM1_TRIG) {
					case MSK_STIM_TRIG_AUX1_RISE_START:
					case MSK_STIM_TRIG_AUX1_ON_WHILE_HIGH: startPWM(B_PWM1); break;						
					case MSK_STIM_TRIG_AUX1_ON_WHILE_LOW:  stopPWM (B_PWM1); break;
				}
			} else {
				switch (app_regs.REG_PWM1_TRIG) {
					case MSK_STIM_TRIG_AUX1_FALL_START:
					case MSK_STIM_TRIG_AUX1_ON_WHILE_LOW:  startPWM(B_PWM1); break;
					case MSK_STIM_TRIG_AUX1_ON_WHILE_HIGH: stopPWM (B_PWM1); break;
		}	}	}
			
		if ((app_regs.REG_PWM2_TRIG & GM_PWM_TRIG_AUX0) && (app_regs.REG_AUX_INPUTS & B_AUX_IN0_CHANGE_MSK)) {
			if (app_regs.REG_AUX_INPUTS & B_AUX_IN0) {
				switch (app_regs.REG_PWM2_TRIG) {
					case MSK_STIM_TRIG_AUX0_RISE_START:
					case MSK_STIM_TRIG_AUX0_ON_WHILE_HIGH: startPWM(B_PWM2); break;						
					case MSK_STIM_TRIG_AUX0_ON_WHILE_LOW:  stopPWM (B_PWM2); break;
				}
			} else {
				switch (app_regs.REG_PWM2_TRIG) {
					case MSK_STIM_TRIG_AUX0_FALL_START:
					case MSK_STIM_TRIG_AUX0_ON_WHILE_LOW:  startPWM(B_PWM2); break;
					case MSK_STIM_TRIG_AUX0_ON_WHILE_HIGH: stopPWM (B_PWM2); break;
		}	}	}
			
		if ((app_regs.REG_PWM2_TRIG & GM_PWM_TRIG_AUX1) && (app_regs.REG_AUX_INPUTS & B_AUX_IN1_CHANGE_MSK)) {
			if (app_regs.REG_AUX_INPUTS & B_AUX_IN1) {
				switch (app_regs.REG_PWM2_TRIG) {
					case MSK_STIM_TRIG_AUX1_RISE_START:
					case MSK_STIM_TRIG_AUX1_ON_WHILE_HIGH: startPWM(B_PWM2); break;						
					case MSK_STIM_TRIG_AUX1_ON_WHILE_LOW:  stopPWM (B_PWM2); break;
				}
			} else {
				switch (app_regs.REG_PWM2_TRIG) {
					case MSK_STIM_TRIG_AUX1_FALL_START:
					case MSK_STIM_TRIG_AUX1_ON_WHILE_LOW:  startPWM(B_PWM2); break;
					case MSK_STIM_TRIG_AUX1_ON_WHILE_HIGH: stopPWM (B_PWM2); break;
		}	}	}
		
		if ((((app_regs.REG_AUX_INPUTS >> 4) & 3) &  (app_regs.REG_AUX_INPUTS & 3) & app_regs.REG_AUX_INPUTS_RISING_EDGE_ENABLE) ||
		   (((app_regs.REG_AUX_INPUTS >> 4) & 3) & ~(app_regs.REG_AUX_INPUTS & 3) & app_regs.REG_AUX_INPUTS_FALLING_EDGE_ENABLE))
		{	
			core_func_send_event(ADD_REG_AUX_INPUTS, true);
		}
	}
	
	aux_inputs_previous_read = aux_inputs_current_read;
	
	reti();
}

/************************************************************************/
/* PWM0                                                                 */
/************************************************************************/
extern uint16_t pwm_and_stim_enable;
extern uint16_t tcount0, tcount1, tcount2;
extern bool stop_pwm0, stop_pwm1, stop_pwm2;

ISR(TCD0_OVF_vect, ISR_NAKED)
{
	if (app_regs.REG_PWM0_CONF_EVENT == MSK_PWM_RISE_EVENT_EN)
	{
		app_regs.REG_PWM_RISE_EVENT = B_PWM0;
		core_func_send_event(ADD_REG_PWM_RISE_EVENT, true);
	}

	if (core_bool_is_visual_enabled())
	{
		if (pwm_and_stim_enable & B_PWM0_EN_OUT1) set_LED_1;
		if (pwm_and_stim_enable & B_PWM0_EN_OUT2) set_LED_2;
		if (pwm_and_stim_enable & B_PWM0_EN_OUT3) set_LED_3;
	}
	reti();
}

ISR(TCD0_CCA_vect, ISR_NAKED)
{
	if (core_bool_is_visual_enabled())
	{
		if (pwm_and_stim_enable & B_PWM0_EN_OUT1) clr_LED_1;
		if (pwm_and_stim_enable & B_PWM0_EN_OUT2) clr_LED_2;
		if (pwm_and_stim_enable & B_PWM0_EN_OUT3) clr_LED_3;
	}
	
	if (stop_pwm0)
	{
		if (pwm_and_stim_enable & B_PWM0_EN_OUT1) clr_OUT1;
		if (pwm_and_stim_enable & B_PWM0_EN_OUT2) clr_OUT2;
		if (pwm_and_stim_enable & B_PWM0_EN_OUT3) clr_OUT3;
		
		pwm_and_stim_enable &= ~(B_PWM0_EN_OUT1 | B_PWM0_EN_OUT2 |B_PWM0_EN_OUT3);
		
		timer_type0_stop(&TCD0);
	}
		
	if (app_regs.REG_PWM0_MODE == MSK_PWM_MODE_COUNT)
	{
		if (--tcount0 == 0)
		{
			if (pwm_and_stim_enable & B_PWM0_EN_OUT1) clr_OUT1;
			if (pwm_and_stim_enable & B_PWM0_EN_OUT2) clr_OUT2;
			if (pwm_and_stim_enable & B_PWM0_EN_OUT3) clr_OUT3;
			
			pwm_and_stim_enable &= ~(B_PWM0_EN_OUT1 | B_PWM0_EN_OUT2 |B_PWM0_EN_OUT3);
			
			timer_type0_stop(&TCD0);
		}
	}
	reti();
}

/************************************************************************/
/* PWM1                                                                 */
/************************************************************************/
ISR(TCC0_OVF_vect, ISR_NAKED)
{
	if (app_regs.REG_PWM1_CONF_EVENT == MSK_PWM_RISE_EVENT_EN)
	{
		app_regs.REG_PWM_RISE_EVENT = B_PWM1;
		core_func_send_event(ADD_REG_PWM_RISE_EVENT, true);
	}

	if (core_bool_is_visual_enabled())
	{
		if (pwm_and_stim_enable & B_PWM1_EN_OUT6) set_LED_6;
		if (pwm_and_stim_enable & B_PWM1_EN_OUT7) set_LED_7;
		if (pwm_and_stim_enable & B_PWM1_EN_OUT8) set_LED_8;
	}
	reti();
}

ISR(TCC0_CCA_vect, ISR_NAKED)
{
	if (core_bool_is_visual_enabled())
	{
		if (pwm_and_stim_enable & B_PWM1_EN_OUT6) clr_LED_6;
		if (pwm_and_stim_enable & B_PWM1_EN_OUT7) clr_LED_7;
		if (pwm_and_stim_enable & B_PWM1_EN_OUT8) clr_LED_8;
	}
	
	if (stop_pwm1)
	{
		if (pwm_and_stim_enable & B_PWM1_EN_OUT6) clr_OUT6;
		if (pwm_and_stim_enable & B_PWM1_EN_OUT7) clr_OUT7;
		if (pwm_and_stim_enable & B_PWM1_EN_OUT8) clr_OUT8;
		
		pwm_and_stim_enable &= ~(B_PWM1_EN_OUT6 | B_PWM1_EN_OUT7 | B_PWM1_EN_OUT8);
		
		timer_type0_stop(&TCC0);
	}
	
	if (app_regs.REG_PWM1_MODE == MSK_PWM_MODE_COUNT)
	{
		if (--tcount1 == 0)
		{
			if (pwm_and_stim_enable & B_PWM1_EN_OUT6) clr_OUT6;
			if (pwm_and_stim_enable & B_PWM1_EN_OUT7) clr_OUT7;
			if (pwm_and_stim_enable & B_PWM1_EN_OUT8) clr_OUT8;
			
			pwm_and_stim_enable &= ~(B_PWM1_EN_OUT6 | B_PWM1_EN_OUT7 | B_PWM1_EN_OUT8);
			
			timer_type0_stop(&TCC0);
		}
	}
	reti();
}

/************************************************************************/
/* PWM2                                                                 */
/************************************************************************/
ISR(TCE0_OVF_vect, ISR_NAKED)
{
	if (app_regs.REG_PWM2_CONF_EVENT == MSK_PWM_RISE_EVENT_EN)
	{
		app_regs.REG_PWM_RISE_EVENT = B_PWM2;
		core_func_send_event(ADD_REG_PWM_RISE_EVENT, true);
	}

	if (core_bool_is_visual_enabled())
	{
		if (pwm_and_stim_enable & B_PWM2_EN_OUT9) set_LED_9;
	}
	reti();
}

ISR(TCE0_CCA_vect, ISR_NAKED)
{
	if (core_bool_is_visual_enabled())
	{
		if (pwm_and_stim_enable & B_PWM2_EN_OUT9) clr_LED_9;
	}
	
	if (stop_pwm2)
	{
		if (pwm_and_stim_enable & B_PWM2_EN_OUT9) clr_OUT9;
		
		pwm_and_stim_enable &= ~(B_PWM2_EN_OUT9);
		
		timer_type0_stop(&TCE0);
	}
	
	if (app_regs.REG_PWM2_MODE == MSK_PWM_MODE_COUNT)
	{
		if (--tcount2 == 0)
		{
			if (pwm_and_stim_enable & B_PWM2_EN_OUT9) clr_OUT9;
			
			pwm_and_stim_enable &= ~(B_PWM2_EN_OUT9);
			
			timer_type0_stop(&TCE0);
		}
	}
	reti();
}