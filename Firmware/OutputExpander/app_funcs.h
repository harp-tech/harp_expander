#ifndef _APP_FUNCTIONS_H_
#define _APP_FUNCTIONS_H_
#include <avr/io.h>


/************************************************************************/
/* Define if not defined                                                */
/************************************************************************/
#ifndef bool
	#define bool uint8_t
#endif
#ifndef true
	#define true 1
#endif
#ifndef false
	#define false 0
#endif


/************************************************************************/
/* Prototypes                                                           */
/************************************************************************/
void app_read_REG_AUX_INPUTS(void);
void app_read_REG_AUX_INPUTS_RISING_EDGE_ENABLE(void);
void app_read_REG_AUX_INPUTS_FALLING_EDGE_ENABLE(void);
void app_read_REG_OUTPUTS_SET(void);
void app_read_REG_OUTPUTS_CLEAR(void);
void app_read_REG_OUTPUTS_TOGGLE(void);
void app_read_REG_OUTPUTS_WRITE(void);
void app_read_REG_PWM_AND_STIM_ENABLE(void);
void app_read_REG_PWM_AND_STIM_DISABLE(void);
void app_read_REG_PWM_AND_STIM_WRITE(void);
void app_read_REG_PWM0_FREQ(void);
void app_read_REG_PWM0_DUTYCYCLE(void);
void app_read_REG_PWM0_COUNT(void);
void app_read_REG_PWM0_REAL_FREQ(void);
void app_read_REG_PWM0_REAL_DUTYCYCLE(void);
void app_read_REG_PWM0_MODE(void);
void app_read_REG_PWM0_TRIG(void);
void app_read_REG_PWM0_CONF_EVENT(void);
void app_read_REG_PWM1_FREQ(void);
void app_read_REG_PWM1_DUTYCYCLE(void);
void app_read_REG_PWM1_COUNT(void);
void app_read_REG_PWM1_REAL_FREQ(void);
void app_read_REG_PWM1_REAL_DUTYCYCLE(void);
void app_read_REG_PWM1_MODE(void);
void app_read_REG_PWM1_TRIG(void);
void app_read_REG_PWM1_CONF_EVENT(void);
void app_read_REG_PWM2_FREQ(void);
void app_read_REG_PWM2_DUTYCYCLE(void);
void app_read_REG_PWM2_COUNT(void);
void app_read_REG_PWM2_REAL_FREQ(void);
void app_read_REG_PWM2_REAL_DUTYCYCLE(void);
void app_read_REG_PWM2_MODE(void);
void app_read_REG_PWM2_TRIG(void);
void app_read_REG_PWM2_CONF_EVENT(void);
void app_read_REG_PWM_START(void);
void app_read_REG_PWM_STOP(void);
void app_read_REG_PWM_RISE_EVENT(void);
void app_read_REG_STIM0_T_ON(void);
void app_read_REG_STIM0_T_OFF(void);
void app_read_REG_STIM0_COUNT(void);
void app_read_REG_STIM0_MODE(void);
void app_read_REG_STIM0_TRIG(void);
void app_read_REG_STIM_START(void);
void app_read_REG_STIM_STOP(void);
void app_read_REG_PULSE_ENABLE(void);
void app_read_REG_PULSE_OUT0(void);
void app_read_REG_PULSE_OUT1(void);
void app_read_REG_PULSE_OUT2(void);
void app_read_REG_PULSE_OUT3(void);
void app_read_REG_PULSE_OUT4(void);
void app_read_REG_PULSE_OUT5(void);
void app_read_REG_PULSE_OUT6(void);
void app_read_REG_PULSE_OUT7(void);
void app_read_REG_PULSE_OUT8(void);
void app_read_REG_PULSE_OUT9(void);
void app_read_REG_EXPANSION_OPTIONS(void);
void app_read_REG_RESERVED2(void);
void app_read_REG_RESERVED3(void);
void app_read_REG_MAG_ENCODER_READ(void);
void app_read_REG_MAG_ENCODER_MODE(void);
void app_read_REG_RESERVED4(void);
void app_read_REG_RESERVED5(void);
void app_read_REG_SERVO_PERIOD_US(void);
void app_read_REG_SERVO0_PULSE_US(void);
void app_read_REG_SERVO1_PULSE_US(void);
void app_read_REG_SERVO2_PULSE_US(void);

bool app_write_REG_AUX_INPUTS(void *a);
bool app_write_REG_AUX_INPUTS_RISING_EDGE_ENABLE(void *a);
bool app_write_REG_AUX_INPUTS_FALLING_EDGE_ENABLE(void *a);
bool app_write_REG_OUTPUTS_SET(void *a);
bool app_write_REG_OUTPUTS_CLEAR(void *a);
bool app_write_REG_OUTPUTS_TOGGLE(void *a);
bool app_write_REG_OUTPUTS_WRITE(void *a);
bool app_write_REG_PWM_AND_STIM_ENABLE(void *a);
bool app_write_REG_PWM_AND_STIM_DISABLE(void *a);
bool app_write_REG_PWM_AND_STIM_WRITE(void *a);
bool app_write_REG_PWM0_FREQ(void *a);
bool app_write_REG_PWM0_DUTYCYCLE(void *a);
bool app_write_REG_PWM0_COUNT(void *a);
bool app_write_REG_PWM0_REAL_FREQ(void *a);
bool app_write_REG_PWM0_REAL_DUTYCYCLE(void *a);
bool app_write_REG_PWM0_MODE(void *a);
bool app_write_REG_PWM0_TRIG(void *a);
bool app_write_REG_PWM0_CONF_EVENT(void *a);
bool app_write_REG_PWM1_FREQ(void *a);
bool app_write_REG_PWM1_DUTYCYCLE(void *a);
bool app_write_REG_PWM1_COUNT(void *a);
bool app_write_REG_PWM1_REAL_FREQ(void *a);
bool app_write_REG_PWM1_REAL_DUTYCYCLE(void *a);
bool app_write_REG_PWM1_MODE(void *a);
bool app_write_REG_PWM1_TRIG(void *a);
bool app_write_REG_PWM1_CONF_EVENT(void *a);
bool app_write_REG_PWM2_FREQ(void *a);
bool app_write_REG_PWM2_DUTYCYCLE(void *a);
bool app_write_REG_PWM2_COUNT(void *a);
bool app_write_REG_PWM2_REAL_FREQ(void *a);
bool app_write_REG_PWM2_REAL_DUTYCYCLE(void *a);
bool app_write_REG_PWM2_MODE(void *a);
bool app_write_REG_PWM2_TRIG(void *a);
bool app_write_REG_PWM2_CONF_EVENT(void *a);
bool app_write_REG_PWM_START(void *a);
bool app_write_REG_PWM_STOP(void *a);
bool app_write_REG_PWM_RISE_EVENT(void *a);
bool app_write_REG_STIM0_T_ON(void *a);
bool app_write_REG_STIM0_T_OFF(void *a);
bool app_write_REG_STIM0_COUNT(void *a);
bool app_write_REG_STIM0_MODE(void *a);
bool app_write_REG_STIM0_TRIG(void *a);
bool app_write_REG_STIM_START(void *a);
bool app_write_REG_STIM_STOP(void *a);
bool app_write_REG_PULSE_ENABLE(void *a);
bool app_write_REG_PULSE_OUT0(void *a);
bool app_write_REG_PULSE_OUT1(void *a);
bool app_write_REG_PULSE_OUT2(void *a);
bool app_write_REG_PULSE_OUT3(void *a);
bool app_write_REG_PULSE_OUT4(void *a);
bool app_write_REG_PULSE_OUT5(void *a);
bool app_write_REG_PULSE_OUT6(void *a);
bool app_write_REG_PULSE_OUT7(void *a);
bool app_write_REG_PULSE_OUT8(void *a);
bool app_write_REG_PULSE_OUT9(void *a);
bool app_write_REG_EXPANSION_OPTIONS(void *a);
bool app_write_REG_RESERVED2(void *a);
bool app_write_REG_RESERVED3(void *a);
bool app_write_REG_MAG_ENCODER_READ(void *a);
bool app_write_REG_MAG_ENCODER_MODE(void *a);
bool app_write_REG_RESERVED4(void *a);
bool app_write_REG_RESERVED5(void *a);
bool app_write_REG_SERVO_PERIOD_US(void *a);
bool app_write_REG_SERVO0_PULSE_US(void *a);
bool app_write_REG_SERVO1_PULSE_US(void *a);
bool app_write_REG_SERVO2_PULSE_US(void *a);


#endif /* _APP_FUNCTIONS_H_ */