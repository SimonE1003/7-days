#include <vector>  // For vector
#include <string>  // For string
#include "map_head.h"
using namespace std;

vector<int> head_story = {0,3};

void initialize_hospital_story(){
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

vector<story*> knocking_door;

void initialize_knocking_door(){ 
    
    knocking_door.push_back(new story);
    knocking_door[0]->text = "You hear someone knocking the door";
    knocking_door[0]->options.push_back("Go to check the peekhole");
    knocking_door[0]->options.push_back("Quietly move to the door and wait beside it");
    knocking_door[0]->options.push_back("Ignore the noise");
    
    //knocking_door[0]->reward = "bandage";

    knocking_door.push_back(new story);
    knocking_door[1]->text = "You see nothing outside";
    knocking_door[1]->options.push_back("End conversation");
    knocking_door[1]->next.push_back(nullptr);
    knocking_door[1]->reward = "no reward";

    knocking_door.push_back(new story);
    knocking_door[2]->text = "The knocking continued for a while, but ended eventually";
    knocking_door[2]->options.push_back("End conversation");
    knocking_door[2]->next.push_back(nullptr);
    knocking_door[2]->reward = "no reward";

    
    knocking_door[0]->next = vector<story*>{knocking_door[1], knocking_door[2], knocking_door[2]};
}

vector<story*> glass_breaking_noise_cockroach;

void initialize_glass_breanking_noise_cockroach(){ //add random events for branches later
    
    glass_breaking_noise_cockroach.push_back(new story);
    glass_breaking_noise_cockroach[0]->text = "You hear the sound of glass breaking, it's likely from the kitchen";
    glass_breaking_noise_cockroach[0]->options.push_back("Go to kitchen to check");
    glass_breaking_noise_cockroach[0]->options.push_back("Ignore the noise");
    

    glass_breaking_noise_cockroach.push_back(new story);
    glass_breaking_noise_cockroach[1]->text = "You see a giant cockroach with a broken leg, and some shattered glasses on the ground";
    glass_breaking_noise_cockroach[1]->options.push_back("Go to help the cockroach and fix its leg"); //3
    glass_breaking_noise_cockroach[1]->options.push_back("Kill the cockroach"); //4
    glass_breaking_noise_cockroach[1]->options.push_back("Leave the cockroach bleeding on the ground");//5

    glass_breaking_noise_cockroach.push_back(new story);
    glass_breaking_noise_cockroach[2]->text = "There are still some weird noise comming from the kitchen";
    glass_breaking_noise_cockroach[2]->options.push_back("Go to kitchen to check");
    glass_breaking_noise_cockroach[2]->options.push_back("Ignor the noise and lock the bedroom door");

    glass_breaking_noise_cockroach.push_back(new story);
    glass_breaking_noise_cockroach[3]->text = "The cockroach spits a bottle, there is a paper slip inside";
    glass_breaking_noise_cockroach[3]->options.push_back("End conversation");
    glass_breaking_noise_cockroach[3]->next.push_back(nullptr);
    glass_breaking_noise_cockroach[3]->reward = "paper slip"; //might link to main story

    glass_breaking_noise_cockroach.push_back(new story);
    glass_breaking_noise_cockroach[4]->text = "Green blood exploded from the cockroach and corroded your skin";
    glass_breaking_noise_cockroach[4]->options.push_back("End conversation");
    glass_breaking_noise_cockroach[4]->next.push_back(nullptr);
    glass_breaking_noise_cockroach[4]->reward = "minus health"; 

    glass_breaking_noise_cockroach.push_back(new story);
    glass_breaking_noise_cockroach[5]->text = "You went back to the bedroom";
    glass_breaking_noise_cockroach[5]->options.push_back("End conversation");
    glass_breaking_noise_cockroach[5]->next.push_back(nullptr);
    glass_breaking_noise_cockroach[5]->reward = "no reward";
    
    glass_breaking_noise_cockroach[0]->next = vector<story*>{glass_breaking_noise_cockroach[1], glass_breaking_noise_cockroach[2]};
    glass_breaking_noise_cockroach[2]->next = vector<story*>{glass_breaking_noise_cockroach[1]};
    glass_breaking_noise_cockroach[1]->next = vector<story*>{glass_breaking_noise_cockroach[3], glass_breaking_noise_cockroach[4]}, glass_breaking_noise_cockroach[5];    
}


void initialize_stories() {
    initialize_hospital_story();
    initialize_knocking_door();
    initialize_glass_breanking_noise_cockroach();
}