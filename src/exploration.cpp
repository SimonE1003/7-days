#include "../include/exploration.h"
#include "../include/game_state.h"
#include "../include/map_head.h"
#include "../include/game_start.h"
#include "../include/save_load.h"
#include "../include/init.h"
#include "../include/game_logic.h"
#include <ncurses.h>

void start_explore() { 
    initialize_stories();
    int height, width;
    getmaxyx(stdscr, height, width);
    while(gs.day<100){
        if (gs.day == 7){
            boss_battle();
        }
        run_shelter();
        
    }
}//this will start one daytime, i feel that let start_explore be day basis
void start_UI(){
	gm_start();
  	/*
	if (is_quit()){
		endwin();
    	exit(0);
	}
  	 */
}// this will start UI
//
