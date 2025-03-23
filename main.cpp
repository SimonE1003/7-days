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