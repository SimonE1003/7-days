//game_start.cpp
// Created by KIMYOUNGSEO on 25. 4. 1.

#include "../include/game_start.h"
#include <unistd.h>
#include "../include/map_head.h"
#include "../include/save_load.h"
#include "../include/game_state.h"
#include "../include/exploration.h"

using namespace std;

// color init
void init_colors() {
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_YELLOW); // name
    init_pair(2, COLOR_RED, COLOR_BLACK);    // for highlight desu
}

// name output
void print_title(WINDOW* win, const string& title, const string& title1, const string& title2, const string& title3, const string& title4, const string& title5) {
    wattron(win, COLOR_PAIR(1) | A_BOLD); // yellow with better text
    int width = getmaxx(win);
    int start_x = (width - title.length()) / 2;
    mvwprintw(win, 1, start_x, "%s", title.c_str());
    mvwprintw(win, 2, start_x, "%s", title1.c_str());
    mvwprintw(win, 3, start_x, "%s", title2.c_str());
    mvwprintw(win, 4, start_x, "%s", title3.c_str());
    mvwprintw(win, 5, start_x, "%s", title4.c_str());
    mvwprintw(win, 6, start_x, "%s", title5.c_str());
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

// returns false(not quit) or True(quit)
bool is_quit() {
    int screen_height, screen_width;
    getmaxyx(stdscr, screen_height, screen_width);
    if (screen_height < 5 || screen_width < 40) return false;

    WINDOW* confirm_win = newwin(5, 40, (screen_height - 5) / 2, (screen_width - 40) / 2);
    if (!confirm_win) return false;

    keypad(confirm_win, TRUE);
    box(confirm_win, 0, 0);

    vector<string> confirm_options = {"Yes, Quit", "No, Go Back"};
    int highlight = 1;
    int choice = 0;

    while (true) {
        werase(confirm_win);
        box(confirm_win, 0, 0);

        mvwprintw(confirm_win, 1, 2, "Are you sure you want to quit?");
        for (size_t i = 0; i < confirm_options.size(); ++i) {
            if (i + 1 == highlight) {
                wattron(confirm_win, COLOR_PAIR(2) | A_REVERSE);
                mvwprintw(confirm_win, 3, 2 + (i * 15), "%s", confirm_options[i].c_str());
                wattroff(confirm_win, COLOR_PAIR(2) | A_REVERSE);
            } else {
                mvwprintw(confirm_win, 3, 2 + (i * 15), "%s", confirm_options[i].c_str());
            }
        }
        wrefresh(confirm_win);

        int ch = wgetch(confirm_win);
        switch (ch) {
            case KEY_LEFT:
                if (highlight > 1) highlight--;
            break;
            case KEY_RIGHT:
                if (highlight < (int)confirm_options.size()) highlight++;
            break;
            case 10:
                choice = highlight;
            break;
            case 27:
                delwin(confirm_win);
            return false;
            default:
                break;
        }

        if (choice != 0) {
            delwin(confirm_win);
            return (choice == 1);
        }
    }
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
    string title  = R"(  ______   _____      __     _______ )";
    string title1 = R"( |____  | |  __ \   /\\ \   / / ____|)";
    string title2 = R"(     / /  | |  | | /  \\ \_/ / (___  )";
    string title3 = R"(    / /   | |  | |/ /\ \\   / \___ \ )";
    string title4 = R"(   / /    | |__| / ____ \| |  ____) |)";
    string title5 = R"(  /_/     |_____/_/    \_\_| |_____/ )";


    // Menu options
    vector<string> options = {"Start Game", "Continue", "Information", "Quit"};
    vector<string> difficulty = {"hard", "normal", "easy"};
    int highlight = 1;
    int choice = 0;

    // board size
    int title_height = 8;
    int menu_height = options.size() + 2;
    int menu_width = 30;

    // board vecter
    int start_y = (screen_height - (title_height + menu_height)) / 2 + title_height;
    int start_x = (screen_width - menu_width) / 2;

    // nameBoard
    WINDOW* title_win = newwin(title_height, screen_width, start_y - title_height, 0);
    wbkgd(title_win, COLOR_PAIR(1));
    print_title(title_win, title, title1 , title2 , title3, title4, title5);

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
                    start_explore();
                    break;
                }
            }

            break;
        }
        // Continue
        else if (choice == 2) {
            load();
            start_explore();  
            break;
        }
        // Information
        else if (choice == 3) {
            clear();
            refresh();
            WINDOW* info_win = newwin(30, 90,
                         (screen_height - 30) / 2,
                         (screen_width - 90) / 2);
            box(info_win, 0, 0);

            // Game information display
            mvwprintw(info_win, 1, 1, "Game Information:");
            mvwprintw(info_win, 3, 1, "Name: Seven Days");
            mvwprintw(info_win, 4, 1, "Group number: 66");
            mvwprintw(info_win, 5, 1, "Authors: KIM YOUNGSEO, LIN CHUNG HAY, SUN JINNAN,");
            mvwprintw(info_win, 6, 1, "        SUN YI-TSEN, WANG YUMING, ZHANG JIAHAO");
            mvwprintw(info_win, 8, 1, "Goal of game: survive 7 days");
            mvwprintw(info_win, 10, 1, "Rules:");
            mvwprintw(info_win, 11, 3, "- You have to control human's basic needs with items");
            mvwprintw(info_win, 13, 1, "Factors influence your survival:");
            mvwprintw(info_win, 14, 3, "* Hunger, Thirst, Sanity, Illness, and other items");
            mvwprintw(info_win, 16, 1, "Game Mechanics:");
            mvwprintw(info_win, 17, 3, "1. After night:");
            mvwprintw(info_win, 18, 5, "- If hunger, thirst, or sanity reaches zero -> health decreases");
            mvwprintw(info_win, 19, 5, "- If illness is above zero -> health decreases");
            mvwprintw(info_win, 20, 3, "2. Through events -> sanity changes");
            mvwprintw(info_win, 21, 3, "3. Collect food/water (automatically used after night)");
            mvwprintw(info_win, 22, 3, "4. No health -> different endings");
            mvwprintw(info_win, 24, 1, "Important Keys:");
            mvwprintw(info_win, 25, 3, "1. In shelter: S->Save  E->Exit");
            mvwprintw(info_win, 26, 3, "2. Outside: S->Story");
            mvwprintw(info_win, 27, 3, "3. Press I to check your status");
            mvwprintw(info_win, 28, 1, "Press any key to continue...");

            wrefresh(info_win);
            wgetch(info_win);
            delwin(info_win);

            clear();
            refresh();
            print_title(title_win, title, title1 , title2 , title3, title4, title5);
            choice = 0;
            continue;
        }
        //Quit
        else if (choice == 4) {
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