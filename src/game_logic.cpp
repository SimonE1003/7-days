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
	int boss_health = 20;
	int height, width;
    getmaxyx(stdscr, height, width);
	play_story(UI_stories[2], height, width);
	UI_stories[6]->text = "You got "+ to_string(gs.health) + " health and "+ to_string(gs.bullet) + " bullets";
	UI_stories[6]->options.push_back("Start fighting");
	UI_stories[6]->next.push_back(nullptr);
	play_story(UI_stories[6], height, width);
	while (boss_health > 0)
	{
		while(gs.bullet > 0){
			play_story(UI_stories[3], height, width);
			boss_health -= 2+2*gs.sanity;
			if (boss_health <= 0)
			{
				break;
			}
			play_story(UI_stories[5], height, width);
			gs.health -= 1;
			if (gs.health <= 0)
			{
				end(1);
			}
		}
		while(gs.health > 0){
			play_story(UI_stories[4], height, width);
			boss_health -= 1;
			if (boss_health <= 0)
			{
				break;
			}
			play_story(UI_stories[5], height, width);
			gs.health -= 1;
			if (gs.health <= 0)
			{
				end(1);
			}
		}
	}
}

void win(){
	//
}
