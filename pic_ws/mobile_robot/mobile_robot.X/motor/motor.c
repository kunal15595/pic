#include "motor.h"

void motor_init(){

}

TAVIX_THREAD_REGULAR motor_thread(void* p){
    while(1){
        avixThread_Relinquish();
    }
}
