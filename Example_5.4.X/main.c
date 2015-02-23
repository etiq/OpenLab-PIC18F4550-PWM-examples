/*
 * File name            : main.c
 * Compiler             : XC8 compiler/ C18 compiler
 * IDE                  : Microchip MPLAB X IDE v1.90
 * Processor            : PIC18F
 * Author               : Etiq Technologies
 * Description          : Example_5.4 DC MOTOR_1
 *                      : Created on November 4, 2013, 2:30 PM
 *                      : Configuration of PWM module_1 and PWM module_2
 *                      : PWM output with variable duty cycle through Channel_0 and Channel_1
 *                      : PWM module_1 can drive a DC motor if connected to Motor_Relay Board
 */

/*
 * Pulse-Width Modulation (PWM) mode
 * The CCPx pin produces up to a 10-bit resolution PWM output

 * OUTPUT PIN CONFIGURATIONS
 * -------------------------
 * PORTC PIN RC2 -  CCP2 (PWM_1) output
 * PORTC PIN RC1 -  CCP1 (PWM_2) output
 *
 * Note : CCP2MX = ON   See config.h file CCP2 MUX bit is turned ON (CCP2 input/output is multiplexed with RC1)
 *
 * Connect J2 on Motor_Relay Board to PORTC
 *
 * DC Motor connections from Motor_Relay Board
 * -------------------------------------------
 * Jumper J8 : POLE_1 (Vcc)         -   DC Motor PIN_1
 *             POLE_2 (Motor 1)     -   DC Motor PIN_2
 */

#if defined(__XC)
    #include <plib\pwm.h>
    #include <xc.h>        /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File 	*/
#elif defined(__18CXX)
#include <p18cxxx.h>        /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)
#include <stdint.h>        /* For uint8_t definition 		*/
#include <stdbool.h>       /* For true/false definition 	*/
#endif

#if defined(__XC) || defined(__18CXX)

#include "config.h"
#include "delay.h"
#include "pwm_1.h"
#endif
#define _XTAL_FREQ 20000000
#define CCP2_DIR TRISCbits.TRISC2
#define CCP1_DIR TRISCbits.TRISC1

#define OUT 0x00
#define IN  0x01

void main()
{
    unsigned char periode = 0x4D;                         // PWM Period = [(PR2) + 1] * 4 * TOSC *(TMR2 Prescale Value)
    unsigned int Duty_cycle_1 = 50;                         // 1/4000 = [PR2 + 1] * 4*[1 / 20000000] * 16
    unsigned int Duty_cycle_2 = 170;
    CCP2_DIR = OUT;
    CCP1_DIR = OUT;
    OpenPWM1( periode );
    OpenPWM2( periode );
    while(1)                                            
    {
     PwmCycle(Duty_cycle_1, Duty_cycle_2);       // period and Duty cycle required for the PWM
    }
}