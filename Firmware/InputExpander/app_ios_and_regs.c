#include <avr/io.h>
#include "hwbp_core_types.h"
#include "app_ios_and_regs.h"

/************************************************************************/
/* Configure and initialize IOs                                         */
/************************************************************************/
void init_ios(void)
{	/* Configure input pins */
	io_pin2in(&PORTA, 0, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // AUX_INPUT0
	io_pin2in(&PORTA, 1, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // AUX_INPUT1

	/* Configure input interrupts */
	io_set_int(&PORTA, INT_LEVEL_LOW, 0, (1<<0), false);                 // AUX_INPUT0
	io_set_int(&PORTA, INT_LEVEL_LOW, 1, (1<<1), false);                 // AUX_INPUT1

	/* Configure output pins */
	io_pin2out(&PORTH, 0, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_I0
	io_pin2out(&PORTH, 1, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_I1
	io_pin2out(&PORTH, 2, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_I2
	io_pin2out(&PORTH, 3, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_I3
	io_pin2out(&PORTH, 4, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_I4
	io_pin2out(&PORTH, 5, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_I5
	io_pin2out(&PORTH, 6, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_I6
	io_pin2out(&PORTH, 7, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_I7
	io_pin2out(&PORTJ, 0, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_I8
	io_pin2out(&PORTJ, 1, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_I9
	io_pin2out(&PORTJ, 2, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_PWR
	io_pin2out(&PORTA, 6, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_STATE
	io_pin2out(&PORTB, 5, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // IDE_IOS_DIR
	io_pin2out(&PORTB, 6, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // IDE_IOS_EN
	io_pin2out(&PORTD, 6, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // BNC_IOS_DIR
	io_pin2out(&PORTD, 7, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // BNC_IOS_EN

	/* Initialize output pins */
	clr_LED_I0;
	clr_LED_I1;
	clr_LED_I2;
	clr_LED_I3;
	clr_LED_I4;
	clr_LED_I5;
	clr_LED_I6;
	clr_LED_I7;
	clr_LED_I8;
	clr_LED_I9;
	clr_LED_PWR;
	clr_LED_STATE;
	set_IDE_IOS_DIR;
	clr_IDE_IOS_EN;
	set_BNC_IOS_DIR;
	clr_BNC_IOS_EN;
}

/************************************************************************/
/* Registers' stuff                                                     */
/************************************************************************/
AppRegs app_regs;

uint8_t app_regs_type[] = {
	TYPE_U8,
	TYPE_U16
};

uint16_t app_regs_n_elements[] = {
	1,
	1
};

uint8_t *app_regs_pointer[] = {
	(uint8_t*)(&app_regs.REG_AUX_INPUTS),
	(uint8_t*)(&app_regs.REG_INPUTS)
};