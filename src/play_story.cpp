#include <ncurses.h>
#include <vector>  // For vector
#include <string>  // For string
#include "../include/map_head.h"
#include "../include/game_state.h"
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

void story_effect(const string& type, const int&value){
    if (type == "health"){ // Update health point
        gs.health += value;
        if (gs.health < 0) gs.health = 0; // Prevent negative health
    } else if (type == "food") {
        gs.food += value; // Update food count
        if (gs.food < 0) gs.food = 0; // Prevent negative food
    } else if (type == "water") {
        gs.water += value; // Update water count
        if (gs.water < 0) gs.water = 0; // Prevent negative water
    } else if (type == "bullet") {
        gs.bullet += value;
        if (gs.bullet < 0) gs.bullet =0;
    }
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
            cout << ST.x << " " << ST.y << endl;
            story_spots.push_back(ST);
            
        }
        mvprintw(5, 0, "%zu", story_spots.size());
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
            cout << ST.x << " " << ST.y << endl;
            story_spots.push_back(ST);
            
        }
        mvprintw(5, 0, "%zu", story_spots.size());
    }
}

void play_story(story* current_story, int height, int width) {
    clear();
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
            mvprintw(original_point[0] * 2 , original_point[1] - 3, "%s", "->");

            play_pos++;
            refresh();
        }
        switch (ch){
            case KEY_UP:
                if (choice > 0){
                    mvprintw(original_point[0] * 2 + choice, original_point[1] - 3, "%s", "  ");
                    choice--;
                    mvprintw(original_point[0] * 2 + choice, original_point[1] - 3, "%s", "->");
                    refresh();

                }
                break;
            case KEY_DOWN:
                if (choice < current_story->options.size() - 1){
                    mvprintw(original_point[0] * 2 + choice, original_point[1] - 3, "%s", "  ");
                    choice++;
                    mvprintw(original_point[0] * 2 + choice, original_point[1] - 3, "%s", "->");
                    refresh();
                }
                break;
            case '\n':
                if (!current_story->reward.empty()) {
                    if (current_story->reward[0] == "start story 11"){
                        hospital_head_story.push_back(11);
                    }
                    else{
                        for (const string& reward: current_story->reward){
                            pair<string,string> result = interpret_reward(reward);
                            string type = result.first;
                            string value = result.second;

                            if (type == "inventory") {
                                story_effect(type, value); // Inventory rewards
                                cleanwholescreen(height, width);
                                mvprintw(height / 3, (width - current_story->reward.size()) / 2, "Added %s into your inventory", value.c_str());
                                mvprintw(height / 2, (width - current_story->reward.size()) / 2, "Press Enter to continue");
                            } else if (type == "health" || type == "food" || type == "water" || type == "bullet") {
                                try {
                                    story_effect(type, stoi(value)); // Numeric rewards
                                    cleanwholescreen(height,width);
                                    mvprintw(height / 3, (width - current_story->reward.size()) / 2, "%s %s", type.c_str(), value.c_str());
                                    mvprintw(height / 2, (width - current_story->reward.size()) / 2, "Press Enter to continue");
                                } catch (const invalid_argument& e) {
                                    mvprintw(height / 3, (width - current_story->reward.size()) / 2, "Invalid numeric reward: %s", value.c_str()); //for debugging purposes
                                }
                            } else {
                                // Display the message
                                cleanwholescreen(height, width);
                                mvprintw(height / 3, (width - current_story->reward.size()) / 2, "%s", reward.c_str());
                                mvprintw(height / 2, (width - current_story->reward.size()) / 2, "Press Enter to continue");
                            }
                        }
                    }
                    refresh();
                    while (getch() != '\n' && getch() != 'q') {
                        continue;
                    }
                }

                // Ensure choice is within bounds before proceeding
                if (choice >= 0 && choice < current_story->next.size()) {
                    play_story(current_story->next[choice], height, width);
                }
                return;
                break;
        }
    }
    clear();
    

    
    clear();
    refresh();
}

