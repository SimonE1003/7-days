#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <string>

using namespace std;

// Game state structure
struct GameState {
    int day, food, water, difficulty, hunger, thirst, health,sanity;
    bool ill;
    int story_progress;
    int items[100];
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