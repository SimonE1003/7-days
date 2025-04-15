#include "../include/game_logic.h"
#include "../include/game_state.h"
#include "../include/map_head.h"
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
	else if (gs.food<delta && gs.hunger>delta)
	{
		gs.hunger-=delta;
	}
	else if (gs.food<delta && gs.hunger<delta)
	{
		gs.health-=delta;
		if(gs.health<=0) {
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
		if(gs.health<=0) {
			end(2);//thirst
		}
	}
	if (gs.sanity>delta)
	{
		gs.sanity-=delta;
	}
	else
	{
		gs.health-=delta;
		if(gs.health<=0) {
			end(3);//craziness
		}
	}
	if (gs.ill){
		gs.health-=delta;
		if(gs.health<=0) {
			end(4);//illness
		}
	}
}

bool head_shot(){
	return rand()%500 < gs.sanity*gs.sanity;
}

void boss_battle(){
	int boss_health = 15;
	int height, width;
    getmaxyx(stdscr, height, width);
	play_story(UI_stories[2], height, width);
	play_story(UI_stories[3], height, width);
	while (1)
	{
		if (gs.bullet > 0){
			play_story(UI_stories[4], height, width);
			if (head_shot()){
				play_story(UI_stories[5], height, width);
				boss_health-=10;
			} else{
				play_story(UI_stories[6], height, width);
				boss_health-=3;
			}
			gs.bullet--;
		} else{
			play_story(UI_stories[7], height, width);
			play_story(UI_stories[8], height, width);
			boss_health--;
		}
		if (boss_health>0){
			UI_stories[11]->text = "The boss has "+to_string(boss_health)+" health left.";
			play_story(UI_stories[11], height, width);
		} else{
			play_story(UI_stories[9], height, width);
			play_story(UI_stories[10], height, width);
			win();
		}
		play_story(UI_stories[12], height, width);
		gs.health--;
		if (gs.health>0){
			UI_stories[13]->text = "You got "+to_string(gs.health)+" health left.";
			play_story(UI_stories[13], height, width);
		}else{
			play_story(UI_stories[14], height, width);
			end(5);//died of boss fight
		}
	}
}

void win(){
	//
}
