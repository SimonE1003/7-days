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

// To Alonso, this is a function that produce the window of is quit and returns false(not quit) or True(quit)
// if you want to just let it quit, remove //
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
                    //run_shelter();
                    start_explore();
                    break;
                }
            }

            break;
        }
        else if (choice == 2) {  // Continue
            load();
            //delwin(diff_win);
            //run_shelter();
            start_explore();  
            break;
        }
        else if (choice == 3) {  // Information
            clear();
            refresh();
            //simplified information display
            WINDOW* info_win = newwin(screen_height, screen_height,0,0);
            box(info_win, 0, 0);
            vector<string> gameInfo = {
                "Game Information:",
                "Name: Seven Days",
                "Group number: 66",
                "Authors: KIM YOUNGSEO, LIN CHUNG HAY, SUN JINNAN, SUN YI-TSEN, WANG YUMING, ZHANG JIAHAO",
                "Goal of game: survive 7 days",
                "Rules:",
                "   - You have to control human's basic needs with items",
                "Factors influence your survival:",
                "  * Hunger, Thirst, Sanity, Illness, and other items",
                "Game Mechanics:",
                "   1. After night:",
                "       - If hunger, thirst, or sanity reaches zero -> health decreases",
                "       - If illness is above zero -> health decreases",
                "   2. Through events -> sanity changes",
                "   3. You can collect food/water to avoid hunger/thirst (automatically used after night)",
                "   4. No health -> different endings",
                "Gameplay:",
                "   1. Day time: Go out and collect items",
                "   2. Night time: Important story happens at shelter",
                "   3. Both night/day show 1 story",
                "   4. After 7 days something happens - prepare well",
                "Important Keys:",
                "   1. In shelter: - S -> Save - E -> Exit",
                "   2. Outside: - S -> Story",
                "   3. Press I to check your status"
            };
            int y = 1;
            for (const auto& line : gameInfo) {
                mvwprintw(info_win, y++, 2, "%s", line.c_str());
            }
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