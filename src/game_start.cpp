//game_start.cpp
// Created by KIMYOUNGSEO on 25. 4. 1.

#include "../include/game_start.h"
#include <unistd.h>
#include "../include/map_head.h"

using namespace std;

// color init
void init_colors() {
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_YELLOW); // name
    init_pair(2, COLOR_RED, COLOR_BLACK);    // for highlight desu
}

// name output
void print_title(WINDOW* win, const string& title) {
    wattron(win, COLOR_PAIR(1) | A_BOLD); // yellow with better text
    int width = getmaxx(win);
    int start_x = (width - title.length()) / 2;
    mvwprintw(win, 1, start_x, "%s", title.c_str());
    wattroff(win, COLOR_PAIR(1) | A_BOLD);
    wrefresh(win);
}

// menu output
void print_menu(WINDOW* menu_win, int highlight, const vector<string>& options) {
    int x = 2, y = 1;
    box(menu_win, 0, 0);
    for (size_t i = 0; i < options.size(); ++i) {
        if (i + 1 == highlight) {
            wattron(menu_win, COLOR_PAIR(2) | A_REVERSE); // red
            mvwprintw(menu_win, y + i, x, "%s", options[i].c_str());
            wattroff(menu_win, COLOR_PAIR(2) | A_REVERSE);
        } else {
            mvwprintw(menu_win, y + i, x, "%s", options[i].c_str());
        }
    }
    wrefresh(menu_win);
}

int gm_start() {
    // initialize ncurses
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    //color added!
    init_colors();

    // get terminal size
    int screen_height, screen_width;
    getmaxyx(stdscr, screen_height, screen_width);

    // title
    string title = "MY GAME MENU";

    // Menu options
    vector<string> options = {"Start Game", "Quit"};
    int highlight = 1;
    int choice = 0;

    // board size
    int title_height = 3;
    int menu_height = options.size() + 2;
    int menu_width = 30;

    // board vecter
    int start_y = (screen_height - (title_height + menu_height)) / 2 + title_height;
    int start_x = (screen_width - menu_width) / 2;

    // nameBoard
    WINDOW* title_win = newwin(title_height, screen_width, start_y - title_height, 0);
    wbkgd(title_win, COLOR_PAIR(1));
    print_title(title_win, title);

    // menu
    WINDOW* menu_win = newwin(menu_height, menu_width, start_y, start_x);
    keypad(menu_win, TRUE);

    // main loop
    while (true) {
        print_menu(menu_win, highlight, options);
        int ch = wgetch(menu_win);
        switch (ch) {
            case KEY_UP:
                if (highlight > 1) highlight--;
                break;
            case KEY_DOWN:
                if (highlight < (int)options.size()) highlight++;
                break;
            case 10: // Enter
                choice = highlight;
                break;
            default:
                break;
        }
        // IF YOU GUYS WANT TO ADD MORE SCENE TELLME kim
        if (choice == 1) {
            run_shelter();
            break;

        }
        else if (choice == 2) {
            clear();
            attron(COLOR_PAIR(1));
            mvprintw(0, 0, "Quitting the Game...");
            attroff(COLOR_PAIR(1));
            refresh();
            sleep(1);
            break;
        }
    }

    endwin();
    return 0;
}