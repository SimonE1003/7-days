#include <ncurses.h>
#include <bits/stdc++.h>
#include "map_head.h"
using namespace std;





void clearnear(int x, int y, vector<vector<char>> map) {
    
    int newX = x;
    int newY = y ;
    if (newX >= 0 && newX < map.size() && newY >= 0 && newY < map[0].size()) {
        mvprintw(newX, newY, "%c",map[newX][newY]);
    }
    else{
        mvprintw(newX, newY, "+");
    }

}
void drawmap(vector<vector<char>> map){
    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[i].size();j++){
            mvprintw(i,j,"%c",map[i][j]);
            
        }
    }
}
int main() {
    // Initialize ncurses
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE); // Enable function keys and arrow keys
    nodelay(stdscr, TRUE); // Make getch() non-blocking
    // Get the size of the window
    int height, width;
    getmaxyx(stdscr, height, width);
    vector<vector<char>> map = string_to_vector(map1);
    int ch;
    int charactorpos[2] = {height / 2, width / 2};
    mvprintw(charactorpos[0], charactorpos[1], "X");
    drawmap(map);
    mvprintw(3,0,"map size: %d %d",map.size(),map[0].size());
    while ((ch = getch()) != 'q') { // Press 'q' to exit the loop
        clearnear(charactorpos[0],charactorpos[1],map);
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
            case ERR:
                break;
            default:
                mvprintw(0, 0, "Key pressed: %c       ", ch);
                break;
        }
        
        mvprintw(charactorpos[0], charactorpos[1], "X");
        mvprintw(1, 0, "Position: %d, %d      ", charactorpos[0], charactorpos[1]);
        mvprintw(2, 0, "Window size: %d, %d", height, width);
        refresh();
    }

    // End ncurses mode
    endwin();

    return 0;
}

// cd /mnt/c/Users/User/OneDrive/1340/Project-Repo