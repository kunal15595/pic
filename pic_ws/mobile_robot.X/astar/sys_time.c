#include "sys_time.h"
#include <time.h>
int gettimeofday (struct timeval *t, void *unused){
    t->tv_sec=time(NULL);
    t->tv_usec=0;
    return 0;
}