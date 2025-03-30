#include <ncurses.h>
#include <bits/stdc++.h>//To be updated(when needed head files are clear)

using namespace std;

struct GameState{
    int day, food, water, difficulty, hunger, thirst, health,bullet;
    bool ill;//whether the player is ill
    int story_progress;//an integer to track where the player are on the main story line.
    int items[100];//numbers of items that the player owns
}; GameState gs;

struct Item{//each item owns a unique code and a name.
    int code;
    string name;
}; Item item_list[100];//list of all items that might appear in the game.

void init();//set all variables to initial value and read item_list from a file named "items".
void start();//show the start screen and options.
void load(string file);//if the player choose to load, load gamestate from a file
void save(string file);//save gamestate to a file.
void sixty_sec();//if the player choose to start a new game, do the "sixty seconds".
bool checkgs();//adjust and check the gamestate to determine whether to end the game or not after a day ends.
void start_a_day();
void start_explore();//explore in the daytime

#include "init.h"
#include "game_logic.h"
#include "save_load.h"
#include "game_state.h"


int main() {
    init();

    start();
    
    while (true) {
        start_a_day();
        if (!checkgs()) {
            end();
            break;
        }
        gs.day++;
        if (ask_for_saving()) break;
    }
    
    return 0;
}
