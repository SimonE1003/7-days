#include "../include/game_state.h"
#include "../include/map_head.h"
#include <ncurses.h>

// Define global variables


/*
struct GameState {
    double day;
    int food, water, difficulty, hunger, thirst, health, sanity, bullet;
    int ill;
    vector <string> items;
};
*/
//GameState gs={0,1,1,1,0,1,1,1,0,0,{}};
GameState gs={0,5,5,0,5,5,10,10,3,0,{"GLOCK-18"}};

void display_status(GameState gs)
{
	initscr();
	start_color();
	init_pair(1,COLOR_RED,COLOR_BLACK);
    int height, width;
    getmaxyx(stdscr, height, width);
    int center = width/2 -5;
    mvprintw(5, center, "Game Status\n");
    mvprintw(6, center, "Difficulty: %d\n", gs.difficulty);
    char day_buffer[20];
    snprintf(day_buffer, sizeof(day_buffer), "%.1f", gs.day);
    mvprintw(7, center, "Day: %s\n", day_buffer);
    mvprintw(8, center, "Food: %d\n", gs.food);
    mvprintw(9, center, "Water: %d\n", gs.water);    
    mvprintw(10, center, "Health: %d\n", gs.health);
    mvprintw(11, center, "Hunger: %d\n", gs.hunger);
    mvprintw(12, center, "Thirst: %d\n", gs.thirst);
    mvprintw(13, center, "Sanity: %d\n", gs.sanity);
    mvprintw(14, center, "Bullet: %d\n", gs.bullet);
    if (gs.ill > 0)
    {
	attron(COLOR_PAIR(1));
        mvprintw(15, center, "You are ill!!!");
	attroff(COLOR_PAIR(1));

    }
    int prtcnt = 0;
    mvprintw(16, center+prtcnt, "Items: ");
    prtcnt += 7;
    for (string item : gs.items)
    {
        
        mvprintw(16, center+prtcnt, "%s", item.c_str());
        prtcnt += item.size() + 2;

    }
    mvprintw(18, center, "Press 'q' to quit\n");
    refresh();

    // Wait for the user to press 'q'
    refresh();
    int ch;
    while ((ch = getch()) != 'q')
    {
        // Do nothing, just wait for 'q'
    }
}

void display_topleft_corner(GameState gs, string current_map){
    if (int(gs.day / 0.5) %2 == 0)
        mvprintw(0, 0, "Day %d", (int)gs.day+1);
    else{
        mvprintw(0,0,"Night Time");
    }
}
