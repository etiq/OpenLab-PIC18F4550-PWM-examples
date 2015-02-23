#include "delay.h"
#include <plib\pwm.h>
void PwmCycle(unsigned char period, unsigned int Duty_cycle)
    {
while(Duty_cycle != 0xFF)
        {
        SetDCPWM1(Duty_cycle);                           /*  PWM generation  */
        Duty_cycle++;                                    /*  Duty cycle increament for PWM1  */
        Delay_s(3);                                     /*  max Duty cycle value can have 1024 (2^10 Duty cycles possible) */
        }                                                /*  : 10bit resolution) */
    }