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
/* AUX_INPUT0                                                           */
/************************************************************************/
ISR(PORTE_INT0_vect, ISR_NAKED)
{
	app_regs.REG_AUX_INPUTS &= ~(B_AUX_IN0);
	app_regs.REG_AUX_INPUTS |= (read_AUX_INPUT0) ? B_AUX_IN0 : 0;
	core_func_send_event(ADD_REG_AUX_INPUTS, true);
	
	if (read_AUX_INPUT0)
		PORTH_OUTSET = 0x1F;
	else
		PORTH_OUTCLR = 0x1F;
	
	reti();
}

/************************************************************************/ 
/* AUX_INPUT1                                                           */
/************************************************************************/
bool aux1_prev_state = false;
ISR(PORTE_INT1_vect, ISR_NAKED)
{	
	if (read_AUX_INPUT1)
	{
		if (!aux1_prev_state)
		{		
			aux1_prev_state = true;
			
			app_regs.REG_AUX_INPUTS &= ~(B_AUX_IN1);
			app_regs.REG_AUX_INPUTS |= (read_AUX_INPUT1) ? B_AUX_IN1 : 0;
			core_func_send_event(ADD_REG_AUX_INPUTS, true);
			
			PORTH_OUTSET = 0xE0;
			PORTJ_OUTSET = 0x07;
		}
	}
	else
	{
		if (aux1_prev_state)
		{
			aux1_prev_state = false;
			
			app_regs.REG_AUX_INPUTS &= ~(B_AUX_IN1);
			app_regs.REG_AUX_INPUTS |= (read_AUX_INPUT1) ? B_AUX_IN1 : 0;
			core_func_send_event(ADD_REG_AUX_INPUTS, true);
			
			PORTH_OUTCLR = 0xE0;
			PORTJ_OUTCLR = 0x07;
		}
	}
		
	reti();
}

void update_LEDs(void)
{
	PORTH_OUT = app_regs.REG_INPUTS;
	if (read_IN8) {PORTJ_OUT |= 0x01;} else {PORTJ_OUT &= ~0x01;}
	if (read_IN9) {PORTJ_OUT |= 0x02;} else {PORTJ_OUT &= ~0x02;}
}

void update_REG_INPUTS(void)
{
	app_regs.REG_INPUTS  = (read_IN0) ? B_IN0 : 0;
	app_regs.REG_INPUTS |= (read_IN1) ? B_IN1 : 0;
	app_regs.REG_INPUTS |= (read_IN2) ? B_IN2 : 0;
	app_regs.REG_INPUTS |= (read_IN3) ? B_IN3 : 0;
	app_regs.REG_INPUTS |= (read_IN4) ? B_IN4 : 0;
	app_regs.REG_INPUTS |= (read_IN5) ? B_IN5 : 0;
	app_regs.REG_INPUTS |= (read_IN6) ? B_IN6 : 0;
	app_regs.REG_INPUTS |= (read_IN7) ? B_IN7 : 0;
	app_regs.REG_INPUTS |= (read_IN8) ? B_IN8 : 0;
	app_regs.REG_INPUTS |= (read_IN9) ? B_IN9 : 0;
}

/************************************************************************/ 
/* IN0-4                                                                */
/************************************************************************/
ISR(PORTD_INT0_vect, ISR_NAKED)
{
	update_REG_INPUTS();
	core_func_send_event(ADD_REG_INPUTS, true);
	update_LEDs();
	reti();
}

/************************************************************************/ 
/* IN5-9                                                                */
/************************************************************************/
ISR(PORTC_INT0_vect, ISR_NAKED)
{
	update_REG_INPUTS();
	core_func_send_event(ADD_REG_INPUTS, true);
	update_LEDs();
	reti();
}
