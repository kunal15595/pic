#include "master.h"
#include "AVIX.h"
#include "std_int.h"
#include "astar.h"
#include <stdbool.h>
#include <math.h>
#include "ping.h"

//Global variables
extern bool path_found;
extern struct coordinate current_pos,next_pos,dest_pos;

const double PROXIMITY_HEURISTIC = 0.1;

void astar_init();
uint8_t get_map_cost(const uint32_t x, const uint32_t y);
void get_new_path();
bool closeby(struct coordinate,struct coordinate);
astar_t *as;
uint8_t map[WIDTH][HEIGHT]=
        {{0,0,0,0,0,0,0,0,0,0},
         {1,0,1,1,1,1,0,0,0,0},
         {0,0,0,0,0,1,0,0,0,0},
         {0,0,0,0,0,1,0,0,0,0},
         {0,0,0,0,0,1,1,1,1,0},
         {0,1,0,0,0,1,0,0,1,0},
         {0,0,0,0,0,0,1,0,1,0},
         {0,0,0,0,0,0,0,1,1,0},
         {0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0}
        };
static struct coordinate current_pos_local,next_pos_local,dest_pos_local;
int num_steps;
bool path_found_local;
direction_t *directions,*dir;
static void map_init();//only for debugging
static void map_print();

TAVIX_THREAD_REGULAR master_thread(void* p){
    astar_init();
    while(1){
        IEC1bits.T5IE=0;
        path_found_local=path_found;
        IEC1bits.T5IE=1;
        if(!path_found_local){
            get_new_path();
        }
        IEC1bits.T5IE=0;
        path_found_local=path_found;
        IEC1bits.T5IE=1;
        if(path_found_local){
            IEC1bits.T5IE=0;
            current_pos_local.x=current_pos.x;
            current_pos_local.y=current_pos.y;
            next_pos_local.x=next_pos.x;
            next_pos_local.y=next_pos.y;
            dest_pos_local.x=dest_pos.x;
            dest_pos_local.y=dest_pos.y;
            IEC1bits.T5IE=1;
            if(closeby(current_pos_local,next_pos_local)){
                if(!(next_pos_local.x==dest_pos_local.x&&next_pos_local.x==dest_pos_local.y)){
                    next_pos_local.x+=astar_get_dx(as,*dir);
                    next_pos_local.y+=astar_get_dy(as,*dir);
                    dir++;
                    IEC1bits.T5IE=0;
                    next_pos.x=next_pos_local.x;
                    next_pos.y=next_pos_local.y;
                    IEC1bits.T5IE=1;
                }
            }
        }
//        ping();
        avixThread_Relinquish();
    }
}

void astar_init(){
    directions=NULL;
    as = astar_new(WIDTH, HEIGHT, get_map_cost, NULL);
    astar_set_origin(as,0,0);
    map_init();//only for debugging
}

void get_new_path(){
    if(directions!=NULL)
        astar_free_directions(directions);
    IEC1bits.T5IE=0;
    current_pos_local.x=current_pos.x;
    current_pos_local.y=current_pos.y;
    dest_pos_local.x=dest_pos.x;
    dest_pos_local.y=dest_pos.y;
    IEC1bits.T5IE=1;
    int result = astar_run(as, current_pos_local.x, current_pos_local.y, dest_pos_local.x, dest_pos_local.y);
    if(astar_have_route(as)){
        num_steps = astar_get_directions(as, &directions);
        IEC1bits.T5IE=0;
        path_found=true;
        IEC1bits.T5IE=1;
        map_print();
    }else{
        directions=NULL;
    }
    dir=directions;

}

uint8_t inline get_map(uint32_t x,uint32_t y){
    return map[x][y];
}

void set_map(uint32_t x,uint32_t y,enum node_type node_type){
    IEC1bits.T5IE=0;
    map[x][y]=node_type;
    IEC1bits.T5IE=1;
}

uint8_t get_map_cost(const uint32_t x, const uint32_t y){
    return (get_map(x,y)==1)?255:1;
}

bool closeby(struct coordinate first,struct coordinate second){
    if(abs(first.x-second.x)<PROXIMITY_HEURISTIC){
        if(abs(first.y-second.y)<PROXIMITY_HEURISTIC)
            return true;
    }
    return false;
}

static void
map_init()
{
//    map={{0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0}
//        };
//    srand(time(NULL));
//	int i,j, x, y;
//
//	// First, clear it.
//        for(i=0;i<HEIGHT;i++){
//            for (j = 0; j < WIDTH; j++) {
//                set_map(i,j,FREE);
//            }
//        }
//
//	// Now, fill it with some random walls (one wall per 50 spaces)
//	for (i = 0; i < WIDTH * HEIGHT / 10; i++) {
//		// Fill random spots with 2-column, 1-row blocks
//		x = rand() % (WIDTH - 1);
//		y = rand() % HEIGHT;
//		// Don't put anything near the start/end positions.
//		if (((x <= 6) && (y <= 3)) ||
//		    ((x >= (WIDTH - 7)) && (y >= (HEIGHT - 4)))) {
//			--i;
//			continue;
//		}
//		set_map (x, y, WALL);
//		set_map (x + 1, y, WALL);
//	}
}

static void
map_print()
{
	int x, y;

	printf ("\n");
	for (y = 0; y < HEIGHT; y++) {
		for (x = 0; x < WIDTH; x++) {
			printf ("%d ", map[x][y]);
		}
		printf ("\n");
	}
	printf ("\n");
}