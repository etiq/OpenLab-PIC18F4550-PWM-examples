/*
 * File name            : main.c
 * Compiler             : XC8 compiler
 * IDE                  : Microchip MPLAB X IDE v1.90
 * Processor            : PIC18F
 * Author               : Etiq Technologies
 * Description          : Example_5.1 Pulse Width Modulation (PWM)
 *                      : Created on November 5, 2013, 2:30 PM
 *                      : Configuration of PWM module1 PWM output with constant duty cycle through Channel 1
 */

/*
 * Pulse-Width Modulation (PWM) mode
 * The CCPx pin produces up to a 10-bit resolution PWM output

 * OUTPUT PIN CONNECTIONS
 * ----------------------
 * PORTC PIN RC2 -  CCP2 (PWM_1)
 * PORTC PIN RC1 -  CCP1 (PWM_2)  CCP2MX = ON
 * CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
 */


#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include <plib\pwm.h>
#include "Pwm_1.h"
#include "delay.h"
#define _XTAL_FREQ 20000000
#define USE_OR_MASKS




void main()
{
    unsigned char period = 0xFF;                 /*  PWM Period = [(PR2) + 1] * 4 * TOSC *(TMR2 Prescale Value)     */
    unsigned int Duty_cycle = 512;               /* 1/4000 = [PR2 + 1] * 4 * [1 / 20000000] * 16    50% duty cycle  */
                                                 /*  PWM Duty Cycle =                                               */
                                                 /*  (CCPR1L:CCP1CON<5:4> *TOSC * (TMR2 Prescale Value)             */
    unsigned char config = SINGLE_OUT ;
    unsigned char mode = PWM_MODE_1;
    OpenPWM1( period );                          /*Opening PWM module 1                                             */
                                                 /*PWM generation                                                   */
    while(1)
    {
        SetDCPWM1(Duty_cycle);                  /*  PWM generation                              */
        Delay_s(1);                              /*  max Duty cycle value can have 1024 (2^10 Duty cycles possible) */
        SetOutputPWM1(config, mode);

    }
}