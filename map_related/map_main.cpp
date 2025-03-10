#include <ncurses.h>
#include <bits/stdc++.h>
using namespace std;
void clearnear(int x,int y){
    mvprintw(x,y," ");
    mvprintw(x+1,y," ");
    mvprintw(x-1,y," ");
    mvprintw(x,y+1," ");
    mvprintw(x,y-1," ");
    mvprintw(x+1,y+1," ");
    mvprintw(x+1,y-1," ");
    mvprintw(x-1,y+1," ");
    mvprintw(x-1,y-1," ");
}
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
    int charactorpos[2] = {height / 2, width / 2};
    mvprintw(charactorpos[0], charactorpos[1], "X");
    while ((ch = getch()) != 'q') { // Press 'q' to exit the loop
        switch (ch) {
            case KEY_UP:
                mvprintw(0, 0, "Up arrow key pressed");
                charactorpos[0] -= 1;
                break;
            case KEY_DOWN:
                mvprintw(0, 0, "Down arrow key pressed");
                charactorpos[0] += 1;
                break;
            case KEY_LEFT:
                mvprintw(0, 0, "Left arrow key pressed");
                charactorpos[1] -= 1;
                break;
            case KEY_RIGHT:
                mvprintw(0, 0, "Right arrow key pressed");
                charactorpos[1] += 1;
                break;
            default:
                mvprintw(0, 0, "Key pressed: %c       ", ch);
                break;
        }
        clearnear(charactorpos[0],charactorpos[1]);
        mvprintw(charactorpos[0], charactorpos[1], "X");
        mvprintw(1, 0, "Position: %d, %d", charactorpos[0], charactorpos[1]);
        refresh();
    }

    // End ncurses mode
    endwin();

    return 0;
}

// cd /mnt/c/Users/User/OneDrive/1340/Project-Repo