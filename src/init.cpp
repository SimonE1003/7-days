#include "../include/init.h"
#include "../include/game_state.h"
#include <ncurses.h>
#include <iostream>

void init() {
    char file[10]="items";
	ifstream fin;
	int num=0;
	while (fin >> items_list[num].code >> items_list[num].name && num<100)
	{
		num++;
	}
	file.close();
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, true);
	nodelay(stdscr, true);
}

void start() {
    // Start screen implementation
}