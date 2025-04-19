
// Created by KIMYOUNGSEO on 25. 4. 2.

#ifndef GAME_START_H
#define GAME_START_H


#include <ncurses.h>
#include <string>
#include <vector>


using namespace std;


void init_colors();
void print_title(WINDOW* win, const string& title);
void print_menu(WINDOW* menu_win, int highlight, const vector<string>& options);
int gm_start();
bool is_quit();

#endif //GAME_START_H
