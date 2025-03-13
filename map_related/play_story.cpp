#include <ncurses.h>
#include <bits/stdc++.h>
#include "map_head.h"
using namespace std;

struct story {
    string text;
    vector<string> options;
    vector<story*> next;
    string reward="";
};

vector<story*> hospital_story;

void initialize_stories() {
    hospital_story.push_back(new story);
    hospital_story[0]->text = "You are in a hospital. You see a nurse.";
    hospital_story[0]->options.push_back("Talk to the nurse");
    hospital_story[0]->options.push_back("Ignore the nurse");
    
    //hospital_story[0]->reward = "bandage";

    hospital_story.push_back(new story);
    hospital_story[1]->text = "The nurse tells you that you are in a hospital. She asks you if you are feeling better.";
    hospital_story[1]->options.push_back("End conversation");
    hospital_story[1]->next.push_back(nullptr);
    hospital_story[1]->reward = "health";

    hospital_story.push_back(new story);
    hospital_story[2]->text = "nothing happened then";
    hospital_story[2]->options.push_back("End conversation");
    hospital_story[2]->next.push_back(nullptr);
    hospital_story[2]->reward = "no reward";

    hospital_story[0]->next = vector<story*>{hospital_story[1], hospital_story[2]};

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
                play_story(current_story->next[choice], height, width);
                return;
                break;
        }
    }
    clear();
    if (current_story -> reward != ""){
        mvprintw(height / 3, (width - current_story->reward.size()) / 2, "%s", current_story->reward.c_str());
        mvprintw(height / 2, (width - current_story->reward.size()) / 2, "Press Enter to continue");
        refresh();
        while(getch() != '\n' and getch() != 'q'){
            continue;
        }
    }

    
    clear();
    refresh();
}

