#include "AD5048A.h"
#include "app_ios_and_regs.h"
#include "hwbp_core.h"

extern AppRegs app_regs;

void read_magnetic_encoder(void)
{
	/* Expansion pins used
	   - OUT5     CS
	   - OUT6     CLK
	   - AUX_IN0  MISO
	   - OUT9     MOSI
	*/

	app_regs.REG_MAG_ENCODER_READ[0] = 0;
	app_regs.REG_MAG_ENCODER_READ[1] = 0;
	
	
	/* CS low for 375 ns (required 350 ns) */
	clr_OUT5; clr_OUT5; 
	clr_OUT5; clr_OUT5; clr_OUT5; clr_OUT5; clr_OUT5;
	clr_OUT5; clr_OUT5; clr_OUT5; clr_OUT5; clr_OUT5;	
	
	/* CLK high for 62.5 ns (required 50 ns) */
	/* CLK low for 62.5 ns (required 50 ns)  */
	/* 16 bits */
	/* Send command 0xFFFF to read angle in the next SPI frame */
	set_OUT9;
	
	set_OUT6; set_OUT6; clr_OUT6; clr_OUT6; 
	set_OUT6; set_OUT6;	clr_OUT6; clr_OUT6;
	set_OUT6; set_OUT6;	clr_OUT6; clr_OUT6;
	set_OUT6; set_OUT6;	clr_OUT6; clr_OUT6;
	set_OUT6; set_OUT6;	clr_OUT6; clr_OUT6;
	set_OUT6; set_OUT6;	clr_OUT6; clr_OUT6;
	set_OUT6; set_OUT6;	clr_OUT6; clr_OUT6;
	set_OUT6; set_OUT6;	clr_OUT6; clr_OUT6;
	
	set_OUT6; set_OUT6; clr_OUT6; clr_OUT6;
	set_OUT6; set_OUT6;	clr_OUT6; clr_OUT6;
	set_OUT6; set_OUT6;	clr_OUT6; clr_OUT6;
	set_OUT6; set_OUT6;	clr_OUT6; clr_OUT6;
	set_OUT6; set_OUT6;	clr_OUT6; clr_OUT6;
	set_OUT6; set_OUT6;	clr_OUT6; clr_OUT6;
	set_OUT6; set_OUT6;	clr_OUT6; clr_OUT6;
	set_OUT6; set_OUT6;	clr_OUT6; clr_OUT6;
	
	/* CS high for 375 ns (required 350 ns) */
	set_OUT5; set_OUT5;
	set_OUT5; set_OUT5; set_OUT5; set_OUT5; set_OUT5;
	set_OUT5; set_OUT5; set_OUT5; set_OUT5; set_OUT5;
	
	
	/* CS low for 375 ns (required 350 ns) */
	clr_OUT5; clr_OUT5;
	clr_OUT5; clr_OUT5; clr_OUT5; clr_OUT5; clr_OUT5;
	clr_OUT5; clr_OUT5; clr_OUT5; clr_OUT5; clr_OUT5;	
	
	/* Read angle from device (14 bits) */
	/* Send command 0x7FFE to read the magnitude in the next SPI frame */
	clr_OUT9;
	set_OUT6; set_OUT6; clr_OUT6; clr_OUT6;
	set_OUT9;
	set_OUT6; set_OUT6; clr_OUT6; clr_OUT6;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[0] |= 0x2000;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[0] |= 0x1000;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[0] |= 0x0800;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[0] |= 0x0400;	
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[0] |= 0x0200;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[0] |= 0x0100;
	
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[0] |= 0x0080;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[0] |= 0x0040;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[0] |= 0x0020;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[0] |= 0x0010;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[0] |= 0x0008;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[0] |= 0x0004;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[0] |= 0x0002;
	clr_OUT9;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[0] |= 0x0001;
	
	/* CS high for 375 ns (required 350 ns) */
	set_OUT5; set_OUT5;
	set_OUT5; set_OUT5; set_OUT5; set_OUT5; set_OUT5;
	set_OUT5; set_OUT5; set_OUT5; set_OUT5; set_OUT5;
	
	
	/* CS low for 375 ns (required 350 ns) */
	clr_OUT5; clr_OUT5;
	clr_OUT5; clr_OUT5; clr_OUT5; clr_OUT5; clr_OUT5;
	clr_OUT5; clr_OUT5; clr_OUT5; clr_OUT5; clr_OUT5;
	
	/* Read angle from device (14 bits) */
	/* Send nop command 0x0000 */
	clr_OUT9;
	set_OUT6; set_OUT6; clr_OUT6; clr_OUT6;
	set_OUT6; set_OUT6; clr_OUT6; clr_OUT6;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[1] |= 0x2000;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[1] |= 0x1000;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[1] |= 0x0800;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[1] |= 0x0400;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[1] |= 0x0200;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[1] |= 0x0100;
	
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[1] |= 0x0080;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[1] |= 0x0040;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[1] |= 0x0020;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[1] |= 0x0010;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[1] |= 0x0008;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[1] |= 0x0004;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[1] |= 0x0002;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) app_regs.REG_MAG_ENCODER_READ[1] |= 0x0001;
	
	/* CS high */
	set_OUT5;
}