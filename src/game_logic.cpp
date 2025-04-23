#include "../include/game_logic.h"
#include "../include/game_state.h"
#include "../include/map_head.h"
#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <string>

void end(int code) {
	int height, width;
	string rewardPrint = "";
    getmaxyx(stdscr, height, width);
	switch (code){
		case 1:UI_stories[15]->text = "You starved to death at the end of the wilderness due to lack of food.";break;
		case 2:UI_stories[15]->text = "You died of thirst, parched in the desolate wilderness.";break;
		case 3:UI_stories[15]->text = "You lost your mind to madness, consumed by chaos in the end.";break;
		case 4:UI_stories[15]->text = "You succumbed to illness, fading away in the grip of disease.";break;
		case 5:UI_stories[15]->text = "You fell in the boss battle, vanquished by an unstoppable foe.";break;
		case 6:UI_stories[15]->text = "You lie in a pool of blood, and your vision gradually turns black.";break;
		case 7:UI_stories[15]->text = "You died";break;//not used yet
	}
	play_story(UI_stories[15], height, width, rewardPrint);
	exit(0);
}

void end_a_day()
{
	int height, width;
	string rewardPrint ="";
	getmaxyx(stdscr, height, width);
	gs.day+=0.5;
	int health_minused = 0;
	int delta = 1 + gs.difficulty;
	UI_stories[17]->text = "";
	if (gs.food>=delta)
	{
		gs.food-=delta;
		UI_stories[17]->text += "Food "+to_string(gs.food)+"(-"+to_string(delta)+") ";
	}
	else if (gs.food<delta && gs.hunger>delta)
	{
		gs.hunger-=delta;
		UI_stories[17]->text += "Hunger "+to_string(gs.hunger)+"(-"+to_string(delta)+") ";
	}
	else if (gs.food<delta && gs.hunger<delta)
	{
		gs.health-=delta;
		health_minused += delta;
		if(gs.health<=0) {
			end(1);//hunger
		}
	}
	if (gs.water>=delta)
	{
		gs.water-=delta;
		UI_stories[17]->text += "Water "+to_string(gs.water)+"(-"+to_string(delta)+") ";
	}
	else if (gs.water<delta && gs.thirst>delta)
	{
		gs.thirst-=delta;
		UI_stories[17]->text += "Thirst "+to_string(gs.thirst)+"(-"+to_string(delta)+") ";
	}
	else if (gs.water<delta && gs.thirst<delta)
	{
		gs.health-=delta;
		health_minused += delta;
		if(gs.health<=0) {
			end(2);//thirst
		}
	}
	if (gs.sanity<delta)
	{
		gs.health-=delta;
		
		health_minused += delta;
		if(gs.health<=0) {
			end(3);//craziness
		}
	}
	if (gs.ill > 0){
		gs.health-=delta;
		UI_stories[17]->text += "Illness, health "+to_string(gs.ill)+"(-"+to_string(delta)+") ";
		if(gs.health<=0) {
			end(4);//illness
		}
	}
	if (health_minused > 0){
		UI_stories[17]->text += "Health "+to_string(gs.health)+"(-"+to_string(health_minused)+") ";
	}
	play_story(UI_stories[16], height, width, rewardPrint);
}

bool head_shot(){
	return rand()%500 < gs.sanity*gs.sanity;
}

void boss_battle(){
	int boss_health = 15;
	string rewardPrint = "";
	int height, width;
    getmaxyx(stdscr, height, width);
	play_story(UI_stories[2], height, width, rewardPrint);
	UI_stories[3]->text = "You got "+ to_string(gs.health) + " health, "+to_string(gs.sanity)+" sanity and "+ to_string(gs.bullet) + " bullets";
	play_story(UI_stories[3], height, width, rewardPrint);
	while (1)
	{
		if (gs.bullet > 0){
			play_story(UI_stories[4], height, width, rewardPrint);
			if (head_shot()){
				play_story(UI_stories[5], height, width, rewardPrint);
				boss_health-=10;
			} else{
				play_story(UI_stories[6], height, width, rewardPrint);
				boss_health-=3;
			}
			gs.bullet--;
		} else{
			play_story(UI_stories[7], height, width, rewardPrint);
			play_story(UI_stories[8], height, width, rewardPrint);
			boss_health--;
		}
		if (boss_health>0){
			UI_stories[11]->text = "The boss has "+to_string(boss_health)+" health left.";
			play_story(UI_stories[11], height, width, rewardPrint);
		} else{
			play_story(UI_stories[9], height, width, rewardPrint);
			play_story(UI_stories[10], height, width, rewardPrint);
			win();
		}
		play_story(UI_stories[12], height, width, rewardPrint);
		gs.health--;
		if (gs.health>0){
			UI_stories[13]->text = "You got "+to_string(gs.health)+" health left.";
			play_story(UI_stories[13], height, width, rewardPrint);
		}else{
			play_story(UI_stories[14], height, width, rewardPrint);
			end(5);//died of boss fight
		}
	}
}

void win() {
    clear();
    refresh();

    int screen_height, screen_width;
    getmaxyx(stdscr, screen_height, screen_width);

    WINDOW* good_ending_win = newwin(screen_height-1, screen_width, 0, 0);
    box(good_ending_win, 0, 0);

    //ASCII art if you guys want some other win ascii change the vector, the x directtion must be equal
    vector<string> victoryArt = {
        R"($$\     $$\                                       $$\           )",
        R"(\$$\   $$  |                                      \__|          )",
        R"( \$$\ $$  /$$$$$$\  $$\   $$\       $$\  $$\  $$\ $$\ $$$$$$$\  )",
        R"(  \$$$$  /$$  __$$\ $$ |  $$ |      $$ | $$ | $$ |$$ |$$  __$$\ )",
        R"(   \$$  / $$ /  $$ |$$ |  $$ |      $$ | $$ | $$ |$$ |$$ |  $$ |)",
        R"(    $$ |  $$ |  $$ |$$ |  $$ |      $$ | $$ | $$ |$$ |$$ |  $$ |)",
        R"(    $$ |  \$$$$$$  |\$$$$$$  |      \$$$$$\$$$$  |$$ |$$ |  $$ |)",
        R"(    \__|   \______/  \______/        \_____\____/ \__|\__|  \__|)"
    };


    int lines = victoryArt.size();
    int start_y = (screen_height - lines) / 2;
    for (int i = 0; i < lines; i++) {
        int start_x = (screen_width - victoryArt[i].length()) / 2;
        mvwprintw(good_ending_win, start_y + i, start_x, "%s", victoryArt[i].c_str());
    }


    string exitM = "Press any key to exit";
    mvwprintw(good_ending_win, start_y + lines + 2, (screen_width - exitM.length()) / 2, "%s", exitM.c_str());
    wrefresh(good_ending_win);
    getch();
    delwin(good_ending_win);
    endwin();
    exit(0);
}