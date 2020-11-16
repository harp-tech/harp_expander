#ifndef _APP_IOS_AND_REGS_H_
#define _APP_IOS_AND_REGS_H_
#include "cpu.h"

void init_ios(void);
/************************************************************************/
/* Definition of input pins                                             */
/************************************************************************/
// AUX_INPUT0             Description: Auxiliar input 0
// AUX_INPUT1             Description: Auxiliar input 1
// IN0                    Description: Input 0
// IN1                    Description: Input 1
// IN2                    Description: Input 2
// IN3                    Description: Input 3
// IN4                    Description: Input 4
// IN5                    Description: Input 5
// IN6                    Description: Input 6
// IN7                    Description: Input 7
// IN8                    Description: Input 8
// IN9                    Description: Input 9

#define read_AUX_INPUT0 read_io(PORTA, 0)       // AUX_INPUT0
#define read_AUX_INPUT1 read_io(PORTA, 1)       // AUX_INPUT1
#define read_IN0 read_io(PORTD, 4)              // IN0
#define read_IN1 read_io(PORTD, 3)              // IN1
#define read_IN2 read_io(PORTD, 2)              // IN2
#define read_IN3 read_io(PORTD, 1)              // IN3
#define read_IN4 read_io(PORTD, 0)              // IN4
#define read_IN5 read_io(PORTC, 0)              // IN5
#define read_IN6 read_io(PORTC, 1)              // IN6
#define read_IN7 read_io(PORTC, 2)              // IN7
#define read_IN8 read_io(PORTC, 3)              // IN8
#define read_IN9 read_io(PORTC, 4)              // IN9

/************************************************************************/
/* Definition of output pins                                            */
/************************************************************************/
// LED_I0                 Description: Drives the I0 LED
// LED_I1                 Description: Drives the I1 LED
// LED_I2                 Description: Drives the I2 LED
// LED_I3                 Description: Drives the I3 LED
// LED_I4                 Description: Drives the I4 LED
// LED_I5                 Description: Drives the I5 LED
// LED_I6                 Description: Drives the I6 LED
// LED_I7                 Description: Drives the I7 LED
// LED_I8                 Description: Drives the I8 LED
// LED_I9                 Description: Drives the I9 LED
// LED_PWR                Description: Drives the PWR LED
// LED_STATE              Description: Drives the STATE LED
// IDE_IOS_DIR            Description: Direction control
// IDE_IOS_EN             Description: Buffer enable
// BNC_IOS_DIR            Description: Direction control
// BNC_IOS_EN             Description: Buffer enable

/* LED_I0 */
#define set_LED_I0 set_io(PORTH, 0)
#define clr_LED_I0 clear_io(PORTH, 0)
#define tgl_LED_I0 toggle_io(PORTH, 0)
#define read_LED_I0 read_io(PORTH, 0)

/* LED_I1 */
#define set_LED_I1 set_io(PORTH, 1)
#define clr_LED_I1 clear_io(PORTH, 1)
#define tgl_LED_I1 toggle_io(PORTH, 1)
#define read_LED_I1 read_io(PORTH, 1)

/* LED_I2 */
#define set_LED_I2 set_io(PORTH, 2)
#define clr_LED_I2 clear_io(PORTH, 2)
#define tgl_LED_I2 toggle_io(PORTH, 2)
#define read_LED_I2 read_io(PORTH, 2)

/* LED_I3 */
#define set_LED_I3 set_io(PORTH, 3)
#define clr_LED_I3 clear_io(PORTH, 3)
#define tgl_LED_I3 toggle_io(PORTH, 3)
#define read_LED_I3 read_io(PORTH, 3)

/* LED_I4 */
#define set_LED_I4 set_io(PORTH, 4)
#define clr_LED_I4 clear_io(PORTH, 4)
#define tgl_LED_I4 toggle_io(PORTH, 4)
#define read_LED_I4 read_io(PORTH, 4)

/* LED_I5 */
#define set_LED_I5 set_io(PORTH, 5)
#define clr_LED_I5 clear_io(PORTH, 5)
#define tgl_LED_I5 toggle_io(PORTH, 5)
#define read_LED_I5 read_io(PORTH, 5)

/* LED_I6 */
#define set_LED_I6 set_io(PORTH, 6)
#define clr_LED_I6 clear_io(PORTH, 6)
#define tgl_LED_I6 toggle_io(PORTH, 6)
#define read_LED_I6 read_io(PORTH, 6)

/* LED_I7 */
#define set_LED_I7 set_io(PORTH, 7)
#define clr_LED_I7 clear_io(PORTH, 7)
#define tgl_LED_I7 toggle_io(PORTH, 7)
#define read_LED_I7 read_io(PORTH, 7)

/* LED_I8 */
#define set_LED_I8 set_io(PORTJ, 0)
#define clr_LED_I8 clear_io(PORTJ, 0)
#define tgl_LED_I8 toggle_io(PORTJ, 0)
#define read_LED_I8 read_io(PORTJ, 0)

/* LED_I9 */
#define set_LED_I9 set_io(PORTJ, 1)
#define clr_LED_I9 clear_io(PORTJ, 1)
#define tgl_LED_I9 toggle_io(PORTJ, 1)
#define read_LED_I9 read_io(PORTJ, 1)

/* LED_PWR */
#define set_LED_PWR set_io(PORTJ, 2)
#define clr_LED_PWR clear_io(PORTJ, 2)
#define tgl_LED_PWR toggle_io(PORTJ, 2)
#define read_LED_PWR read_io(PORTJ, 2)

/* LED_STATE */
#define set_LED_STATE set_io(PORTA, 6)
#define clr_LED_STATE clear_io(PORTA, 6)
#define tgl_LED_STATE toggle_io(PORTA, 6)
#define read_LED_STATE read_io(PORTA, 6)

/* IDE_IOS_DIR */
#define set_IDE_IOS_DIR set_io(PORTB, 5)
#define clr_IDE_IOS_DIR clear_io(PORTB, 5)
#define tgl_IDE_IOS_DIR toggle_io(PORTB, 5)
#define read_IDE_IOS_DIR read_io(PORTB, 5)

/* IDE_IOS_EN */
#define set_IDE_IOS_EN set_io(PORTB, 6)
#define clr_IDE_IOS_EN clear_io(PORTB, 6)
#define tgl_IDE_IOS_EN toggle_io(PORTB, 6)
#define read_IDE_IOS_EN read_io(PORTB, 6)

/* BNC_IOS_DIR */
#define set_BNC_IOS_DIR set_io(PORTD, 7)
#define clr_BNC_IOS_DIR clear_io(PORTD, 7)
#define tgl_BNC_IOS_DIR toggle_io(PORTD, 7)
#define read_BNC_IOS_DIR read_io(PORTD, 7)

/* BNC_IOS_EN */
#define set_BNC_IOS_EN set_io(PORTD, 6)
#define clr_BNC_IOS_EN clear_io(PORTD, 6)
#define tgl_BNC_IOS_EN toggle_io(PORTD, 6)
#define read_BNC_IOS_EN read_io(PORTD, 6)


/************************************************************************/
/* Registers' structure                                                 */
/************************************************************************/
typedef struct
{
	uint8_t REG_AUX_INPUTS;
	uint16_t REG_INPUTS;
} AppRegs;

/************************************************************************/
/* Registers' address                                                   */
/************************************************************************/
/* Registers */
#define ADD_REG_AUX_INPUTS                  32 // U8     State of the auxiliar inputs
#define ADD_REG_INPUTS                      33 // U16    State of the inputs

/************************************************************************/
/* PWM Generator registers' memory limits                               */
/*                                                                      */
/* DON'T change the APP_REGS_ADD_MIN value !!!                          */
/* DON'T change these names !!!                                         */
/************************************************************************/
/* Memory limits */
#define APP_REGS_ADD_MIN                    0x20
#define APP_REGS_ADD_MAX                    0x21
#define APP_NBYTES_OF_REG_BANK              3

/************************************************************************/
/* Registers' bits                                                      */
/************************************************************************/
#define B_AUX_IN0                          (1<<0)       // Auxiliar input 0
#define B_AUX_IN1                          (1<<1)       // Auxiliar input 1
#define B_IN0                              (1<<0)       // Digital IN0
#define B_IN1                              (1<<1)       // Digital IN1
#define B_IN2                              (1<<2)       // Digital IN2
#define B_IN3                              (1<<3)       // Digital IN3
#define B_IN4                              (1<<4)       // Digital IN4
#define B_IN5                              (1<<5)       // Digital IN5
#define B_IN6                              (1<<6)       // Digital IN6
#define B_IN7                              (1<<7)       // Digital IN7
#define B_IN8                              (1<<8)       // Digital IN8
#define B_IN9                              (1<<9)       // Digital IN9

#endif /* _APP_REGS_H_ */