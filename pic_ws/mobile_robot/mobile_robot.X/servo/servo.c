#include "servo.h"
#include "AVIX.h"
#include "ELB_PWM.h"
#include <outcompare.h>


TAVIX_THREAD_REGULAR servo_thread(void* p){
    EnableIntOC9;
    OC9R = 0x5FF0;
    OC9RS = 0x5FF4;
    OC9CON1bits.OCTSEL = 0b000;
    OC9CON2bits.SYNCSEL = 0x1F;
    OC9CON1bits.OCM = 0b110;
    OC9CON2bits.OCINV =  1;
    while(1){
        int i;
        for (i = 20; i < 200; i+=20) {
            PWM1_SET_PulseWidth(0.01 * i);
            ping();
            avixThread_Sleep(5000);
        }
        while (i>=20) {
            PWM1_SET_PulseWidth(0.01 * i);
            ping();
            avixThread_Sleep(5000);
            i-=20;
        }
    }
}
