/* 
 * File name            : main.c
 * Compiler             : XC8 compiler
 * IDE                  : Microchip MPLAB X IDE v1.90
 * Author               : Etiq Technologies
 * Description          : Example_5.1 Pulse Width Modulation
 *                        PWM module1 is Configured for generating PWM single output signal through Channel 1
 * Created on November 5, 2013, 2:30 PM
 */

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include <plib\pwm.h>
#include "Pwm_1.h"
#define _XTAL_FREQ 20000000
#define USE_OR_MASKS


void main()
{
    unsigned char period = 0x4E;                 /*  PWM Period = [(PR2) + 1] * 4 * TOSC *(TMR2 Prescale Value)  */
    unsigned int Duty_cycle = 0x00;              /* 1/4000 = [PR2 + 1] * 4 * [1 / 20000000] * 16                   */
                                                 /*  PWM Duty Cycle =                                    */
                                                 /*  (CCPR1L:CCP1CON<5:4> ?TOSC ? (TMR2 Prescale Value)  */
    unsigned char config = SINGLE_OUT ;
    unsigned char mode = PWM_MODE_1;    
    OpenPWM1( period );                          /*Opening PWM module 1*/
                                                 /*PWM generation*/
    while(1)
    {
        PwmCycle(period, Duty_cycle);           /*  period and Duty cycle required for the PWM  */
        SetOutputPWM1(config, mode);
    }

}