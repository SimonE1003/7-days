#include "../include/game_logic.h"
#include "../include/game_state.h"
#include <ncurses.h>
#include <unistd.h>

void end(int code) {
	//
}

void end_a_day()
{
	gs.day+=0.5;
	int delta = 1 + gs.difficulty;
	if (gs.food>=delta)
	{
		gs.food-=delta;
	}
	else if (gs.food<delta && gs.hunger<delta)
	{
		gs.hunger-=delta;
	}
	else if (gs.food<delta && gs.hunger<delta)
	{
		gs.health-=delta;
		if(gs.health<delta) {
			end(1);//hunger
		}
	}
	if (gs.water>=delta)
	{
		gs.water-=delta;
	}
	else if (gs.water<delta && gs.thirst>delta)
	{
		gs.thirst-=delta;
	}
	else if (gs.water<delta && gs.thirst<delta)
	{
		gs.health-=delta;
		//TODO
	}
	if (gs.sanity>delta)
	{
		gs.sanity-=delta;
	}
	else
	{
		gs.health-=delta;
		//TODO
	}
	if (gs.ill){
		gs.health-=delta;
		//TODO
	}
}

void boss_battle(){
	//
}

void win(){
	//
}
