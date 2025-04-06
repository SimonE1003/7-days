#include "../include/exploration.h"
#include "../include/game_state.h"
#include "../include/map_head.h"
#include "../include/game_start.h"
#include "../include/save_load.h"
#include "../include/init.h"

void start_explore() { run_shelter(); }//this will start one daytime, i feel that let start_explore be day basis
void start_UI(){ gm_start(); }// this will start UI
int main() {
    init();
    save();
    load();
    start_UI();
    //start_explore();
    return 0;
}