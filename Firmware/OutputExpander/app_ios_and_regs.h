#ifndef _APP_IOS_AND_REGS_H_
#define _APP_IOS_AND_REGS_H_
#include "cpu.h"

void init_ios(void);
/************************************************************************/
/* Definition of input pins                                             */
/************************************************************************/
// AUX_INPUT0             Description: Auxiliary input 0
// AUX_INPUT1             Description: Auxiliary input 1
// IS_OUTPUT              Description: Check for the right hardware
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
#define read_IS_OUTPUT read_io(PORTE, 3)        // IS_OUTPUT
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
// LED_0                  Description: Drives the LED 0
// LED_1                  Description: Drives the LED 1
// LED_2                  Description: Drives the LED 2
// LED_3                  Description: Drives the LED 3
// LED_4                  Description: Drives the LED 4
// LED_5                  Description: Drives the LED 5
// LED_6                  Description: Drives the LED 6
// LED_7                  Description: Drives the LED 7
// LED_8                  Description: Drives the LED 8
// LED_9                  Description: Drives the LED 9
// LED_PWR                Description: Drives the PWR LED
// LED_STATE              Description: Drives the STATE LED
// IDE_IOS_DIR            Description: Direction control
// IDE_IOS_EN             Description: Buffer enable
// BNC_IOS_DIR            Description: Direction control
// BNC_IOS_EN             Description: Buffer enable
// OUT0                   Description: Output 0
// OUT1                   Description: Output 1
// OUT2                   Description: Output 2
// OUT3                   Description: Output 3
// OUT4                   Description: Output 4
// OUT5                   Description: Output 5
// OUT6                   Description: Output 6
// OUT7                   Description: Output 7
// OUT8                   Description: Output 8
// OUT9                   Description: Output 9

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

/* OUT0 */
#define set_OUT0 set_io(PORTD, 4)
#define clr_OUT0 clear_io(PORTD, 4)
#define tgl_OUT0 toggle_io(PORTD, 4)
#define read_OUT0 read_io(PORTD, 4)

/* OUT1 */
#define set_OUT1 set_io(PORTD, 3)
#define clr_OUT1 clear_io(PORTD, 3)
#define tgl_OUT1 toggle_io(PORTD, 3)
#define read_OUT1 read_io(PORTD, 3)

/* OUT2 */
#define set_OUT2 set_io(PORTD, 2)
#define clr_OUT2 clear_io(PORTD, 2)
#define tgl_OUT2 toggle_io(PORTD, 2)
#define read_OUT2 read_io(PORTD, 2)

/* OUT3 */
#define set_OUT3 set_io(PORTD, 1)
#define clr_OUT3 clear_io(PORTD, 1)
#define tgl_OUT3 toggle_io(PORTD, 1)
#define read_OUT3 read_io(PORTD, 1)

/* OUT4 */
#define set_OUT4 set_io(PORTD, 0)
#define clr_OUT4 clear_io(PORTD, 0)
#define tgl_OUT4 toggle_io(PORTD, 0)
#define read_OUT4 read_io(PORTD, 0)

/* OUT5 */
#define set_OUT5 set_io(PORTC, 0)
#define clr_OUT5 clear_io(PORTC, 0)
#define tgl_OUT5 toggle_io(PORTC, 0)
#define read_OUT5 read_io(PORTC, 0)

/* OUT6 */
#define set_OUT6 set_io(PORTC, 1)
#define clr_OUT6 clear_io(PORTC, 1)
#define tgl_OUT6 toggle_io(PORTC, 1)
#define read_OUT6 read_io(PORTC, 1)

/* OUT7 */
#define set_OUT7 set_io(PORTC, 2)
#define clr_OUT7 clear_io(PORTC, 2)
#define tgl_OUT7 toggle_io(PORTC, 2)
#define read_OUT7 read_io(PORTC, 2)

/* OUT8 */
#define set_OUT8 set_io(PORTC, 3)
#define clr_OUT8 clear_io(PORTC, 3)
#define tgl_OUT8 toggle_io(PORTC, 3)
#define read_OUT8 read_io(PORTC, 3)

/* OUT9 */
#define set_OUT9 set_io(PORTE, 0)
#define clr_OUT9 clear_io(PORTE, 0)
#define tgl_OUT9 toggle_io(PORTE, 0)
#define read_OUT9 read_io(PORTE, 0)


/************************************************************************/
/* Registers' structure                                                 */
/************************************************************************/
typedef struct
{
	uint8_t REG_AUX_INPUTS;
	uint8_t REG_AUX_INPUTS_RISING_EDGE_ENABLE;
	uint8_t REG_AUX_INPUTS_FALLING_EDGE_ENABLE;
	uint16_t REG_OUTPUTS_SET;
	uint16_t REG_OUTPUTS_CLEAR;
	uint16_t REG_OUTPUTS_TOGGLE;
	uint16_t REG_OUTPUTS_WRITE;
	uint16_t REG_PWM_AND_STIM_ENABLE;
	uint16_t REG_PWM_AND_STIM_DISABLE;
	uint16_t REG_PWM_AND_STIM_WRITE;
	float REG_PWM0_FREQ;
	float REG_PWM0_DUTYCYCLE;
	uint16_t REG_PWM0_COUNT;
	float REG_PWM0_REAL_FREQ;
	float REG_PWM0_REAL_DUTYCYCLE;
	uint8_t REG_PWM0_MODE;
	uint8_t REG_PWM0_TRIG;
	uint8_t REG_PWM0_CONF_EVENT;
	float REG_PWM1_FREQ;
	float REG_PWM1_DUTYCYCLE;
	uint16_t REG_PWM1_COUNT;
	float REG_PWM1_REAL_FREQ;
	float REG_PWM1_REAL_DUTYCYCLE;
	uint8_t REG_PWM1_MODE;
	uint8_t REG_PWM1_TRIG;
	uint8_t REG_PWM1_CONF_EVENT;
	float REG_PWM2_FREQ;
	float REG_PWM2_DUTYCYCLE;
	uint16_t REG_PWM2_COUNT;
	float REG_PWM2_REAL_FREQ;
	float REG_PWM2_REAL_DUTYCYCLE;
	uint8_t REG_PWM2_MODE;
	uint8_t REG_PWM2_TRIG;
	uint8_t REG_PWM2_CONF_EVENT;
	uint8_t REG_PWM_START;
	uint8_t REG_PWM_STOP;
	uint8_t REG_PWM_RISE_EVENT;
	uint16_t REG_STIM0_T_ON;
	uint16_t REG_STIM0_T_OFF;
	uint16_t REG_STIM0_COUNT;
	uint8_t REG_STIM0_MODE;
	uint8_t REG_STIM0_TRIG;
	uint8_t REG_STIM_START;
	uint8_t REG_STIM_STOP;
	uint16_t REG_PULSE_ENABLE;
	uint16_t REG_PULSE_OUT0;
	uint16_t REG_PULSE_OUT1;
	uint16_t REG_PULSE_OUT2;
	uint16_t REG_PULSE_OUT3;
	uint16_t REG_PULSE_OUT4;
	uint16_t REG_PULSE_OUT5;
	uint16_t REG_PULSE_OUT6;
	uint16_t REG_PULSE_OUT7;
	uint16_t REG_PULSE_OUT8;
	uint16_t REG_PULSE_OUT9;
	uint8_t REG_EXPANSION_OPTIONS;
	uint8_t REG_RESERVED2;
	uint8_t REG_RESERVED3;
	uint16_t REG_MAG_ENCODER_READ[2];
	uint8_t REG_MAG_ENCODER_MODE;
	uint8_t REG_RESERVED4;
	uint8_t REG_RESERVED5;
	uint16_t REG_SERVO_PERIOD_US;
	uint16_t REG_SERVO0_PULSE_US;
	uint16_t REG_SERVO1_PULSE_US;
	uint16_t REG_SERVO2_PULSE_US;
} AppRegs;

/************************************************************************/
/* Registers' address                                                   */
/************************************************************************/
/* Registers */
#define ADD_REG_AUX_INPUTS                  32 // U8     State of the auxiliary inputs
#define ADD_REG_AUX_INPUTS_RISING_EDGE_ENABLE 33 // U8     Enables the rising edge detection of the correspondet auxiliar input (bitmask)
#define ADD_REG_AUX_INPUTS_FALLING_EDGE_ENABLE 34 // U8     Enables the falling edge detection of the correspondet auxiliar input (bitmask)
#define ADD_REG_OUTPUTS_SET                 35 // U16    Set the outputs
#define ADD_REG_OUTPUTS_CLEAR               36 // U16    Clear the outputs
#define ADD_REG_OUTPUTS_TOGGLE              37 // U16    Toggle the outputs
#define ADD_REG_OUTPUTS_WRITE               38 // U16    Write to all outputs at once
#define ADD_REG_PWM_AND_STIM_ENABLE         39 // U16    
#define ADD_REG_PWM_AND_STIM_DISABLE        40 // U16    
#define ADD_REG_PWM_AND_STIM_WRITE          41 // U16    
#define ADD_REG_PWM0_FREQ                   42 // FLOAT  Frequency of PWM0. Maximum frequency is 1000Hz
#define ADD_REG_PWM0_DUTYCYCLE              43 // FLOAT  Duty cycle fro PWM0. Maximum value is 100%
#define ADD_REG_PWM0_COUNT                  44 // U16    Number of pulses on PWM0
#define ADD_REG_PWM0_REAL_FREQ              45 // FLOAT  Real frequency that will be preformed at PWM0
#define ADD_REG_PWM0_REAL_DUTYCYCLE         46 // FLOAT  Real duty cycle that will be preformed at PWM0
#define ADD_REG_PWM0_MODE                   47 // U8     Mode configuration for PWM0
#define ADD_REG_PWM0_TRIG                   48 // U8     Configuration of hardware trigger for PWM0
#define ADD_REG_PWM0_CONF_EVENT             49 // U8     
#define ADD_REG_PWM1_FREQ                   50 // FLOAT  Frequency of PWM1. Maximum frequency is 1000Hz
#define ADD_REG_PWM1_DUTYCYCLE              51 // FLOAT  Duty cycle fro PWM1. Maximum value is 100%
#define ADD_REG_PWM1_COUNT                  52 // U16    Number of pulses on PWM1
#define ADD_REG_PWM1_REAL_FREQ              53 // FLOAT  Real frequency that will be preformed at PWM1
#define ADD_REG_PWM1_REAL_DUTYCYCLE         54 // FLOAT  Real duty cycle that will be preformed at PWM1
#define ADD_REG_PWM1_MODE                   55 // U8     Mode configuration for PWM1
#define ADD_REG_PWM1_TRIG                   56 // U8     Configuration of hardware trigger for PWM1
#define ADD_REG_PWM1_CONF_EVENT             57 // U8     
#define ADD_REG_PWM2_FREQ                   58 // FLOAT  Frequency of PWM2. Maximum frequency is 1000Hz
#define ADD_REG_PWM2_DUTYCYCLE              59 // FLOAT  Duty cycle fro PWM2. Maximum value is 100%
#define ADD_REG_PWM2_COUNT                  60 // U16    Number of pulses on PWM2
#define ADD_REG_PWM2_REAL_FREQ              61 // FLOAT  Real frequency that will be preformed at PWM2
#define ADD_REG_PWM2_REAL_DUTYCYCLE         62 // FLOAT  Real duty cycle that will be preformed at PWM2
#define ADD_REG_PWM2_MODE                   63 // U8     Mode configuration for PWM2
#define ADD_REG_PWM2_TRIG                   64 // U8     Configuration of hardware trigger for PWM2
#define ADD_REG_PWM2_CONF_EVENT             65 // U8     
#define ADD_REG_PWM_START                   66 // U8     
#define ADD_REG_PWM_STOP                    67 // U8     
#define ADD_REG_PWM_RISE_EVENT              68 // U8     
#define ADD_REG_STIM0_T_ON                  69 // U16    
#define ADD_REG_STIM0_T_OFF                 70 // U16    
#define ADD_REG_STIM0_COUNT                 71 // U16    
#define ADD_REG_STIM0_MODE                  72 // U8     
#define ADD_REG_STIM0_TRIG                  73 // U8     
#define ADD_REG_STIM_START                  74 // U8     
#define ADD_REG_STIM_STOP                   75 // U8     
#define ADD_REG_PULSE_ENABLE                76 // U16    Bitmask of pulse enable for each digital output
#define ADD_REG_PULSE_OUT0                  77 // U16    Pulse time in ms
#define ADD_REG_PULSE_OUT1                  78 // U16    Pulse time in ms
#define ADD_REG_PULSE_OUT2                  79 // U16    Pulse time in ms
#define ADD_REG_PULSE_OUT3                  80 // U16    Pulse time in ms
#define ADD_REG_PULSE_OUT4                  81 // U16    Pulse time in ms
#define ADD_REG_PULSE_OUT5                  82 // U16    Pulse time in ms
#define ADD_REG_PULSE_OUT6                  83 // U16    Pulse time in ms
#define ADD_REG_PULSE_OUT7                  84 // U16    Pulse time in ms
#define ADD_REG_PULSE_OUT8                  85 // U16    Pulse time in ms
#define ADD_REG_PULSE_OUT9                  86 // U16    Pulse time in ms
#define ADD_REG_EXPANSION_OPTIONS           87 // U8     Selects the current expansion board available in the EXPANSION port
#define ADD_REG_RESERVED2                   88 // U8     
#define ADD_REG_RESERVED3                   89 // U8     
#define ADD_REG_MAG_ENCODER_READ            90 // U16    
#define ADD_REG_MAG_ENCODER_MODE            91 // U8     
#define ADD_REG_RESERVED4                   92 // U8     
#define ADD_REG_RESERVED5                   93 // U8     
#define ADD_REG_SERVO_PERIOD_US             94 // U16    
#define ADD_REG_SERVO0_PULSE_US             95 // U16    
#define ADD_REG_SERVO1_PULSE_US             96 // U16    
#define ADD_REG_SERVO2_PULSE_US             97 // U16    

/************************************************************************/
/* PWM Generator registers' memory limits                               */
/*                                                                      */
/* DON'T change the APP_REGS_ADD_MIN value !!!                          */
/* DON'T change these names !!!                                         */
/************************************************************************/
/* Memory limits */
#define APP_REGS_ADD_MIN                    0x20
#define APP_REGS_ADD_MAX                    0x61
#define APP_NBYTES_OF_REG_BANK              133

/************************************************************************/
/* Registers' bits                                                      */
/************************************************************************/
#define B_AUX_IN0                          (1<<0)       // Auxiliar input 0
#define B_AUX_IN1                          (1<<1)       // Auxiliar input 1
#define B_AUX_IN0_CHANGE_MSK               (1<<4)       // Set when the Auxiliar input 0 created the interrupt
#define B_AUX_IN1_CHANGE_MSK               (1<<5)       // Set when the Auxiliar input 1 created the interrupt
#define B_OUT0                             (1<<0)       // Digital OUT0
#define B_OUT1                             (1<<1)       // Digital OUT1
#define B_OUT2                             (1<<2)       // Digital OUT2
#define B_OUT3                             (1<<3)       // Digital OUT3
#define B_OUT4                             (1<<4)       // Digital OUT4
#define B_OUT5                             (1<<5)       // Digital OUT5
#define B_OUT6                             (1<<6)       // Digital OUT6
#define B_OUT7                             (1<<7)       // Digital OUT7
#define B_OUT8                             (1<<8)       // Digital OUT8
#define B_OUT9                             (1<<9)       // Digital OUT9
#define B_PWM0_EN_OUT1                     (1<<0)       // 
#define B_PWM0_EN_OUT2                     (1<<1)       // 
#define B_PWM0_EN_OUT3                     (1<<2)       // 
#define B_PWM1_EN_OUT6                     (1<<3)       // 
#define B_PWM1_EN_OUT7                     (1<<4)       // 
#define B_PWM1_EN_OUT8                     (1<<5)       // 
#define B_PWM2_EN_OUT9                     (1<<6)       // 
#define B_STIM0_EN_OUT0                    (1<<7)       // 
#define B_STIM0_EN_OUT5                    (1<<8)       // 
#define GM_PWM_MODE                        3            // 
#define MSK_PWM_MODE_INFINITE              0            // 
#define MSK_PWM_MODE_COUNT                 1            // 
#define GM_PWM_TRIG_AUX0                   0x0F         // 
#define GM_PWM_TRIG_AUX1                   0xF0         // 
#define MSK_PWM_TRIG_SW                    (0<<0)       // 
#define MSK_PWM_TRIG_AUX0_RISE_START       (1<<0)       // 
#define MSK_PWM_TRIG_AUX0_FALL_START       (2<<0)       // 
#define MSK_PWM_TRIG_AUX0_ON_WHILE_HIGH    (3<<0)       // 
#define MSK_PWM_TRIG_AUX0_ON_WHILE_LOW     (4<<0)       // 
#define MSK_PWM_TRIG_AUX1_RISE_START       (1<<4)       // 
#define MSK_PWM_TRIG_AUX1_FALL_START       (2<<4)       // 
#define MSK_PWM_TRIG_AUX1_ON_WHILE_HIGH    (3<<4)       // 
#define MSK_PWM_TRIG_AUX1_ON_WHILE_LOW     (4<<4)       // 
#define GM_PWM_EVENT                       1            // 
#define MSK_PWM_RISE_EVENT_DIS             (0<<0)       // 
#define MSK_PWM_RISE_EVENT_EN              (1<<0)       // 
#define B_PWM0                             (1<<0)       // 
#define B_PWM1                             (1<<1)       // 
#define B_PWM2                             (1<<2)       // 
#define GM_STIM_MODE                       3            // 
#define MSK_STIM_MODE_INFINITE             0            // 
#define MSK_STIM_MODE_COUNT                1            // 
#define GM_STIM_TRIG                       255          // 
#define MSK_STIM_TRIG_SW                   (0<<0)       // 
#define MSK_STIM_TRIG_AUX0_RISE_START      (1<<0)       // 
#define MSK_STIM_TRIG_AUX0_FALL_START      (2<<0)       // 
#define MSK_STIM_TRIG_AUX0_ON_WHILE_HIGH   (3<<0)       // 
#define MSK_STIM_TRIG_AUX0_ON_WHILE_LOW    (4<<0)       // 
#define MSK_STIM_TRIG_AUX1_RISE_START      (0<<4)       // 
#define MSK_STIM_TRIG_AUX1_FALL_START      (1<<4)       // 
#define MSK_STIM_TRIG_AUX1_ON_WHILE_HIGH   (2<<4)       // 
#define MSK_STIM_TRIG_AUX1_ON_WHILE_LOW    (3<<4)       // 
#define B_STIM0                            (1<<0)       // 
#define B_STIM0                            (1<<0)       // 
#define GM_EXPANSION_OPTIONS               7            // 
#define MSK_BREAKOUT                       0            // 
#define MSK_MAGNETIC_ENCODER               1            // 
#define MSK_SERVO_MOTOR_1                  2            // 
#define MSK_SERVO_MOTOR_2                  3            // 
#define MSK_SERVO_MOTOR_3                  4            // 
#define GM_MAG_ENCODER_MODE                7            // 
#define MSK_AT_50SPS                       0            // 
#define MSK_AT_100SPS                      1            // 
#define MSK_AT_200SPS                      2            // 
#define MSK_AT_250SPS                      3            // 
#define MSK_AT_500SPS                      4            // 
#define MSK_AT_1000SPS                     5            // 

#endif /* _APP_REGS_H_ */