#include "../include/ui_utils.h"
#include <ncurses.h>

bool ask_for_saving() { 
    // Get terminal dimensions
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    // Define the prompt message
    const char* prompt = "Save game? (Y/N)";
    int prompt_len = strlen(prompt);

    // Calculate window dimensions (including borders)
    int win_width = prompt_len + 4;  // 2 characters padding on each side
    int win_height = 5;

    // Boundary check: Ensure the window does not exceed screen dimensions
    win_width = std::min(win_width, max_x - 4);
    win_height = std::min(win_height, max_y - 4);

    // Calculate window position (centered)
    int start_y = (max_y - win_height) / 2;
    int start_x = (max_x - win_width) / 2;

    // Create a new window
    WINDOW* win = newwin(win_height, win_width, start_y, start_x);
    keypad(win, TRUE);  // Enable function keys
    box(win, 0, 0);     // Draw a border

    // Display the prompt message centered in the window
    mvwprintw(win, win_height/2, (win_width - prompt_len)/2, "%s", prompt);
    wrefresh(win);

    // Handle user input
    bool result = false;
    while (true) {
        int ch = wgetch(win);
        switch (tolower(ch)) {
            case 'y': 
                result = true;
                goto cleanup;
            case 'n':
                result = false;
                goto cleanup;
            case KEY_RESIZE:  // Handle window resize events
                redrawwin(stdscr);
                refresh();
                break;
        }
    }

cleanup:
    // Clean up the window
    delwin(win);
    touchwin(stdscr);  // Mark the main window for refresh
    refresh();         // Refresh the main window

    return result;
}