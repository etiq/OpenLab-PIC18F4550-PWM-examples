/*
 * File name            : pwm_1.c
 * Compiler             : XC8 compiler/ C18 compiler
 * IDE                  : Microchip MPLAB X IDE v1.90
 * Processor            : PIC18F
 * Author               : Etiq Technologies
 * Description          : Example_5.4 DC MOTOR_1
 *                      : Created on November 13, 2013, 4:10 PM
 *                      : PWM functions definitions source files
*/

#include "delay.h"
#include <plib\pwm.h>
void PwmCycle(unsigned int Duty_cycle_1, unsigned int Duty_cycle_2)
    {
    unsigned char p =  Duty_cycle_1;
    unsigned char q =  Duty_cycle_2;
   while(Duty_cycle_1 != q)
        {
        SetDCPWM1(Duty_cycle_1);                         // PWM_1 generation
        SetDCPWM2(Duty_cycle_2);                         // PWM_2 generation
        Duty_cycle_1++;                                  // Duty cycle increament for PWM1
        Duty_cycle_2--;                                  // Duty cycle decrement for PWM2
        delay_ms(128);
        }
                                                         // max Duty cycle value can have 1024 (2^10 Duty cycles possible   : 10bit resolution)
   while(Duty_cycle_1 != p)
        {
        SetDCPWM1(Duty_cycle_1);
        SetDCPWM2(Duty_cycle_2);
        Duty_cycle_1--;
        Duty_cycle_2++;
        delay_ms(128);
        }
    }