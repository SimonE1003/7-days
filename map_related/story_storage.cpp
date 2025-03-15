#include <vector>  // For vector
#include <string>  // For string
#include "map_head.h"
using namespace std;

vector<int> head_story = {0,3};
void initialize_stories() {
    hospital_story.push_back(new story);
    hospital_story[0]->text = "You are in a hospital. You see a nurse.";
    hospital_story[0]->options.push_back("Talk to the nurse");
    hospital_story[0]->options.push_back("Ignore the nurse");
    
    //hospital_story[0]->reward = "bandage";

    hospital_story.push_back(new story);
    hospital_story[1]->text = "The nurse tells you that you are in a hospital.\n She asks you if you are feeling better.";
    hospital_story[1]->options.push_back("End conversation");
    hospital_story[1]->next.push_back(nullptr);
    hospital_story[1]->reward = "health";

    hospital_story.push_back(new story);
    hospital_story[2]->text = "nothing happened then";
    hospital_story[2]->options.push_back("End conversation");
    hospital_story[2]->next.push_back(nullptr);
    hospital_story[2]->reward = "no reward";

    hospital_story[0]->next = vector<story*>{hospital_story[1], hospital_story[2]};


    hospital_story.push_back(new story);
    hospital_story[3]->text = "You are in a hospital. You see a doctor.";
    hospital_story[3]->options.push_back("ask for help");
    hospital_story[3]->options.push_back("grab his pancake");
    
    

    hospital_story.push_back(new story);
    hospital_story[4]->text = "The doctor gives you a bandage.";
    hospital_story[4]->options.push_back("End conversation");
    hospital_story[4]->next.push_back(nullptr);
    hospital_story[4]->reward = "bandage";

    hospital_story.push_back(new story);
    hospital_story[5]->text = "you got a pancake";
    hospital_story[5]->options.push_back("End");
    hospital_story[5]->next.push_back(nullptr);
    hospital_story[5]->reward = "pancake";

    hospital_story[3]->next = vector<story*>{hospital_story[4], hospital_story[5]};

}