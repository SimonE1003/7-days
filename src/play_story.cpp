#include <ncurses.h>
#include <vector>  // For vector
#include <string>  // For string
#include "../include/map_head.h"
#include "../include/game_state.h"
#include "../include/game_logic.h"
#include <iostream>
#include <ctime>
#include <sstream>
#include <utility>
#include <cstdlib> // For srand and rand
#include <algorithm> // For sample
#include <random> // For default_random_engine
#include <set>
using namespace std;

/*example usage of the function
stats effect: story_effect("health", 10)
inventory effect: story_effect("inventory", "item")*/

bool story_effect(const string& type, const int&value){
    if (type == "health"){ // Update health point
        gs.health += value;
        if (gs.health <= 0) return false; // Prevent negative health
        return true;
    } else if (type == "food") {
        gs.food += value; // Update food count
        if (gs.food <= 0) return false; // Prevent negative food
        return true;
    } else if (type == "water") {
        gs.water += value; // Update water count
        if (gs.water <= 0) return false; // Prevent negative water
        return true;
    } 
    else if (type == "sanity"){
        gs.sanity += value; // Update sanity level
        if (gs.sanity <= 0) return false; // Prevent negative sanity
        return true;
    } 
    else if (type == "hunger") {
        gs.hunger += value; // Update hunger level
        if (gs.hunger <= 0) return false; // Prevent negative hunger
        return true;
    } 
    else if (type == "thirst") {
        gs.thirst += value; // Update thirst level
        if (gs.thirst <= 0) return false; // Prevent negative thirst
        return true;
    }
    else if (type == "bullet") {
        gs.bullet += value;
        if (gs.bullet < 0) {
            gs.bullet -= value;
            return false;
        }
        return true;
    }
    else if (type == "startstory"){
        hospital_head_story.push_back(value);
    }
    return true;
}

void story_effect(const string&type, const string& item){
    if (type == "inventory"){
        gs.items.push_back(item);
    }
    
}

pair<string, string> interpret_reward(const string& reward){
    string type;
    string value;

    // use stringstream to split the string
    stringstream ss(reward);
    ss >> type; // extract the type like health or inventory
    getline(ss, value); // extract the rest of the string, which is the value

    // remove the spaces infront of the value
    if (!value.empty() && value[0]==' '){
        value = value.substr(1);
    }
    return {type, value};
}
vector<story*> weaponshop_story;
vector<story*> hospital_story;
vector<story*> supermarket_story;
vector<story_spot> story_spots;
vector<story*> UI_stories;
vector<story*> sample( int num, string current_map) {
    if (current_map == "hospital"){
        vector<story*> selected_stories;
        srand(time(0));
        random_shuffle(hospital_head_story.begin(), hospital_head_story.end());
        for (int i = 0; i < num; i++) {
            selected_stories.push_back(hospital_story[hospital_head_story[hospital_head_story.size()-1-i]]);
            
        }
        for (int i = 0; i < num; i++) {
            hospital_head_story.pop_back();
            
        }
        return selected_stories;
    }
    /*if (current_map == "hospital") {
        vector<story*> selected_stories;

        // Ensure story 17 is included
        if (hospital_story.size() > 0) {
            selected_stories.push_back(hospital_story[0]);
            num--; // Reduce the number of remaining stories to select
        }

        // Shuffle and select the remaining stories
        srand(time(0));
        random_shuffle(hospital_head_story.begin(), hospital_head_story.end());
        for (int i = 0; i < num && i < hospital_head_story.size(); i++) {
            selected_stories.push_back(hospital_story[hospital_head_story[hospital_head_story.size() - 1 - i]]);
        }

        // Remove the selected stories from the pool
        for (int i = 0; i < num; i++) {
            hospital_head_story.pop_back();
        }

        return selected_stories;
    }*/
    else if (current_map == "supermarket"){
        vector<story*> selected_stories;
        srand(time(0));
        random_shuffle(supermarket_head_story.begin(), supermarket_head_story.end());
        for (int i = 0; i < num; i++) {
            selected_stories.push_back(supermarket_story[supermarket_head_story[supermarket_head_story.size()-1-i]]);
            
        }
        for (int i = 0; i < num; i++) {
            supermarket_head_story.pop_back();
            
        }
        return selected_stories;
    }
    else if (current_map == "weaponshop"){
        vector<story*> selected_stories;
        srand(time(0));
        random_shuffle(weaponshop_head_story.begin(), weaponshop_head_story.end());
        for (int i = 0; i < num; i++) {
            selected_stories.push_back(weaponshop_story[weaponshop_head_story[weaponshop_head_story.size()-1-i]]);
            
        }
        for (int i = 0; i < num; i++) {
            weaponshop_head_story.pop_back();
            
        }
        return selected_stories;
    }
    return vector<story*>(); // Return an empty vector if no valid map is found
}
void create_story_spot(int num, int original_x, int original_y, int height, int width, vector<vector<char>> map,string current_map) {
    story_spots={};
    srand(time(0));
    if (current_map == "hospital") {
        vector<story*> selected_stories = sample( num, current_map);

        for (int i = 0; i < num; i++) {
            story_spot ST;
            ST.target_story = selected_stories[i];
            ST.x = rand() % (height-1) + original_x + 1;
            ST.y = rand() % width + original_y;
            set <char> valid = { 'D', 'o', 'r'};
            while (map[ST.x-original_x][ST.y-original_y] == '#' or valid.find(map[ST.x-original_x][ST.y-original_y]) != valid.end()) {
                ST.x = rand() % (height-1) + original_x + 1;
                ST.y = rand() % width + original_y;
            }
            ////cout << ST.x << " " << ST.y << endl;
            story_spots.push_back(ST);
            
        }
        //mvprintw(5, 0, "%zu", story_spots.size());
    }
    if (current_map == "supermarket"){
        vector<story*> selected_stories = sample( num, current_map);

        for (int i = 0; i < num; i++) {
            story_spot ST;
            ST.target_story = selected_stories[i];
            ST.x = rand() % (height-1) + original_x + 1;
            ST.y = rand() % width + original_y;
            set <char> valid = { 'D', 'o', 'r'};
            while (map[ST.x-original_x][ST.y-original_y] == '#' or valid.find(map[ST.x-original_x][ST.y-original_y]) != valid.end()) {
                ST.x = rand() % (height-1) + original_x + 1;
                ST.y = rand() % width + original_y;
            }
            ////cout << ST.x << " " << ST.y << endl;
            story_spots.push_back(ST);
            
        }
        //w(5, 0, "%zu", story_spots.size());
    }
    if (current_map == "weaponshop"){
        vector<story*> selected_stories = sample( num, current_map);

        for (int i = 0; i < num; i++) {
            story_spot ST;
            ST.target_story = selected_stories[i];
            ST.x = rand() % (height-1) + original_x + 1;
            ST.y = rand() % width + original_y;
            set <char> valid = { 'D', 'o', 'r'};
            while (map[ST.x-original_x][ST.y-original_y] == '#' or valid.find(map[ST.x-original_x][ST.y-original_y]) != valid.end()) {
                ST.x = rand() % (height-1) + original_x + 1;
                ST.y = rand() % width + original_y;
            }
            ////cout << ST.x << " " << ST.y << endl;
            story_spots.push_back(ST);
            
        }
        //mvprintw(5, 0, "%zu", story_spots.size());
    }
}

void play_story(story* current_story, int height, int width, string& rewardPrint) {
    string current_map = "Story";
    clear();
    display_topleft_corner(gs, current_map);
    refresh();
    if (current_story == nullptr) {
        return;
    }
    int playcnt = 0;
    int ch;
    int play_pos = 0;
    int original_point[2] = {height / 3, int((width - current_story->text.size()) / 2)};
    int choice = 0;
    while ((ch = getch()) != 'q') { // Press 'q' to exit the loop
        if (play_pos < current_story->text.size()) {
            mvprintw(original_point[0], original_point[1] + play_pos, "%c", current_story->text[play_pos]);
            play_pos++;
            refresh();
            playcnt = 0;
        } else if (play_pos == current_story->text.size()) {
            for (int k = 0; k < current_story->options.size(); k++) {
                mvprintw(original_point[0] * 2 + k, original_point[1], "%s", current_story->options[k].c_str());
            }
            mvprintw(original_point[0] * 2, original_point[1] - 3, "%s", "->");
            play_pos++;
            refresh();
        }

        switch (ch) {
            case KEY_UP:
                if (choice > 0) {
                    mvprintw(original_point[0] * 2 + choice, original_point[1] - 3, "%s", "  ");
                    choice--;
                    mvprintw(original_point[0] * 2 + choice, original_point[1] - 3, "%s", "->");
                    refresh();
                }
                break;

            case KEY_DOWN:
                if (choice < current_story->options.size() - 1) {
                    mvprintw(original_point[0] * 2 + choice, original_point[1] - 3, "%s", "  ");
                    choice++;
                    mvprintw(original_point[0] * 2 + choice, original_point[1] - 3, "%s", "->");
                    refresh();
                }
                break;

            case '\n':
                bool proceed = true; // track if the player can proceed
                if (current_story != nullptr && choice >= 0 && choice < current_story->next.size() && current_story->next[choice] != nullptr) {
                    story* next_story = current_story->next[choice];
                    if (next_story->options.size() == 1) {
                        int temp_bullet = gs.bullet;
                        if (!next_story->reward.empty()) {
                            for (const string& reward : next_story->reward) {
                                pair<string, string> result = interpret_reward(reward);
                                string type = result.first;
                                string value = result.second;
    
                                if (type == "bullet"){
                                    temp_bullet += stoi(value);
                                    if (temp_bullet < 0) {
                                        proceed = false;
                                        mvprintw(original_point[0] * 2 + choice, original_point[1] + 20, "(Insufficient stats!, please choose again)");
                                        refresh();
                                        break;
                                    }
                                }
                                if (type == "inventory-"){
                                    bool found = false;
                                    for (auto it = gs.items.begin(); it != gs.items.end(); ++it) {
                                        if (*it == value) {
                                            gs.items.erase(it);
                                            found = true;
                                            break;
                                        }
                                    }
                                    if (!found) {
                                        proceed = false;
                                        mvprintw(original_point[0] * 2 + choice, original_point[1] + 20, "(Item not found!, please choose again)");
                                        refresh();
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }


                if (!current_story->reward.empty()) {
                    for (const string& reward : current_story->reward) {
                        pair<string, string> result = interpret_reward(reward);
                        string type = result.first;
                        string value = result.second;

                        if (type == "inventory") {
                            story_effect(type, value); // Inventory rewards
                            rewardPrint += reward + ", ";
                        } else if (type == "health" || type == "food" || type == "water" || type == "bullet" || type == "sanity") {
                            if (story_effect(type, stoi(value))) rewardPrint += reward + ", ";
                            else if (type == "health") end(6);
                            else if (type == "sanity") end(3);
                        } 
                        else if (type == "death") end(7);
                        else if (type == "startstory"){
                            story_effect(type, value); // Start story rewards
                        }
                        else {
                            rewardPrint += reward + ", ";
                        }
                    }

                }
                // Display the reward
                if (!rewardPrint.empty() && (current_story->next.empty() || current_story->next[0] == nullptr)) {
                    if (!rewardPrint.empty() && rewardPrint.length() > 2) {
                        rewardPrint = rewardPrint.substr(0, rewardPrint.length() - 2); // Remove trailing ", "
                    }
                    cleanwholescreen(height, width);
                    display_topleft_corner(gs, current_map);
                    refresh();
                    mvprintw(height / 2, (width - rewardPrint.length() - 6) / 2, "Added %s", rewardPrint.c_str());
                    mvprintw(height / 2 + 2, (width - 24) / 2, "Press Enter to continue...");
                    refresh();
                    while ((ch = getch()) != '\n') {
                        continue; // Wait for the user to press Enter
                    }
                    rewardPrint.clear();
                }
                if (!proceed) {
                    break;
                }
                // Ensure choice is within bounds before proceeding
                if (choice >= 0 && choice < current_story->next.size()) {
                    play_story(current_story->next[choice], height, width, rewardPrint);
                }
                return;
        }
    }
    clear();
    display_topleft_corner(gs, current_map);
    refresh();
}

