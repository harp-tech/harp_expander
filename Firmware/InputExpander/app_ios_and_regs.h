#ifndef _APP_IOS_AND_REGS_H_
#define _APP_IOS_AND_REGS_H_
#include "cpu.h"

void init_ios(void);
/************************************************************************/
/* Definition of input pins                                             */
/************************************************************************/
// AUX_INPUT0             Description: Auxiliary input 0
// AUX_INPUT1             Description: Auxiliary input 1
// IS_INPUT               Description: Check for the right hardware
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
// PA0                    Description: 
// PA1                    Description: 
// PA2                    Description: 
// PA3                    Description: 
// PA4                    Description: 
// PA5                    Description: 
// PA7                    Description: 
// PB0                    Description: 
// PB1                    Description: 
// PB2                    Description: 
// PB3                    Description: 
// PB4                    Description: 
// PB7                    Description: 
// PC4                    Description: 
// PC5                    Description: 
// PD5                    Description: 
// PE1                    Description: 
// PE6                    Description: 
// PE7                    Description: 
// PF0                    Description: 
// PF1                    Description: 
// PF4                    Description: 
// PF5                    Description: 
// PF6                    Description: 
// PF7                    Description: 
// PJ3                    Description: 
// PJ4                    Description: 
// PJ5                    Description: 
// PJ7                    Description: 
// PK3                    Description: 
// PK4                    Description: 
// PK5                    Description: 
// PK6                    Description: 
// PK7                    Description: 
// PQ0                    Description: 
// PQ1                    Description: 
// PQ2                    Description: 
// PQ3                    Description: 

#define read_AUX_INPUT0 read_io(PORTE, 2)       // AUX_INPUT0
#define read_AUX_INPUT1 read_io(PORTE, 5)       // AUX_INPUT1
#define read_IS_INPUT read_io(PORTE, 3)         // IS_INPUT
#define read_IN0 read_io(PORTD, 4)              // IN0
#define read_IN1 read_io(PORTD, 3)              // IN1
#define read_IN2 read_io(PORTD, 2)              // IN2
#define read_IN3 read_io(PORTD, 1)              // IN3
#define read_IN4 read_io(PORTD, 0)              // IN4
#define read_IN5 read_io(PORTC, 0)              // IN5
#define read_IN6 read_io(PORTC, 1)              // IN6
#define read_IN7 read_io(PORTC, 2)              // IN7
#define read_IN8 read_io(PORTC, 3)              // IN8
#define read_IN9 read_io(PORTE, 0)              // IN9
#define read_PA0 read_io(PORTA, 0)              // PA0
#define read_PA1 read_io(PORTA, 1)              // PA1
#define read_PA2 read_io(PORTA, 2)              // PA2
#define read_PA3 read_io(PORTA, 3)              // PA3
#define read_PA4 read_io(PORTA, 4)              // PA4
#define read_PA5 read_io(PORTA, 5)              // PA5
#define read_PA7 read_io(PORTA, 7)              // PA7
#define read_PB0 read_io(PORTB, 0)              // PB0
#define read_PB1 read_io(PORTB, 1)              // PB1
#define read_PB2 read_io(PORTB, 2)              // PB2
#define read_PB3 read_io(PORTB, 3)              // PB3
#define read_PB4 read_io(PORTB, 4)              // PB4
#define read_PB7 read_io(PORTB, 7)              // PB7
#define read_PC4 read_io(PORTC, 4)              // PC4
#define read_PC5 read_io(PORTC, 5)              // PC5
#define read_PD5 read_io(PORTD, 5)              // PD5
#define read_PE1 read_io(PORTE, 1)              // PE1
#define read_PE6 read_io(PORTE, 6)              // PE6
#define read_PE7 read_io(PORTE, 7)              // PE7
#define read_PF0 read_io(PORTF, 0)              // PF0
#define read_PF1 read_io(PORTF, 1)              // PF1
#define read_PF4 read_io(PORTF, 4)              // PF4
#define read_PF5 read_io(PORTF, 5)              // PF5
#define read_PF6 read_io(PORTF, 6)              // PF6
#define read_PF7 read_io(PORTF, 7)              // PF7
#define read_PJ3 read_io(PORTJ, 3)              // PJ3
#define read_PJ4 read_io(PORTJ, 4)              // PJ4
#define read_PJ5 read_io(PORTJ, 5)              // PJ5
#define read_PJ7 read_io(PORTJ, 7)              // PJ7
#define read_PK3 read_io(PORTK, 3)              // PK3
#define read_PK4 read_io(PORTK, 4)              // PK4
#define read_PK5 read_io(PORTK, 5)              // PK5
#define read_PK6 read_io(PORTK, 6)              // PK6
#define read_PK7 read_io(PORTK, 7)              // PK7
#define read_PQ0 read_io(PORTQ, 0)              // PQ0
#define read_PQ1 read_io(PORTQ, 1)              // PQ1
#define read_PQ2 read_io(PORTQ, 2)              // PQ2
#define read_PQ3 read_io(PORTQ, 3)              // PQ3

/************************************************************************/
/* Definition of output pins                                            */
/************************************************************************/
// LED_0                  Description: Drives the I0 LED
// LED_1                  Description: Drives the I1 LED
// LED_2                  Description: Drives the I2 LED
// LED_3                  Description: Drives the I3 LED
// LED_4                  Description: Drives the I4 LED
// LED_5                  Description: Drives the I5 LED
// LED_6                  Description: Drives the I6 LED
// LED_7                  Description: Drives the I7 LED
// LED_8                  Description: Drives the I8 LED
// LED_9                  Description: Drives the I9 LED
// LED_PWR                Description: Drives the PWR LED
// LED_STATE              Description: Drives the STATE LED
// IDE_IOS_DIR            Description: Direction control
// IDE_IOS_EN             Description: Buffer enable
// BNC_IOS_DIR            Description: Direction control
// BNC_IOS_EN             Description: Buffer enable

/* LED_0 */
#define set_LED_0 set_io(PORTH, 0)
#define clr_LED_0 clear_io(PORTH, 0)
#define tgl_LED_0 toggle_io(PORTH, 0)
#define read_LED_0 read_io(PORTH, 0)

/* LED_1 */
#define set_LED_1 set_io(PORTH, 1)
#define clr_LED_1 clear_io(PORTH, 1)
#define tgl_LED_1 toggle_io(PORTH, 1)
#define read_LED_1 read_io(PORTH, 1)

/* LED_2 */
#define set_LED_2 set_io(PORTH, 2)
#define clr_LED_2 clear_io(PORTH, 2)
#define tgl_LED_2 toggle_io(PORTH, 2)
#define read_LED_2 read_io(PORTH, 2)

/* LED_3 */
#define set_LED_3 set_io(PORTH, 3)
#define clr_LED_3 clear_io(PORTH, 3)
#define tgl_LED_3 toggle_io(PORTH, 3)
#define read_LED_3 read_io(PORTH, 3)

/* LED_4 */
#define set_LED_4 set_io(PORTH, 4)
#define clr_LED_4 clear_io(PORTH, 4)
#define tgl_LED_4 toggle_io(PORTH, 4)
#define read_LED_4 read_io(PORTH, 4)

/* LED_5 */
#define set_LED_5 set_io(PORTH, 5)
#define clr_LED_5 clear_io(PORTH, 5)
#define tgl_LED_5 toggle_io(PORTH, 5)
#define read_LED_5 read_io(PORTH, 5)

/* LED_6 */
#define set_LED_6 set_io(PORTH, 6)
#define clr_LED_6 clear_io(PORTH, 6)
#define tgl_LED_6 toggle_io(PORTH, 6)
#define read_LED_6 read_io(PORTH, 6)

/* LED_7 */
#define set_LED_7 set_io(PORTH, 7)
#define clr_LED_7 clear_io(PORTH, 7)
#define tgl_LED_7 toggle_io(PORTH, 7)
#define read_LED_7 read_io(PORTH, 7)

/* LED_8 */
#define set_LED_8 set_io(PORTJ, 0)
#define clr_LED_8 clear_io(PORTJ, 0)
#define tgl_LED_8 toggle_io(PORTJ, 0)
#define read_LED_8 read_io(PORTJ, 0)

/* LED_9 */
#define set_LED_9 set_io(PORTJ, 1)
#define clr_LED_9 clear_io(PORTJ, 1)
#define tgl_LED_9 toggle_io(PORTJ, 1)
#define read_LED_9 read_io(PORTJ, 1)

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
	uint8_t REG_AUX_INPUTS_RISING_EDGE_ENABLE;
	uint8_t REG_AUX_INPUTS_FALLING_EDGE_ENABLE;
	uint16_t REG_INPUTS[2];
	uint16_t REG_RISING_EDGE_ENABLE;
	uint16_t REG_FALLING_EDGE_ENABLE;
	uint8_t REG_INPUT_MODE;
	uint8_t REG_ENCODER_MODE;
	int16_t REG_ENCODER;
	uint8_t REG_EXPANSION_OPTIONS;
} AppRegs;

/************************************************************************/
/* Registers' address                                                   */
/************************************************************************/
/* Registers */
#define ADD_REG_AUX_INPUTS                  32 // U8     State of the auxiliary inputs
#define ADD_REG_AUX_INPUTS_RISING_EDGE_ENABLE 33 // U8     Enables the rising edge detection of the correspondet auxiliar input (bitmask)
#define ADD_REG_AUX_INPUTS_FALLING_EDGE_ENABLE 34 // U8     Enables the falling edge detection of the correspondet auxiliar input (bitmask)
#define ADD_REG_INPUTS                      35 // U16    State of the inputs [0] , change masks [1]
#define ADD_REG_RISING_EDGE_ENABLE          36 // U16    Enables the rising edge detection of the correspondet input (bitmask)
#define ADD_REG_FALLING_EDGE_ENABLE         37 // U16    Enables the falling edge detection of the correspondet input (bitmask)
#define ADD_REG_INPUT_MODE                  38 // U8     Configures the input mode
#define ADD_REG_ENCODER_MODE                39 // U8     Configures the rotary encoder
#define ADD_REG_ENCODER                     40 // I16    Contains the rotary encoder reading
#define ADD_REG_EXPANSION_OPTIONS           41 // U8     Selects the current expansion board available in the EXPANSION port

/************************************************************************/
/* PWM Generator registers' memory limits                               */
/*                                                                      */
/* DON'T change the APP_REGS_ADD_MIN value !!!                          */
/* DON'T change these names !!!                                         */
/************************************************************************/
/* Memory limits */
#define APP_REGS_ADD_MIN                    0x20
#define APP_REGS_ADD_MAX                    0x29
#define APP_NBYTES_OF_REG_BANK              16

/************************************************************************/
/* Registers' bits                                                      */
/************************************************************************/
#define B_AUX_IN0                          (1<<0)       // Auxiliar input 0
#define B_AUX_IN1                          (1<<1)       // Auxiliar input 1
#define B_AUX_IN0_CHANGE_MSK               (1<<4)       // Set when the Auxiliar input 0 created the interrupt
#define B_AUX_IN1_CHANGE_MSK               (1<<5)       // Set when the Auxiliar input 1 created the interrupt
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
#define B_IN0_CHANGE_MSK                   (1<<0)       // Set when the digital input 0 created the interrupt
#define B_IN1_CHANGE_MSK                   (1<<1)       // Set when the digital input 1 created the interrupt
#define B_IN2_CHANGE_MSK                   (1<<2)       // Set when the digital input 2 created the interrupt
#define B_IN3_CHANGE_MSK                   (1<<3)       // Set when the digital input 3 created the interrupt
#define B_IN4_CHANGE_MSK                   (1<<4)       // Set when the digital input 4 created the interrupt
#define B_IN5_CHANGE_MSK                   (1<<5)       // Set when the digital input 5 created the interrupt
#define B_IN6_CHANGE_MSK                   (1<<6)       // Set when the digital input 6 created the interrupt
#define B_IN7_CHANGE_MSK                   (1<<7)       // Set when the digital input 7 created the interrupt
#define B_IN8_CHANGE_MSK                   (1<<8)       // Set when the digital input 8 created the interrupt
#define B_IN9_CHANGE_MSK                   (1<<9)       // Set when the digital input 9 created the interrupt
#define GM_INPUT_MODE                      1            // 
#define MSK_ON_INTERRUPTS                  0            // 
#define MSK_AT_1000FPS                     1            // 
#define MSK_AT_2000FPS                     2            // 
#define GM_ENC_MODE                        7            // 
#define MSK_ENC_DISABLED                   0            // Disables the rotary encoder
#define MSK_ENC_250Hz                      1            // Send encoder data at 250 Hz
#define MSK_ENC_500Hz                      2            // Send encoder data at 500 Hz
#define MSK_ENC_1000Hz                     3            // Send encoder data at 1000Hz
#define MSK_ENC_WHEN_CHANGE                4            // Send encoder data only when movement is detected
#define GM_EXPANSION_OPTIONS               1            // 
#define MSK_BREAKOUT                       0            // 

#endif /* _APP_REGS_H_ */