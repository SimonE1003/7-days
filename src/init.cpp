#include "../include/init.h"
#include <ncurses.h>
#include <iostream>

void init() {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, true);
	nodelay(stdscr, true);
}

void start() {
    // Start screen implementation
}
