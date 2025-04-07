#include "../include/save_load.h"
#include "../include/game_state.h"
#include "../include/game_start.h"
#include "../include/map_head.h"
#include <ncurses.h>
#include <string>
#include <fstream>
#include <unistd.h>
#include <dirent.h>  // For directory reading on Linux/macOS

// Function to get list of save files with a specific extension
std::vector<std::string> get_save_files(const std::string& directory, const std::string& extension = ".save") {
    std::vector<std::string> files;
    DIR* dir = opendir(directory.c_str());
    if (dir) {
        struct dirent* entry;
        while ((entry = readdir(dir)) != nullptr) {
            std::string filename = entry->d_name;
            // Check if file ends with the specified extension
            if (filename.length() >= extension.length() && 
                filename.compare(filename.length() - extension.length(), extension.length(), extension) == 0) {
                files.push_back(filename);
            }
        }
        closedir(dir);
    }
    return files;
}

void load() {
    // Define directory to look for save files
    std::string directory = "save";

    // Get list of save files
    std::vector<std::string> save_files = get_save_files(directory);
    if (save_files.empty()) {
        mvprintw(LINES-1, 0, "No save files found!");
        refresh();
        return;
    }

    // Define window dimensions
    int height = save_files.size() + 4;  // Room for border and instructions
    int width = 60;
    int start_y = (LINES - height) / 2;  // Center vertically
    int start_x = (COLS - width) / 2;    // Center horizontally

    // Create selection window
    WINDOW *load_win = newwin(height, width, start_y, start_x);
    box(load_win, 0, 0);
    mvwprintw(load_win, 1, 2, "Select a save file to load from:");
    mvwprintw(load_win, height-2, 2, "Use arrows, Enter to load, ESC to cancel");
    wrefresh(load_win);

    // Menu variables
    int highlight = 0;  // Index of highlighted item
    int ch;

    // Main selection loop
    keypad(load_win, TRUE);  // Enable arrow keys
    while (true) {
        // Display save files with highlighting
        for (size_t i = 0; i < save_files.size(); ++i) {
            if (i == highlight) {
                wattron(load_win, A_REVERSE);  // Highlight selected item
            }
            mvwprintw(load_win, i + 2, 2, "%s", save_files[i].c_str());
            wattroff(load_win, A_REVERSE);
        }
        wrefresh(load_win);

        // Get user input
        ch = wgetch(load_win);
        switch (ch) {
            case KEY_UP:
                if (highlight > 0) highlight--;  // Move up
                break;
            case KEY_DOWN:
                if (highlight < save_files.size() - 1) highlight++;  // Move down
                break;
            case 10:  // Enter key
            {
                std::string filename = save_files[highlight];
                std::ifstream load_file(directory + "/" + filename, std::ios::binary);
                if (load_file.is_open()) {
                    /*
                    struct GameState {
                        double day;
                        int food, water, difficulty, hunger, thirst, health, sanity, bullet;
                        bool ill;
                        vector <string> items;
                    };
                    extern vector<int> hospital_head_story， supermarket_head_story， weaponstore_head_story;
                    */
                    int ill;
                    load_file>>gs.day>>gs.food>>gs.water>>gs.difficulty>>gs.hunger>>gs.thirst>>gs.health>>gs.sanity>>gs.bullet
                        >>ill;
                    gs.ill = ill?true:false;
                    string item;
                    while (load_file>>item) {
                        if (item == "END_OF_ITEMS") {
                            break;
                        } else{
                            gs.items.push_back(item);
                        }
                    }
                    int head;
                    while (load_file>>head) {
                        if (head == -1) {
                            break;
                        } else{
                            hospital_head_story.push_back(head);
                        }
                    }
                    while (load_file>>head) {
                        if (head == -1) {
                            break;
                        } else{
                            supermarket_head_story.push_back(head);
                        }
                    }
                    while (load_file>>head) {
                        if (head == -1) {
                            break;
                        } else{
                            weaponstore_head_story.push_back(head);
                        }
                    }
                    load_file.close();
                    delwin(load_win);
                    clear();
                    mvprintw(LINES-1, 0, "Game loaded from %s", filename.c_str());
                    refresh();
                    sleep(0.5);
                    return;  // Exit after successful load
                } else {
                    delwin(load_win);
                    clear();
                    mvprintw(LINES-1, 0, "Error: Could not load %s", filename.c_str());
                    refresh();
                    gm_start();
                    return;
                }
            }
            case 27:  // ESC key
                delwin(load_win);
                clear();
                mvprintw(LINES-1, 0, "Load cancelled");
                refresh();
                gm_start();
                return;  // Exit without loading
        }
    }
}

void save() {
    // Define dimensions and position for the new window
    int height = 5;
    int width = 40;
    int start_y = (LINES - height) / 2;  // Center vertically on screen
    int start_x = (COLS - width) / 2;    // Center horizontally on screen

    // Create a new window
    WINDOW *save_win = newwin(height, width, start_y, start_x);
    
    // Draw border and display prompt messages
    box(save_win, 0, 0);
    mvwprintw(save_win, 1, 2, "Enter filename to save game");
    mvwprintw(save_win, 2, 2, "(Enter empty filename to cancel):");
    wrefresh(save_win);

    // Create input area
    WINDOW *input_win = newwin(1, width-4, start_y+3, start_x+2);
    wrefresh(input_win);

    // Enable keyboard input
    echo();
    curs_set(1);

    std::string filename;
    char input[256] = {0};  

    
    mvwprintw(input_win, 0, 0, "");  
    wrefresh(input_win);
    int result = wgetnstr(input_win, input, 255);  

    
    if (result == ERR || input[0] == '\0') {
        
        delwin(input_win);
        delwin(save_win);
        noecho();
        curs_set(0);
        mvprintw(LINES-1, 0, "Save cancelled");
        refresh();
        sleep(2);
        return;
    } else if (std::string(input).find('/') != std::string::npos) {
        // Check if input contains '/', reject it if so
        delwin(input_win);
        delwin(save_win);
        noecho();
        curs_set(0);
        mvprintw(LINES-1, 0, "Error: Filename cannot contain '/'");
        refresh();
        napms(1000);  // Show error message for 1 second
        clear();
        refresh();
        return;
    } else {
        filename = std::string(input); 
    }

    // Clean up windows
    delwin(input_win);
    delwin(save_win);
    noecho();
    curs_set(0);
    const std::string save_dir = "save";
    
    // Save game data to file
    if (!filename.empty()) {
        const std::string extension = ".save";
        if (filename.length() < extension.length() || 
            filename.compare(filename.length() - extension.length(), extension.length(), extension) != 0) {
            filename += extension;  // Append ".save" if not already present
        }
        std::string full_path = save_dir + "/" + filename;
        std::ofstream save_file(full_path);
        /*
        struct GameState {
            double day;
            int food, water, difficulty, hunger, thirst, health, sanity, bullet;
            bool ill;
            vector <string> items;
        };
        extern vector<int> hospital_head_story， supermarket_head_story， weaponstore_head_story;
        */
        if (save_file.is_open()) {
            save_file<<gs.day<<endl<<gs.food<<endl<<gs.water<<endl<<gs.difficulty<<endl<<gs.hunger<<endl
                <<gs.thirst<<endl<<gs.health<<endl<<gs.sanity<<endl<<gs.bullet<<endl<<(gs.ill ? 1:0)<<endl;
            for (auto it = gs.items.begin(); it!= gs.items.end(); it++) {
                save_file<<*it<<endl;
            }
            save_file<<"END_OF_ITEMS"<<endl;
            for (auto it = hospital_head_story.begin(); it!= hospital_head_story.end(); it++) {
                save_file<<*it<<endl;
            }
            save_file<<-1<<endl;
            for (auto it = supermarket_head_story.begin(); it!= supermarket_head_story.end(); it++) {
                save_file<<*it<<endl;
            }
            save_file<<-1<<endl;
            for (auto it = weaponstore_head_story.begin(); it!= weaponstore_head_story.end(); it++) {
                save_file<<*it<<endl;
            }
            save_file<<-1<<endl;
            save_file.close();
            mvprintw(LINES-1, 0, "Game saved to %s", filename.c_str());
            refresh();
            sleep(1);
        } else {
            // Display error message if save fails
            mvprintw(LINES-1, 0, "Error: Could not save to %s", filename.c_str());
            refresh();
            sleep(1);
        }
    }
}
