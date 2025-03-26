#include <vector>  // For vector
#include <string>  // For string
#include <ctime>
#include <cstdlib> // For rand() and srand()
#include "map_head.h"
using namespace std;

int generate_random_num(int min, int max) {
    srand(time(0));
    int random_num = rand() % (max - min + 1) + min;
    return random_num;
}

vector<int> hospital_head_story = {0,3,7,15};

void initialize_hospital_story(){
    hospital_story.push_back(new story);
    hospital_story[0]->text = "You see a zombie nurse walking like a zombie.";
    hospital_story[0]->options.push_back("Talk to the nurse");
    hospital_story[0]->options.push_back("Ignore the nurse");
    
    //hospital_story[0]->reward = "bandage";

    hospital_story.push_back(new story);
    hospital_story[1]->text = "The nurse tells you that you are in a hospital. She asks you if you are feeling better.";
    hospital_story[1]->options.push_back("Why zombit can talk?");
    
    hospital_story[1]->reward = "health";

    hospital_story.push_back(new story);
    hospital_story[2]->text = "You're bitten, so that's why";
    hospital_story[2]->options.push_back("End conversation");
    hospital_story[2]->next.push_back(nullptr);
    hospital_story[2]->reward = "HP - 1";

    
    hospital_story[1]->next.push_back(hospital_story[2]);

    hospital_story.push_back(new story);
    hospital_story[3]->text = "You see a doctor's gown.";
    hospital_story[3]->options.push_back("ask for help");
    hospital_story[3]->options.push_back("grab the pancake in his pocket");
    
    

    hospital_story.push_back(new story);
    hospital_story[4]->text = "Why are you talking to a gown?";
    hospital_story[4]->options.push_back("End conversation");
    hospital_story[4]->next.push_back(nullptr);
    hospital_story[4]->reward = "";

    hospital_story.push_back(new story);
    hospital_story[5]->text = "you got a pancake";
    hospital_story[5]->options.push_back("End");
    hospital_story[5]->next.push_back(nullptr);
    hospital_story[5]->reward = "pancake";

    hospital_story[3]->next = vector<story*>{hospital_story[4], hospital_story[5]};

    hospital_story.push_back(new story);
    hospital_story[6]->text = "nothing happened then";
    hospital_story[6]->options.push_back("End conversation");
    hospital_story[6]->next.push_back(nullptr);
    hospital_story[6]->reward = "";

    hospital_story[0]->next = vector<story*>{hospital_story[1], hospital_story[6]};

    // Story 7
    hospital_story.push_back(new story);
    hospital_story[7]->text = "You find a locked cabinet with a strange symbol on it.";
    hospital_story[7]->options.push_back("Try to open the cabinet");
    hospital_story[7]->next = vector<story*>{nullptr};

    // Story 8
    hospital_story.push_back(new story);
    hospital_story[8]->text = "The cabinet opens, revealing a glowing syringe.";
    hospital_story[8]->options.push_back("Take the syringe");
    hospital_story[8]->options.push_back("Look at it closer");
    hospital_story[8]->next = vector<story*>{nullptr, nullptr};
    hospital_story[8]->reward = "";

    // Story 9
    hospital_story.push_back(new story);
    hospital_story[9]->text = "You feel a surge of energy after using the syringe.";
    hospital_story[9]->options.push_back("End conversation");
    hospital_story[9]->next.push_back(nullptr);
    hospital_story[9]->reward = "health boost";

    // Story 10
    hospital_story.push_back(new story);
    hospital_story[10]->text = "You hear a faint whisper: 'Don't trust the syringe...'";
    hospital_story[10]->options.push_back("Ignore the whisper");
    hospital_story[10]->options.push_back("Investigate the source of the whisper");
    hospital_story[10]->next = vector<story*>{nullptr, nullptr};

    // Story 11
    hospital_story.push_back(new story);
    hospital_story[11]->text = "You find a hidden, locked, room with strange medical equipment.";
    hospital_story[11]->options.push_back("Try number 651149114 by the strange man");
    hospital_story[11]->options.push_back("Too dangerous, leave the room");
    hospital_story[11]->next = vector<story*>{nullptr,nullptr};

    // Story 12
    hospital_story.push_back(new story);
    hospital_story[12]->text = "The equipment activates, and you feel a strange sensation. The effect is unknown.";
    hospital_story[12]->options.push_back("End conversation");
    hospital_story[12]->next.push_back(nullptr);
    hospital_story[12]->reward = "unknown effect";

    // Story 13
    hospital_story.push_back(new story);
    hospital_story[13]->text = "You encounter a patient who seems to know you.";
    hospital_story[13]->options.push_back("Talk to the patient");
    hospital_story[13]->options.push_back("Attack him");
    hospital_story[13]->next = vector<story*>{nullptr, nullptr}; 

    // Story 14
    hospital_story.push_back(new story);
    hospital_story[14]->text = "The patient reveals a series of number 651149114, no idea what it means.";
    hospital_story[14]->options.push_back("Leave him alone");
    hospital_story[14]->next.push_back(nullptr);
    hospital_story[14]->reward = "start story 11";
    

    // Story 15
    hospital_story.push_back(new story);
    hospital_story[15]->text = "You find a journal with cryptic notes.";
    hospital_story[15]->options.push_back("Read the journal");
    hospital_story[15]->options.push_back("Leave it alone");
    hospital_story[15]->next = vector<story*>{nullptr, nullptr};

    // Story 16
    hospital_story.push_back(new story);
    hospital_story[16]->text = "The journal mentions a hidden exit from the hospital.";
    hospital_story[16]->options.push_back("Search for the exit");
    hospital_story[16]->options.push_back("Ignore the journal");
    hospital_story[16]->next = vector<story*>{nullptr, nullptr};
    hospital_story[16]->reward = "clue to escape";

    // Story 17
    hospital_story.push_back(new story);
    hospital_story[17]->text = "the patient is dead";
    hospital_story[17]->options.push_back("Feel sorry for him");
    hospital_story[17]->next.push_back(nullptr);
    hospital_story[17]->reward = "bullet - 1";


    hospital_story[7]->next[0] = hospital_story[8]; 

    hospital_story[8]->next[0] = hospital_story[9]; 
    hospital_story[8]->next[1] = hospital_story[10]; 

    hospital_story[10]->next[0] = hospital_story[8]; 
    hospital_story[10]->next[1] = hospital_story[13];

    hospital_story[11]->next[0] = hospital_story[12];
    hospital_story[11]->next[1] = hospital_story[6];

    hospital_story[13]->next[0] = hospital_story[14];
    hospital_story[13]->next[1] = hospital_story[6]; 
}

vector<story*> knocking_door;

void initialize_knocking_door(){ 
    
    for (int i = 0; i <= 13; i++) {
        knocking_door.push_back(new story);
    }

    knocking_door[0]->text = "You hear someone knocking the door";
    knocking_door[0]->options.push_back("Go to check the peekhole"); // Random: 1. Nothing Outside 2.A weird guy 3.A giant cockroach 

    //1. Nothing Outside story
    knocking_door[1]->text = "You see nothing outside, you wonder who knocked the door";
    knocking_door[1]->options.push_back("Go out and check");
    knocking_door[1]->options.push_back("Lock the door and go back to the bedroom");
    knocking_door[2]->text = "After walking a few steps in the dark, you hear a scream and suddenly got scrached by a woman covered in blood.";
    knocking_door[2]->options.push_back("Fight the woman");
    knocking_door[2]->options.push_back("Run back home");
    knocking_door[3]->text = "The woman killed you before you can draw your weapon, you should've never come outside at night";
    knocking_door[3]->options.push_back("End game");
    knocking_door[3]->next.push_back(nullptr);
    knocking_door[3]->reward = "death"; //game ends here
    knocking_door[4]->text = "You rushed back home and slamed the door behind you";
    knocking_door[4]->options.push_back("End conversation");
    knocking_door[4]->next.push_back(nullptr);
    knocking_door[5]->text = "The knocking started again and continued for a while, but ended eventually";
    knocking_door[5]->options.push_back("End conversation");
    knocking_door[5]->next.push_back(nullptr);
    knocking_door[5]->reward = "no reward";

    //2. A weird guy story
    knocking_door[6]->text = "You see a weird guy standing outside";
    knocking_door[6]->options.push_back("Go out and talk to him");
    knocking_door[6]->options.push_back("Lock the door and go back to the bedroom");
    knocking_door[7]->text = "The guy asks you if you have any food";
    knocking_door[7]->options.push_back("Give him some food"); 
    knocking_door[7]->options.push_back("Refuse");
    knocking_door[7]->options.push_back("Suprise attack him");
    knocking_door[8]->text = "He takes the food and give you a small knife for return";
    knocking_door[8]->options.push_back("End conversation");
    knocking_door[8]->next.push_back(nullptr);
    knocking_door[8]->reward = "minus food, gained small knife";
    knocking_door[9]->text = "You pushed him away and locked the door again";
    knocking_door[9]->options.push_back("End conversation");
    knocking_door[9]->next.push_back(nullptr);
    knocking_door[8]->reward = "no reward";
    knocking_door[10]->text = "You poke him in the eye, but got stabbed by him; you killed him with his own knife";
    knocking_door[10]->options.push_back("Search his body");
    knocking_door[11]->text = "You found a silver key inside his pocket";
    knocking_door[11]->next.push_back(nullptr);
    knocking_door[11]->reward = "silver key";

    //3. A giant cockroach story
    knocking_door[12]->text = "To be continued...";
    knocking_door[12]->options.push_back("...");
    knocking_door[12]->next.push_back(nullptr);
    knocking_door[13]->text = "To be continued...";
    knocking_door[13]->options.push_back("...");
    knocking_door[13]->next.push_back(nullptr);

    int random_branch = generate_random_num(0, 2); 

    if (random_branch == 0) {
        //1. Nothing Outside branch
        knocking_door[0]->next = vector<story*>{knocking_door[1]};
        knocking_door[1]->next = vector<story*>{knocking_door[2], knocking_door[5]};
        knocking_door[2]->next = vector<story*>{knocking_door[3], knocking_door[4]};
    } else if (random_branch == 1) {
        //2. A weird guy branch
        knocking_door[0]->next = vector<story*>{knocking_door[6]};
        knocking_door[6]->next = vector<story*>{knocking_door[7], knocking_door[5]};
        knocking_door[7]->next = vector<story*>{knocking_door[8], knocking_door[9], knocking_door[10]};
        knocking_door[10]->next = vector<story*>{knocking_door[11]};
    } else {
        //3. Giant cockroach story
        knocking_door[0]->next = vector<story*>{knocking_door[12]};
        knocking_door[12]->next = vector<story*>{knocking_door[13]};
    }
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
    glass_breaking_noise_cockroach[5]->reward = "";
    
    glass_breaking_noise_cockroach[0]->next = vector<story*>{glass_breaking_noise_cockroach[1], glass_breaking_noise_cockroach[2]};
    glass_breaking_noise_cockroach[2]->next = vector<story*>{glass_breaking_noise_cockroach[1]};
    glass_breaking_noise_cockroach[1]->next = vector<story*>{glass_breaking_noise_cockroach[3], glass_breaking_noise_cockroach[4]}, glass_breaking_noise_cockroach[5];    
}


void initialize_stories() {
    initialize_hospital_story();
    initialize_knocking_door();
    initialize_glass_breanking_noise_cockroach();
}