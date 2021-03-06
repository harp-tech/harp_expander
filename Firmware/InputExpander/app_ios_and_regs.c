#include <avr/io.h>
#include "hwbp_core_types.h"
#include "app_ios_and_regs.h"

/************************************************************************/
/* Configure and initialize IOs                                         */
/************************************************************************/
void init_ios(void)
{	/* Configure input pins */
	io_pin2in(&PORTE, 2, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // AUX_INPUT0
	io_pin2in(&PORTE, 5, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // AUX_INPUT1
	io_pin2in(&PORTE, 3, PULL_IO_UP, SENSE_IO_EDGES_BOTH);               // IS_INPUT
	io_pin2in(&PORTD, 4, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // IN0
	io_pin2in(&PORTD, 3, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // IN1
	io_pin2in(&PORTD, 2, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // IN2
	io_pin2in(&PORTD, 1, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // IN3
	io_pin2in(&PORTD, 0, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // IN4
	io_pin2in(&PORTC, 0, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // IN5
	io_pin2in(&PORTC, 1, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // IN6
	io_pin2in(&PORTC, 2, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // IN7
	io_pin2in(&PORTC, 3, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // IN8
	io_pin2in(&PORTE, 0, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // IN9
	io_pin2in(&PORTA, 0, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PA0
	io_pin2in(&PORTA, 1, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PA1
	io_pin2in(&PORTA, 2, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PA2
	io_pin2in(&PORTA, 3, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PA3
	io_pin2in(&PORTA, 4, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PA4
	io_pin2in(&PORTA, 5, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PA5
	io_pin2in(&PORTA, 7, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PA7
	io_pin2in(&PORTB, 0, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PB0
	io_pin2in(&PORTB, 1, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PB1
	io_pin2in(&PORTB, 2, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PB2
	io_pin2in(&PORTB, 3, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PB3
	io_pin2in(&PORTB, 4, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PB4
	io_pin2in(&PORTB, 7, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PB7
	io_pin2in(&PORTC, 4, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PC4
	io_pin2in(&PORTC, 5, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PC5
	io_pin2in(&PORTD, 5, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PD5
	io_pin2in(&PORTE, 1, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PE1
	io_pin2in(&PORTE, 6, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PE6
	io_pin2in(&PORTE, 7, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PE7
	io_pin2in(&PORTF, 0, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PF0
	io_pin2in(&PORTF, 1, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PF1
	io_pin2in(&PORTF, 4, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PF4
	io_pin2in(&PORTF, 5, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PF5
	io_pin2in(&PORTF, 6, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PF6
	io_pin2in(&PORTF, 7, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PF7
	io_pin2in(&PORTJ, 3, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PJ3
	io_pin2in(&PORTJ, 4, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PJ4
	io_pin2in(&PORTJ, 5, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PJ5
	io_pin2in(&PORTJ, 7, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PJ7
	io_pin2in(&PORTK, 3, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PK3
	io_pin2in(&PORTK, 4, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PK4
	io_pin2in(&PORTK, 5, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PK5
	io_pin2in(&PORTK, 6, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PK6
	io_pin2in(&PORTK, 7, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PK7
	io_pin2in(&PORTQ, 0, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PQ0
	io_pin2in(&PORTQ, 1, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PQ1
	io_pin2in(&PORTQ, 2, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PQ2
	io_pin2in(&PORTQ, 3, PULL_IO_DOWN, SENSE_IO_EDGES_BOTH);             // PQ3

	/* Configure input interrupts */
	io_set_int(&PORTE, INT_LEVEL_LOW, 0, (1<<2), false);                 // AUX_INPUT0
	io_set_int(&PORTE, INT_LEVEL_LOW, 0, (1<<5), false);                 // AUX_INPUT1
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

	/* Configure output pins */
	io_pin2out(&PORTH, 0, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_0
	io_pin2out(&PORTH, 1, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_1
	io_pin2out(&PORTH, 2, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_2
	io_pin2out(&PORTH, 3, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_3
	io_pin2out(&PORTH, 4, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_4
	io_pin2out(&PORTH, 5, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_5
	io_pin2out(&PORTH, 6, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_6
	io_pin2out(&PORTH, 7, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_7
	io_pin2out(&PORTJ, 0, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_8
	io_pin2out(&PORTJ, 1, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_9
	io_pin2out(&PORTJ, 2, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_PWR
	io_pin2out(&PORTA, 6, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_STATE
	io_pin2out(&PORTB, 5, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // IDE_IOS_DIR
	io_pin2out(&PORTB, 6, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // IDE_IOS_EN
	io_pin2out(&PORTD, 7, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // BNC_IOS_DIR
	io_pin2out(&PORTD, 6, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // BNC_IOS_EN

	/* Initialize output pins */
	clr_LED_0;
	clr_LED_1;
	clr_LED_2;
	clr_LED_3;
	clr_LED_4;
	clr_LED_5;
	clr_LED_6;
	clr_LED_7;
	clr_LED_8;
	clr_LED_9;
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
	TYPE_U8,
	TYPE_U8,
	TYPE_U16,
	TYPE_U16,
	TYPE_U16,
	TYPE_U8,
	TYPE_U8,
	TYPE_I16,
	TYPE_U8
};

uint16_t app_regs_n_elements[] = {
	1,
	1,
	1,
	2,
	1,
	1,
	1,
	1,
	1,
	1
};

uint8_t *app_regs_pointer[] = {
	(uint8_t*)(&app_regs.REG_AUX_INPUTS),
	(uint8_t*)(&app_regs.REG_AUX_INPUTS_RISING_EDGE_ENABLE),
	(uint8_t*)(&app_regs.REG_AUX_INPUTS_FALLING_EDGE_ENABLE),
	(uint8_t*)(app_regs.REG_INPUTS),
	(uint8_t*)(&app_regs.REG_RISING_EDGE_ENABLE),
	(uint8_t*)(&app_regs.REG_FALLING_EDGE_ENABLE),
	(uint8_t*)(&app_regs.REG_INPUT_MODE),
	(uint8_t*)(&app_regs.REG_ENCODER_MODE),
	(uint8_t*)(&app_regs.REG_ENCODER),
	(uint8_t*)(&app_regs.REG_EXPANSION_OPTIONS)
};