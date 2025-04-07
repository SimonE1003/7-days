//game_start.cpp
// Created by KIMYOUNGSEO on 25. 4. 1.

#include "../include/game_start.h"
#include <unistd.h>
#include "../include/map_head.h"
#include "../include/save_load.h"
#include "../include/game_state.h"

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
    vector<string> options = {"Start Game", "Continue", "Information", "Quit"};
    vector<string> difficulty = {"hard", "normal", "easy"};
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
            case 10:
                choice = highlight;
                break;
            default:
                break;
        }

        if (choice == 1) {  // Start Game
            clear();
            refresh();
            //Added difficulty selection before starting game
            WINDOW* diff_win = newwin(difficulty.size() + 2, menu_width,
                                     (screen_height - difficulty.size()) / 2,
                                     (screen_width - menu_width) / 2);
            keypad(diff_win, TRUE);
            int diff_highlight = 1;
            int diff_choice = 0;

            while (true) {
                print_menu(diff_win, diff_highlight, difficulty);
                int ch = wgetch(diff_win);
                switch (ch) {
                    case KEY_UP:
                        if (diff_highlight > 1) diff_highlight--;
                        break;
                    case KEY_DOWN:
                        if (diff_highlight < (int)difficulty.size()) diff_highlight++;
                        break;
                    case 10:
                        diff_choice = diff_highlight;
                        break;
                    default:
                        break;
                }

                if (diff_choice != 0) {
                    //Proper difficulty values assigned
                    switch (diff_choice) {
                        case 1: gs.difficulty = 2; break;  // Hard
                        case 2: gs.difficulty = 1; break;  // Normal
                        case 3: gs.difficulty = 0; break;  // Easy
                    }
                    delwin(diff_win);
                    run_shelter();
                    break;
                }
            }

            break;
        }
        else if (choice == 2) {  // Continue
            load();
            //delwin(diff_win);
            run_shelter();
                
            break;
        }
        else if (choice == 3) {  // Information
            clear();
            refresh();
            //simplified information display
            WINDOW* info_win = newwin(30, 90,
                                     (screen_height - 30) / 2,
                                     (screen_width - 90) / 2);
            box(info_win, 0, 0);
            mvwprintw(info_win, 1, 1, "Game Information:");
            mvwprintw(info_win, 3, 1, "Goal of game: survive 7days");
            mvwprintw(info_win, 4, 1, "Rule: you have to control human's basic need with items");
            mvwprintw(info_win, 5, 1, "Basically, in the morning you have to collect and follow main story at night");
            mvwprintw(info_win, 6, 1, "Special keys and points: ");
            mvwprintw(info_win, 7, 1, "Name: IDK");
            mvwprintw(info_win, 8, 1, "Author: Group6");
            mvwprintw(info_win, 11, 1, "Press any key to continue...");
            wrefresh(info_win);
            wgetch(info_win);
            delwin(info_win);

            clear();
            refresh();
            print_title(title_win, title);
            choice = 0;  // Return to main menu
            continue;
        }
        else if (choice == 4) {  // Quit
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