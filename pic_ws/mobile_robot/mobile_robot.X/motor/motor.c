#include "motor.h"
#include "AVIX.h"
#include "master.h"
#include "Define.h"

//Global variables
extern bool path_found;
extern struct coordinate current_pos,next_pos,dest_pos;

U8 A_Str_U8_1[50];
U8 blank_string_1[6] = "      ";
static struct coordinate current_pos_local,next_pos_local;

void motor_init(){

}

TAVIX_THREAD_REGULAR motor_thread(void* p){
    while(1){
        IEC1bits.T5IE=0;
        current_pos_local.x=current_pos.x;
        current_pos_local.y=current_pos.y;
        next_pos_local.x=next_pos.x;
        next_pos_local.y=next_pos.y;
        IEC1bits.T5IE=1;
        current_pos_local.x=next_pos_local.x;
        current_pos_local.y=next_pos_local.y;
        printf("x : %d y: %d \n",current_pos_local.x,current_pos_local.y);
        LCD_WriteString(1, 1, blank_string_1);
        sprintf(A_Str_U8_1, "%d", current_pos_local.x); // Print variable to string
        LCD_WriteString(1, 1, A_Str_U8_1);

        LCD_WriteString(2, 1, blank_string_1);
        sprintf(A_Str_U8_1, "%d", current_pos_local.y); // Print variable to string
        LCD_WriteString(2, 1, A_Str_U8_1);

        IEC1bits.T5IE=0;
        current_pos.x=current_pos_local.x;
        current_pos.y=current_pos_local.y;
        IEC1bits.T5IE=1;

        avixThread_Sleep(10000);
        avixThread_Relinquish();
    }
}
