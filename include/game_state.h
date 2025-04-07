#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <string>
#include <vector>

using namespace std;

// Game state structure
struct GameState {
    double day;
    int food, water, difficulty, hunger, thirst, health, sanity, bullet;
    bool ill;
    vector <string> items;
};

// Global variables (extern declarations)
extern GameState gs;

void display_status(GameState gs);

#endif
