#include "master.h"
#include "AVIX.h"
#include "std_int.h"
#include "astar.h"

void astar_init();
uint8_t get_map_cost(const uint32_t x, const uint32_t y);
astar_t *as;

TAVIX_THREAD_REGULAR master_thread(void* p){
    astar_init();
    while(1){
        avixThread_Relinquish();
    }
}

void astar_init(){
    tavixExchId map_id=avixExch_Get("map");
    as = astar_new(WIDTH, HEIGHT, get_map_cost, NULL);
    astar_set_origin(as,0,0);
}