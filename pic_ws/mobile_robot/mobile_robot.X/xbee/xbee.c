#include "xbee.h"

U8 com_transmit_broad[] = {0x7E, 0x00, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x68, 0x65, 0x6C, 0x6C, 0x6F, 0xEC};

// 7E000F1701000000000000FFFFFFFE02444264
U8 com_atdb_broad[] = {0x7E, 0x00, 0x0F, 0x17, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFE, 0x02, 0x44, 0x42, 0x64};

// 7E000F17010013A20040B79714FFFE0244420B
U8 com_atdb_ref1[] = {0x7E, 0x00, 0x0F, 0x17, 0x01, 0x00, 0x13, 0xA2, 0x00,
    0x40, 0xB7, 0x97, 0x14, 0xFF, 0xFE, 0x02, 0x44, 0x42, 0x0B};

// 7E000F17010013A20040B79712FFFE0244420D
U8 com_atdb_ref2[] = {0x7E, 0x00, 0x0F, 0x17, 0x01, 0x00, 0x13, 0xA2, 0x00,
    0x40, 0xB7, 0x97, 0x12, 0xFF, 0xFE, 0x02, 0x44, 0x42, 0x0D};

// 7E000F17010013A20040B796E8FFFE02444238
U8 com_atdb_ref3[] = {0x7E, 0x00, 0x0F, 0x17, 0x01, 0x00, 0x13, 0xA2, 0x00,
    0x40, 0xB7, 0x96, 0xE8, 0xFF, 0xFE, 0x02, 0x44, 0x42, 0x38};

// sample atdb response -> 7E 00 10 97 01 00 13 A2 00 40 AC C4 49 00 00 44 42 00 29 0A

// 7E 00 0C 00 01 00 00 00 00 00 00 FF FF 00 61 9F
U8 com_atrp_broad[] = {0x7E, 0x00, 0x0F, 0x17, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFE, 0x02, 0x44, 0x42, 0x64};

// 7E 00 0C 00 01 00 13 A2 00 40 B7 97 14 00 61 46
U8 com_atrp_ref1[] = {0x7E, 0x00, 0x0F, 0x17, 0x01, 0x00, 0x13, 0xA2, 0x00,
    0x40, 0xB7, 0x97, 0x14, 0xFF, 0xFE, 0x02, 0x44, 0x42, 0x0B};

// 7E 00 0C 00 01 00 13 A2 00 40 B7 97 12 00 61 48
U8 com_atrp_ref2[] = {0x7E, 0x00, 0x0F, 0x17, 0x01, 0x00, 0x13, 0xA2, 0x00,
    0x40, 0xB7, 0x97, 0x12, 0xFF, 0xFE, 0x02, 0x44, 0x42, 0x0D};

// 7E 00 0C 00 01 00 13 A2 00 40 B7 96 E8 00 61 73
U8 com_atrp_ref3[] = {0x7E, 0x00, 0x0F, 0x17, 0x01, 0x00, 0x13, 0xA2, 0x00,
    0x40, 0xB7, 0x96, 0xE8, 0xFF, 0xFE, 0x02, 0x44, 0x42, 0x38};

// sample atrp response ->

U8 com_test[] = {0x7E, 0x00, 0x0F, 0x17, 0x01, 0x00, 0x13, 0xA2, 0x00, 0x40,
    0xB7, 0x97, 0x14, 0xFF, 0xFE, 0x02, 0x4E, 0x49, 0xFA};

U8 com_test_2[] = {0x7E, 0x00, 0x27, 0x10, 0x01, 0x00, 0x13, 0xA2, 0x00, 0x40,
    0xB7, 0x97, 0x14, 0xFF, 0xFE, 0x00, 0x00, 0x71, 0x77, 0x65, 0x72, 0x74,
    0x79, 0x75, 0x69, 0x6F, 0x70, 0x6C, 0x6B, 0x6A, 0x68, 0x67, 0x66,
    0x64, 0x61, 0x7A, 0x78, 0x63, 0x76, 0x62, 0x6E, 0x6D, 0xEE};

int is_complete;
int xbee_lock = 0;
tavixTimerId timer_xbee_id;
int read_atrp_signal = 0;
int atrp_ref_id = 0;
tavixTimerTick num_ticks;
unsigned int Capture1, Capture2;
int Interrupt_Count = 0, Int_flag, count, temp_edge_index_1 = 0, temp_edge_index_2 = 0;
unsigned int timer_first_edge, timer_second_edge, timer_third_edge,
first_edge, second_edge, third_edge, temp_edge, pulse;
unsigned int edge_buffer_up[200];
unsigned int edge_buffer_down[200];
F32 distance[4];
F32 distance_avg;
int distance_count;
U8 atdb_buf[100];
int atdb_buf_index = 0;
int atdb_scan_index = 0;
U8 atdb_ref1, atdb_ref2, atdb_ref3;

TAVIX_THREAD_REGULAR xbee_thread(void* p){
    U8 lcd_xbee[50];
    U8 blank_string[3] = "   ";
    timer_xbee_id = avixTimer_Create("timer_xbee");
    avixTimer_Set(timer_xbee_id, AVIX_DELAY_MS(1000), AVIX_TIMER_CYCLIC);
    avixTimer_Start(timer_xbee_id);
    while(1){
//
        avixTimer_Wait(timer_xbee_id);
//        num_ticks = avixTimer_GetRemainingTicks(timer_xbee_id);
//        M_ToggleIO(LED3);

//        LCD_WriteString(2, 1, blank_string);
        while(atdb_scan_index%100 != atdb_buf_index){
            // 7E 00 10 97 01 00 13 A2 00 40 AC C4 49 00 00 44 42 00 29 0A
            if(atdb_buf[atdb_scan_index]==0x7E){
                if(atdb_buf[(atdb_scan_index+2)%100]==0x10){
                    if(atdb_buf[(atdb_scan_index+12)%100]==0x14){
                        atdb_ref1 = atdb_buf[(atdb_scan_index+18)%100];
                        LCD_WriteString(1, 1, blank_string);
                        sprintf(lcd_xbee, "%X", atdb_ref1);
                        LCD_WriteString(1, 1, lcd_xbee);
                    }else if(atdb_buf[(atdb_scan_index+12)%100]==0x12){
                        atdb_ref2 = atdb_buf[(atdb_scan_index+18)%100];
                        LCD_WriteString(1, 5, blank_string);
                        sprintf(lcd_xbee, "%X", atdb_ref2);
                        LCD_WriteString(1, 5, lcd_xbee);
                    }else if(atdb_buf[(atdb_scan_index+12)%100]==0xE8){
                        atdb_ref3 = atdb_buf[(atdb_scan_index+18)%100];
                        LCD_WriteString(1, 9, blank_string);
                        sprintf(lcd_xbee, "%X", atdb_ref3);
                        LCD_WriteString(1, 9, lcd_xbee);
                    }
                    atdb_scan_index += 19;

                }else {
                    atdb_scan_index++;
                }
            }
            atdb_scan_index++;
            if(atdb_scan_index==100)atdb_scan_index=0;
        }

//        UART2_SEND_String(com_transmit_broad, sizeof(com_transmit_broad));
        UART2_SEND_String(com_atdb_broad, sizeof (com_atdb_broad));
    }
}

avixDeclareISR(_U2RXInterrupt, no_auto_psv){
//    M_ToggleIO(LED3);
    while(U2STAbits.URXDA){
        atdb_buf[atdb_buf_index++] = U2RXREG;
        if(atdb_buf_index==100)atdb_buf_index=0;
    }
    LED2 = C_ON;
//    read_atrp_signal = 1;
    U2RX_Clear_Intr_Status_Bit;
}

//avixDeclareISR(_IC1Interrupt, no_auto_psv){
//    //        M_ToggleIO(LED3);
////    LED3 = C_ON;
//    is_complete = 0;
//    ReadCapture1(&edge_buffer_up[temp_edge_index_1++]);
//    if (temp_edge_index_1 >= 200)temp_edge_index_1 = 0;
//
////    IC1_Clear_Intr_Status_Bit;
//    IFS0bits.IC1IF = 0;
//}
//
//avixDeclareISR(_IC2Interrupt, no_auto_psv){
//    //        M_ToggleIO(LED3);
//    //    LED3 = C_ON;
//    is_complete = 1;
//    ReadCapture2(&edge_buffer_down[temp_edge_index_2++]);
//    if (temp_edge_index_2 >= 200)temp_edge_index_2 = 0;
//
////    IC2_Clear_Intr_Status_Bit;
//    IFS0bits.IC2IF = 0;
//}