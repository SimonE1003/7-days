#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <string>
#include <vector>

using namespace std;

// Game state structure
struct GameState {
    double day;

=======
    int food, water, difficulty, hunger, thirst, health, sanity, bullet;
>>>>>>> 645e503 (update game_state.cpp and game_state.h,add color to some texts)
    bool ill;
    int story_progress;
    vector <string> items;
};

// Item definition structure
struct Item {
    int code;
    string name;
};

// Global variables (extern declarations)
extern GameState gs;
extern Item item_list[100];

void display_status(GameState gs);

#endif
