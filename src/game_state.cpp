#include "game_state.h"

// Define global variables
GameState gs={0,0,0,0,10,10,10,10,false,0,{0}};
Item item_list[100];

void display_status(GameState gs)
{

	mvprintw(5,10,"Game Status\n");
	mvprintw(6,10,"Difficulty:%d\n",gs.difficulty);
	mvprintw(7,10,"Day:%d\n",gs.day);
	mvprintw(8,10,"Food:%d\n",gs.food);
	mvprintw(9,10,"Water:%d\n",gs.water);
	mvprintw(10,10,"Health:%d\n",gs.health);
	mvprintw(11,10,"Hunger:%d\n",gs.hunger);
	mvprintw(12,10,"Thirst:%d\n",gs.thirst);
	mvprintw(13,10,"Sanity:%d\n",gs.sanity);
	if (ill)
	{
		printw(14,10,"You are ill!!!");
	}

		

}