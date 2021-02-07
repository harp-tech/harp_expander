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
/* Local functions                                                      */
/************************************************************************/
uint16_t inputs_previous_read = 0;

void check_for_event_and_update_LEDs(void)
{
	uint16_t inputs_current_read  = (read_IN0 ? B_IN0 : 0) | (read_IN1 ? B_IN1 : 0) | (read_IN2 ? B_IN2 : 0) | (read_IN3 ? B_IN3 : 0) | (read_IN4 ? B_IN4 : 0);
	         inputs_current_read |= (read_IN5 ? B_IN5 : 0) | (read_IN6 ? B_IN6 : 0) | (read_IN7 ? B_IN7 : 0) | (read_IN8 ? B_IN8 : 0) | (read_IN9 ? B_IN9 : 0);
	
	if (inputs_previous_read != inputs_current_read)
	{
		app_regs.REG_INPUTS[0] = inputs_current_read;
		app_regs.REG_INPUTS[1] = inputs_previous_read ^ inputs_current_read;
		
		if ((app_regs.REG_INPUTS[1] &   app_regs.REG_INPUTS[0]  & app_regs.REG_RISING_EDGE_ENABLE) ||
		    (app_regs.REG_INPUTS[1] & (~app_regs.REG_INPUTS[0]) & app_regs.REG_FALLING_EDGE_ENABLE))
			{
				core_func_send_event(ADD_REG_INPUTS, true);
			}
		
		inputs_previous_read = inputs_current_read;
		
		/* Update LEDs */
		if (core_bool_is_visual_enabled())
		{
			PORTH_OUT = (uint8_t) app_regs.REG_INPUTS[0];
			if (app_regs.REG_INPUTS[0] & B_IN8) { set_LED_8; } else { clr_LED_8; }
			if (app_regs.REG_INPUTS[0] & B_IN9) { set_LED_9; } else { clr_LED_9; }
		}
	}
}

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

ISR(PORTE_INT0_vect, ISR_NAKED)
{
	uint8_t aux_inputs_current_read = (read_AUX_INPUT0 ? B_AUX_IN0 : 0) | (read_AUX_INPUT1 ? B_AUX_IN1 : 0);
	
	app_regs.REG_AUX_INPUTS = 0;
	
	if ((aux_inputs_current_read ^ aux_inputs_previous_read) & B_AUX_IN0) { app_regs.REG_AUX_INPUTS |= B_AUX_IN0_CHANGE_MSK; }
	if ((aux_inputs_current_read ^ aux_inputs_previous_read) & B_AUX_IN1) { app_regs.REG_AUX_INPUTS |= B_AUX_IN1_CHANGE_MSK; }
	
	if (app_regs.REG_AUX_INPUTS)
	{
		app_regs.REG_AUX_INPUTS |= (aux_inputs_current_read & (B_AUX_IN0 | B_AUX_IN1));
		core_func_send_event(ADD_REG_AUX_INPUTS, true);
	}
	
	aux_inputs_previous_read = aux_inputs_current_read;
	
	reti();
}

/************************************************************************/ 
/* IN0-4                                                                */
/************************************************************************/
ISR(PORTD_INT0_vect, ISR_NAKED)
{
	check_for_event_and_update_LEDs();	
	reti();
}

/************************************************************************/ 
/* IN5-8                                                                */
/************************************************************************/
ISR(PORTC_INT0_vect, ISR_NAKED)
{
	check_for_event_and_update_LEDs();
	reti();
}

/************************************************************************/ 
/* IN9                                                                  */
/************************************************************************/
ISR(PORTE_INT1_vect, ISR_NAKED)
{
	check_for_event_and_update_LEDs();
	reti();
}

