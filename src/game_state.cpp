#include "../include/game_state.h"
#include <ncurses.h>

// Define global variables


/*
struct GameState {
    double day;
    int food, water, difficulty, hunger, thirst, health, sanity, bullet;
    bool ill;
    vector <string> items;
};
*/

GameState gs={0,0,0,0,10,10,10,10,0,false,{}};

void display_status(GameState gs)
{
	initscr();
	start_color();
	init_pair(1,COLOR_RED,COLOR_BLACK);

    mvprintw(5, 10, "Game Status\n");
    mvprintw(6, 10, "Difficulty: %d\n", gs.difficulty);
    char day_buffer[20];
    snprintf(day_buffer, sizeof(day_buffer), "%.1f", gs.day);
    mvprintw(7, 10, "Day: %s\n", day_buffer);
    mvprintw(8, 10, "Food: %d\n", gs.food);
    mvprintw(9, 10, "Water: %d\n", gs.water);    mvprintw(10, 10, "Health: %d\n", gs.health);
    mvprintw(11, 10, "Hunger: %d\n", gs.hunger);
    mvprintw(12, 10, "Thirst: %d\n", gs.thirst);
    mvprintw(13, 10, "Sanity: %d\n", gs.sanity);
    mvprintw(14, 10, "Bullet: %d\n", gs.bullet);
    if (gs.ill)
    {
	attron(COLOR_PAIR(1));
        mvprintw(14, 10, "You are ill!!!");
	attroff(COLOR_PAIR(1));

    }
    int prtcnt = 0;
    mvprintw(15, 10+prtcnt, "Items: ");
    prtcnt += 7;
    for (string item : gs.items)
    {
        
        mvprintw(15, 10+prtcnt, "%s", item.c_str());
        prtcnt += item.size() + 2;

    }
    mvprintw(17, 10, "Press 'q' to quit\n");
    refresh();

    // Wait for the user to press 'q'
    refresh();
    int ch;
    while ((ch = getch()) != 'q')
    {
        // Do nothing, just wait for 'q'
    }
}
