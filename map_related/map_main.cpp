#include <ncurses.h>
#include <bits/stdc++.h>

int main() {
    // Initialize ncurses
    initscr();
    noecho();
    curs_set(FALSE);

    // Get the size of the window
    int height, width;
    getmaxyx(stdscr, height, width);

    // Draw the axes
    for (int i = 0; i < width; ++i) {
        mvprintw(height / 2, i, "-");
    }
    for (int i = 0; i < height; ++i) {
        mvprintw(i, width / 2, "|");
    }

    // Draw a simple graph (y = x^2)
    for (int x = -width / 2; x < width / 2; ++x) {
        int y = (x * x) / 10; // Scale down for visibility
        if (height / 2 - y >= 0 && height / 2 - y < height) {
            mvprintw(height / 2 - y, width / 2 + x, "*");
        }
    }

    // Refresh the screen to show the graph
    refresh();

    // Wait for user input
    getch();

    // End ncurses mode
    endwin();

    return 0;
}
//cd /mnt/c/Users/User/Onedrive/1340/Project-Repo/map_related