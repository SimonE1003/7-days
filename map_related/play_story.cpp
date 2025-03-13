#include <ncurses.h>
#include <bits/stdc++.h>
#include "map_head.h"
using namespace std;

struct story {
    string text;
    vector<string> options;
    vector<story*> next;
    string reward;
};

vector<story*> hospital_story;

void initialize_stories() {
    hospital_story.push_back(new story);
    hospital_story[0]->text = "You are in a hospital. You see a nurse.";
    hospital_story[0]->options.push_back("Talk to the nurse");
    hospital_story[0]->options.push_back("Ignore the nurse");
    hospital_story[0]->next = vector<story*>(2, nullptr);
    hospital_story[0]->reward = "a bandage";
}

void play_story(story* current_story, int height, int width) {
    clear();
    refresh();

    int ch;
    int play_pos = 0;
    int original_point[2] = {height / 3, int((width - current_story->text.size()) / 2)};
    while ((ch = getch()) != 'q') { // Press 'q' to exit the loop
        if (play_pos < current_story->text.size()) {
            mvprintw(original_point[0], original_point[1] + play_pos, "%c", current_story->text[play_pos]);
            play_pos++;
            refresh();
        } else if (play_pos == current_story->text.size()) {
            for (int k = 0; k < current_story->options.size(); k++) {
                mvprintw(original_point[0] * 2 + k, original_point[1], "%s", current_story->options[k].c_str());
            }
            play_pos++;
            refresh();
        }
    }
    clear();
    mvprintw(height / 2, (width - current_story->reward.size()) / 2, "%s", current_story->reward.c_str());
    refresh();
    getch();
    clear();
    refresh();
}

