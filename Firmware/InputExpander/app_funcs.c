#include "app_funcs.h"
#include "app_ios_and_regs.h"
#include "hwbp_core.h"


/************************************************************************/
/* Create pointers to functions                                         */
/************************************************************************/
extern AppRegs app_regs;

void (*app_func_rd_pointer[])(void) = {
	&app_read_REG_AUX_INPUTS,
	&app_read_REG_INPUTS
};

bool (*app_func_wr_pointer[])(void*) = {
	&app_write_REG_AUX_INPUTS,
	&app_write_REG_INPUTS
};


/************************************************************************/
/* REG_AUX_INPUTS                                                       */
/************************************************************************/
void app_read_REG_AUX_INPUTS(void)
{
	//app_regs.REG_AUX_INPUTS = 0;

}

bool app_write_REG_AUX_INPUTS(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_AUX_INPUTS = reg;
	return true;
}


/************************************************************************/
/* REG_INPUTS                                                           */
/************************************************************************/
void app_read_REG_INPUTS(void)
{
	//app_regs.REG_INPUTS = 0;

}

bool app_write_REG_INPUTS(void *a)
{
	uint16_t reg = *((uint16_t*)a);

	app_regs.REG_INPUTS = reg;
	return true;
}