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

