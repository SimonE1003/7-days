#include <ncurses.h>
#include <vector>  // For vector
#include <string>  // For string
#include "map_head.h"
#include <iostream>
#include <ctime>
#include <cstdlib> // For srand and rand
#include <algorithm> // For sample
#include <random> // For default_random_engine
using namespace std;

vector<story*> hospital_story;
vector<story_spot> story_spots;
vector<story*> sample( int num) {
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
void create_story_spot(int num, int original_x, int original_y, int height, int width, vector<vector<char>> map,string current_map) {
    story_spots={};
    srand(time(0));
    if (current_map == "hospital") {
        vector<story*> selected_stories = sample( num);

        for (int i = 0; i < num; i++) {
            story_spot ST;
            ST.target_story = selected_stories[i];
            ST.x = rand() % (height-1) + original_x + 1;
            ST.y = rand() % width + original_y;
            while (map[ST.x-original_x][ST.y-original_y] == '#') {
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
                
                if (current_story -> reward == "start story 11"){
                    hospital_head_story.push_back(11);
                    
                }
                /*if (current_story -> reward != ""){
                    mvprintw(height / 3, (width - current_story->reward.size()) / 2, "%s", current_story->reward.c_str());
                    mvprintw(height / 2, (width - current_story->reward.size()) / 2, "Press Enter to continue");
                    refresh();
                    while(getch() != '\n' and getch() != 'q'){
                        continue;
                    }
                }*/
                play_story(current_story->next[choice], height, width);
                return;
                break;
        }
    }
    clear();
    

    
    clear();
    refresh();
}

