#include <ncurses.h>
#include <bits/stdc++.h>

int main() {
    // Initialize ncurses
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE); // Enable function keys and arrow keys

    // Get the size of the window
    int height, width;
    getmaxyx(stdscr, height, width);

    int ch;
    while ((ch = getch()) != 'q') { // Press 'q' to exit the loop
        switch (ch) {
            case KEY_UP:
                mvprintw(0, 0, "Up arrow key pressed");
                break;
            case KEY_DOWN:
                mvprintw(0, 0, "Down arrow key pressed");
                break;
            case KEY_LEFT:
                mvprintw(0, 0, "Left arrow key pressed");
                break;
            case KEY_RIGHT:
                mvprintw(0, 0, "Right arrow key pressed");
                break;
            default:
                mvprintw(0, 0, "Key pressed: %c", ch);
                break;
        }
        refresh();
    }

    // End ncurses mode
    endwin();

    return 0;
}