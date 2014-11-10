#include "ping.h"
#include "ELBv21_HardwareConfig.h"
#include "Define.h"
#include "AVIX.h"
//Microchip library
#include <incap.h>
#include <outcompare.h>
#include <stdbool.h>


unsigned int min_obstacle_dist;

/*** GLOBAL VARIABLES ***/
static U8 A_Str_U8[50];
static unsigned int Capture1, Capture2;
static int Interrupt_Count, Int_flag, count, temp_edge_index;
static unsigned int timer_first_edge, timer_second_edge,timer_third_edge,
        first_edge, second_edge , third_edge, temp_edge, edge_buffer[122], pulse,min_obstacle_dist_local;

static int count = 0;
static int read_enable = 0;


TAVIX_THREAD_REGULAR ping_thread(void* p){
//    while(1){
//         while (!read_enable);
//        int j;
//        for(j=1;j<5;j++){
//            if(edge_buffer[j+1] - edge_buffer[j] > 30){
//                if(edge_buffer[j+1] - edge_buffer[j] < 500){
//                    pulse = edge_buffer[j+1] - edge_buffer[j];
//                    break;
//                }else{
//                    pulse = 11111;
//                }
//            }else{
//                pulse = 11111;
//            }
//        }
//        if(pulse != 11111){
////            LCD_Clear();
//            sprintf(A_Str_U8, "%u", pulse); // Print variable to string
//            LCD_WriteString(2, 9, A_Str_U8);
//        }
//        read_enable = 0;
//    }
}


avixDeclareISR(_IC1Interrupt, no_auto_psv){
    ReadCapture1(&temp_edge);
    M_ToggleIO(LED2);
    if(temp_edge > 0x6000 && temp_edge < 0x7000){
        edge_buffer[++temp_edge_index]= temp_edge;
        if(temp_edge_index>=2){
//            int j=(temp_edge_index>6)?temp_edge_index-5:1;
            int j;
            for(j=1;j<=5;j++){
                if(edge_buffer[j+1] - edge_buffer[j] > 30){
                    if(edge_buffer[j+1] - edge_buffer[j] < 500){
                        pulse = edge_buffer[j+1] - edge_buffer[j];
            M_ToggleIO(LED3);
//                        temp_edge_index=0;
                        break;
                    }else{
                        pulse = 11111;
                    }
                }else{
                    pulse = 11111;
                }
            }
        }
        if(temp_edge_index > 120)temp_edge_index=50;
    }else{
        temp_edge_index = 0;
    }
    IC1_Clear_Intr_Status_Bit;
}

avixDeclareISR(_OC9Interrupt, no_auto_psv){
    OC9_Clear_Intr_Status_Bit;
}

avixDeclareISR(_T1Interrupt, no_auto_psv){
    IFS0bits.T1IF = 0;
}

void ping(){
//    DisableIntIC1;
    min_obstacle_dist_local=pulse;
//    EnableInstIC1;
    if(min_obstacle_dist_local != 11111){
        sprintf(A_Str_U8, "%u", min_obstacle_dist_local); // Print variable to string
        LCD_WriteString(2, 1, A_Str_U8);
    }
}


