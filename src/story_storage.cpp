#include <vector>  // For vector
#include <string>  // For string
#include <ctime>
#include <cstdlib> // For rand() and srand()
#include "../include/map_head.h"
#include "../include/game_state.h"
#include <climits>

using namespace std;

int generate_random_num(int min, int max) {
    srand(time(0));
    int random_num = rand() % (max - min + 1) + min;
    return random_num;
}

vector<int> hospital_head_story = {0,3,7,15};

void initialize_hospital_story(){
    srand(time(0));
    hospital_story.push_back(new story);
    hospital_story[0]->text = "You see a zombie nurse walking like a zombie.";
    hospital_story[0]->options.push_back("Talk to the nurse");
    hospital_story[0]->options.push_back("Ignore the nurse");
    hospital_story[0]->reward = "inventory bandage";

    hospital_story.push_back(new story);
    hospital_story[1]->text = "The nurse tells you that you are in a hospital. She asks you if you are feeling better.";
    hospital_story[1]->options.push_back("Why zombies can talk?");
    
    hospital_story[1]->reward = "health -1";

    hospital_story.push_back(new story);
    hospital_story[2]->text = "You're bitten, so that's why";
    hospital_story[2]->options.push_back("End conversation");
    hospital_story[2]->next.push_back(nullptr);
    hospital_story[2]->reward = "health -1";

    
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
    hospital_story[5]->reward = "inventory pancake";

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
    hospital_story[9]->reward = "health +2";

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
    //hospital_story[12]->reward = "unknown effect";

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
    hospital_story[15]->next = vector<story*>{nullptr};

    // Story 16
    hospital_story.push_back(new story);
    hospital_story[16]->text = "The journal mentions a hidden exit from the hospital.";
    hospital_story[16]->options.push_back("Search for the exit");
    hospital_story[16]->options.push_back("Ignore the journal");
    hospital_story[16]->next = vector<story*>{nullptr, nullptr};
    hospital_story[16]->reward = "inventory clue";

    // Story 17
    hospital_story.push_back(new story);
    hospital_story[17]->text = "the patient is dead";
    hospital_story[17]->options.push_back("Feel sorry for him");
    hospital_story[17]->next.push_back(nullptr);
    hospital_story[17]->reward = "bullet -1";

    // Story 18 after 16
    // Story 18: Finding the hidden exit
    hospital_story.push_back(new story);
    hospital_story[18]->text = "You find a hidden exit in the hospital. The door is locked, but there's a keypad next to it.";
    hospital_story[18]->options.push_back("Try to guess the code");
    hospital_story[18]->options.push_back("Look around for clues");
    hospital_story[18]->next = vector<story*>{nullptr, nullptr};

    // Story 19: Guessing the code
    hospital_story.push_back(new story);
    hospital_story[19]->text = "The keypad locks after three failed attempts.";
    hospital_story[19]->options.push_back("Leave");
    hospital_story[19]->next.push_back(nullptr);
    hospital_story[19]->reward = "";

    // Story 20: Searching for clues
    hospital_story.push_back(new story);
    hospital_story[20]->text = "You find a note nearby with the numbers '651149114' scribbled on it.";
    hospital_story[20]->options.push_back("Try the code on the keypad");
    hospital_story[20]->next = vector<story*>{nullptr};

    // Story 21: Unlocking the exit
    hospital_story.push_back(new story);
    hospital_story[21]->text = "The keypad beeps, and the door unlocks. You step outside into a dark alley.";
    hospital_story[21]->options.push_back("Explore the alley");
    hospital_story[21]->options.push_back("Go back inside");
    hospital_story[21]->next = vector<story*>{nullptr, nullptr};
    hospital_story[21]->reward = " inventory freedom";

    // Story 22: Exploring the alley
    hospital_story.push_back(new story);
    hospital_story[22]->text = "You walk down the alley and find a backpack with supplies.";
    hospital_story[22]->options.push_back("Take the supplies and leave");
    hospital_story[22]->options.push_back("Leave the backpack and return to the hospital");
    hospital_story[22]->next = vector<story*>{nullptr, nullptr};
    hospital_story[22]->reward = "inventory supplies";

    // Story 23: Returning to the hospital
    hospital_story.push_back(new story);
    hospital_story[23]->text = "You decide to return to the hospital, leaving the hidden exit behind.";
    hospital_story[23]->options.push_back("End conversation");
    hospital_story[23]->next.push_back(nullptr);
    hospital_story[23]->reward = "";

    hospital_story.push_back(new story);
    hospital_story[24]->text = "You try to guess the code, successfully open the door";
    hospital_story[24]->options.push_back("open the door");
    hospital_story[24]->next.push_back(hospital_story[21]);
    hospital_story[24]->reward = "";

    // Linking the new stories
    hospital_story[16]->next[0] = hospital_story[18]; // Search for the exit
    hospital_story[16]->next[1] = hospital_story[6]; // Ignore the journal
    if(rand()>INT_MAX/2 - gs.difficulty*1000){//successfully open the door
        //mvprintw(3,0,"%d cf %d",rand(),INT_MAX/2 - gs.difficulty*1000);
        hospital_story[18]->next[0] = hospital_story[24];
    }else{
        hospital_story[18]->next[0] = hospital_story[19]; // Guess the code wrong
    }
    hospital_story[18]->next[1] = hospital_story[20]; // Look for clues
    srand(time(0));
    if(rand()>INT_MAX/2 - gs.difficulty*1000){//successfully open the door
        //mvprintw(3,0,"%d cf %d",rand(),INT_MAX/2 - gs.difficulty*1000);
        hospital_story[20]->next[0] = hospital_story[21];
    }else{
        hospital_story[20]->next[0] = hospital_story[19]; // fail to open
    }

    hospital_story[21]->next[0] = hospital_story[22]; // Explore the alley
    hospital_story[21]->next[1] = hospital_story[23]; // Go back inside

    hospital_story[22]->next[0] = hospital_story[6];  // Take supplies and leave (link to an existing story)
    hospital_story[22]->next[1] = hospital_story[23]; // Leave the backpack and return


    hospital_story[7]->next[0] = hospital_story[8]; 

    hospital_story[8]->next[0] = hospital_story[9]; 
    hospital_story[8]->next[1] = hospital_story[10]; 

    hospital_story[10]->next[0] = hospital_story[8]; 
    hospital_story[10]->next[1] = hospital_story[13];

    hospital_story[11]->next[0] = hospital_story[12];
    hospital_story[11]->next[1] = hospital_story[6];

    hospital_story[13]->next[0] = hospital_story[14];
    hospital_story[13]->next[1] = hospital_story[6]; 

    hospital_story[15]->next[0] = hospital_story[16];
}

vector<story*> knocking_door;

void initialize_knocking_door(){ 
    
    for (int i = 0; i <= 16; i++) {
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
    knocking_door[3]->options.push_back("End Game");
    knocking_door[3]->next.push_back(nullptr);
    knocking_door[3]->reward = "death"; //game ends here
    knocking_door[4]->text = "You rushed back home and slamed the door behind you";
    knocking_door[4]->options.push_back("End conversation");
    knocking_door[4]->next.push_back(nullptr);
    knocking_door[5]->text = "The knocking started again and continued for a while, but ended eventually";
    knocking_door[5]->options.push_back("End conversation");
    knocking_door[5]->next.push_back(nullptr);
    knocking_door[5]->reward = "";

    //2. A weird guy story
    knocking_door[6]->text = "You see a weird guy standing outside";
    knocking_door[6]->options.push_back("Go out and talk to him");
    knocking_door[6]->options.push_back("Lock the door and go back to the bedroom");
    knocking_door[7]->text = "The guy asks you if you have any food";
    knocking_door[7]->options.push_back("Give him some food"); 
    knocking_door[7]->options.push_back("Refuse");
    knocking_door[7]->options.push_back("Suprise attack him");
    knocking_door[8]->text = "He takes the food and give you a bullet for return";
    knocking_door[8]->options.push_back("End conversation");
    knocking_door[8]->next.push_back(nullptr);
    knocking_door[8]->reward = "minus food, gained a bullet";
    knocking_door[9]->text = "You pushed him away and locked the door again";
    knocking_door[9]->options.push_back("End conversation");
    knocking_door[9]->next.push_back(nullptr);
    knocking_door[8]->reward = "no reward";
    knocking_door[10]->text = "You poke him in the eye, but got stabbed by him; you killed him with his own knife";
    knocking_door[10]->options.push_back("Search his body");
    knocking_door[11]->text = "You found a silver key inside his pocket";
    knocking_door[11]->options.push_back("End conversation");
    knocking_door[11]->next.push_back(nullptr);
    knocking_door[11]->reward = "inventory silver key";

    //3. A giant cockroach story
    knocking_door[12]->text = "You see a giant cockroach standing outside";
    knocking_door[12]->options.push_back("Go out to check the cockroach");
    knocking_door[12]->options.push_back("Lock the door and go back to the bedroom");
    knocking_door[13]->text = "The cockroach saw you, and quickly runs away";
    knocking_door[13]->options.push_back("Chase it"); //14
    knocking_door[13]->options.push_back("Shoot it with a bullet"); //15
    knocking_door[13]->options.push_back("Go back home"); //16
    knocking_door[14]->text = "You chase the cockroach for a while, and suddenly fall in to a pit; you got eaten alive by a number of cockroaches";
    knocking_door[14]->options.push_back("End Game");
    knocking_door[14]->next.push_back(nullptr);
    knocking_door[14]->reward = "death"; //game ends here
    knocking_door[15]->text = "You shot a bullet at the cockroach, but you missed since it's too dark outside";
    knocking_door[15]->options.push_back("Chase the cockroach");
    knocking_door[15]->options.push_back("Go back home");
    knocking_door[15]->reward = "bullet -1"; 
    knocking_door[16]->text = "You got back home safely";
    knocking_door[16]->options.push_back("End conversation");
    knocking_door[16]->next.push_back(nullptr);

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
        knocking_door[12]->next = vector<story*>{knocking_door[13], knocking_door[5]};
        knocking_door[13]->next = vector<story*>{knocking_door[14], knocking_door[15], knocking_door[16]};
        knocking_door[15]->next = vector<story*>{knocking_door[14], knocking_door[16]};
    }
}

vector<story*> glass_breaking_noise;

void initialize_glass_breanking_noise(){ 
    
    for (int i = 0; i <= 8; i++) {
        glass_breaking_noise.push_back(new story);
    }

    glass_breaking_noise[0]->text = "You hear the sound of glass breaking, it's likely from the kitchen";
    glass_breaking_noise[0]->options.push_back("Go to kitchen to check");
    glass_breaking_noise[0]->options.push_back("Ignore the noise");

    //1. cockroach story
    glass_breaking_noise[1]->text = "You see a giant cockroach with a broken leg, and some shattered glasses on the ground";
    glass_breaking_noise[1]->options.push_back("Go to help the cockroach and fix its leg"); //2
    glass_breaking_noise[1]->options.push_back("Kill the cockroach"); //3
    glass_breaking_noise[1]->options.push_back("Leave the cockroach bleeding on the ground");//4
    glass_breaking_noise[2]->text = "The cockroach spits a bottle, there is a paper slip inside";
    glass_breaking_noise[2]->options.push_back("End conversation");
    glass_breaking_noise[2]->next.push_back(nullptr);
    glass_breaking_noise[2]->reward = "inventory paper slip"; //might link to main story
    glass_breaking_noise[3]->text = "Green blood exploded from the cockroach and corroded your skin";
    glass_breaking_noise[3]->options.push_back("End conversation");
    glass_breaking_noise[3]->next.push_back(nullptr);
    glass_breaking_noise[3]->reward = "health -1"; 
    glass_breaking_noise[4]->text = "You went back to the bedroom";
    glass_breaking_noise[4]->options.push_back("End conversation");
    glass_breaking_noise[4]->next.push_back(nullptr);

    //2. intruder story
    glass_breaking_noise[5]->text = "You see a guy in the kitchen, acting like a thief";
    glass_breaking_noise[5]->options.push_back("Go talk to him"); //6
    glass_breaking_noise[5]->options.push_back("Quitely aim at him and shoot him"); //9
    glass_breaking_noise[5]->options.push_back("Quitely go back to the bedroom and lock the door");//4
    glass_breaking_noise[6]->text = "He got suprised by you, he said he thought this is a ruined place and he is only looking for food";
    glass_breaking_noise[6]->options.push_back("Give hime some food"); 
    glass_breaking_noise[6]->options.push_back("Quickly shoot at him"); 
    glass_breaking_noise[7]->text = "He thanked you and give you two bullets for return";
    glass_breaking_noise[7]->options.push_back("End conversation"); 
    glass_breaking_noise[7]->next.push_back(nullptr);
    glass_breaking_noise[7]->reward = "bullet + 1, food - 1";
    glass_breaking_noise[8]->text = "The gun shot killed him instently, you searched him and found a water bottle";
    glass_breaking_noise[8]->options.push_back("End conversation"); 
    glass_breaking_noise[8]->next.push_back(nullptr);
    glass_breaking_noise[8]->reward = "water +1";


    //3. ...story
    glass_breaking_noise[8]->text = "...";
    glass_breaking_noise[8]->options.push_back("..."); 
    glass_breaking_noise[8]->next.push_back(nullptr);

    int random_branch = generate_random_num(0, 2);

    if (random_branch == 0){
        //cockroach branch
        glass_breaking_noise[0]->next = vector<story*>{glass_breaking_noise[1], glass_breaking_noise[4]};
        glass_breaking_noise[1]->next = vector<story*>{glass_breaking_noise[2], glass_breaking_noise[3], glass_breaking_noise[4]}; 
    }
    else if (random_branch == 1){
        //intruder branch
        glass_breaking_noise[0]->next = vector<story*>{glass_breaking_noise[5], glass_breaking_noise[4]};
        glass_breaking_noise[5]->next = vector<story*>{glass_breaking_noise[6], glass_breaking_noise[7], glass_breaking_noise[4]};
        glass_breaking_noise[6]->next = vector<story*>{glass_breaking_noise[7], glass_breaking_noise[8]};

    }
    else{
        //...
        glass_breaking_noise[0]->next = vector<story*>{glass_breaking_noise[8], glass_breaking_noise[4]};
    }


    
}


void initialize_stories() {
    initialize_hospital_story();
    initialize_knocking_door();
    initialize_glass_breanking_noise();
}