#include <vector> // For vector
#include <string> // For string
#include <ctime>
#include <cstdlib> // For rand() and srand()
#include "../include/map_head.h"
#include "../include/game_state.h"
#include <climits>

using namespace std;

int generate_random_num(int min, int max)
{
    srand(time(0));
    int random_num = rand() % (max - min + 1) + min;
    return random_num;
}


vector<int> hospital_head_story = {0,3,7,15,28,30,32,34,36};
vector<int> weaponshop_head_story = {0,3,7,10,12};

//28,30,32,34,36
void initialize_weaponshop_story(){
        srand(time(0));
	for (int i=0; i<100; i++)
	{
		weaponshop_story.push_back(new story);
	}
        //story0 Main1
        
        weaponshop_story[0]->text="You see an AK-47 on the ground.";
        weaponshop_story[0]->options.push_back("Try to get that AK-47");//story1
        weaponshop_story[0]->options.push_back("Ignore the gun");//story2

        //story1 Main1 branch1
        weaponshop_story[1]->text="A zombie noticed you, it is time to try your new weapon.";
        weaponshop_story[1]->options.push_back("Kill it with your AK-47!!!");
	weaponshop_story[1]->next.push_back(nullptr);
        weaponshop_story[1]->reward={"inventory AK-47",/*gs.weaponlevel+*/"bullet - 2"};//here will be bullet -2/weaponlevel
	//story2 Main1 branch2
	
	weaponshop_story[2]->text="You keep searching in the weaponshop, and noticed some bullets on the counter.";
	weaponshop_story[2]->options.push_back("Get the bullets.");
	weaponshop_story[2]->next.push_back(weaponshop_story[3]);

	weaponshop_story[0]->next = vector<story*>{weaponshop_story[1], weaponshop_story[2]};
	
	//story3 after story2
	weaponshop_story[3]->text="You got some bullets.";
	weaponshop_story[3]->options.push_back("End.");
	weaponshop_story[3]->reward={"bullet +5"};
	weaponshop_story[3]->next.push_back(nullptr);

	//story4 Main story2
	weaponshop_story[4]->text="You meet a strong zombie with a crowbar in his hand.";
	weaponshop_story[4]->options.push_back("Try to kill it.");//story5
	weaponshop_story[4]->options.push_back("Bypass him and continue exploring.");//story6
	weaponshop_story[4]->options.push_back("Run away.");//story7
	
	
	//story5 Main2 branch1
	
	weaponshop_story[5]->text="You obtained a crowbar,maybe it can help you open some doors?";
	weaponshop_story[5]->options.push_back("Continue exploration.");
	weaponshop_story[5]->next.push_back(nullptr);
	weaponshop_story[5]->reward={"inventory crowbar","bullet -2"};//here will be bullet -2/weaponlevel
	//story6 Main2 branch2
	
        weaponshop_story[6]->text="You notice someone's doomsday notebook.";
        weaponshop_story[6]->options.push_back("Read it.");
        weaponshop_story[6]->reward={"sanity +1"};
	//story7 story4 branch3
        
        weaponshop_story[7]->text="You escaped.";
        weaponshop_story[7]->options.push_back("End.");
        weaponshop_story[7]->next.push_back(nullptr);
	//story8 after story6
	weaponshop_story[8]->text="It has some encouraging words on it.";
	weaponshop_story[8]->options.push_back("At least I see a glimmer of hope.");
	weaponshop_story[8]->next.push_back(nullptr);
	weaponshop_story[8]->reward={"sanity +1"};

	weaponshop_story[4]->next = vector<story*>{weaponshop_story[5], weaponshop_story[6],weaponshop_story[7]};
	weaponshop_story[6]->next.push_back(weaponshop_story[8]);
	//story9 Main3
	weaponshop_story[9]->text="You enter the warehouse of the weaponshop,it's completely dark.";
	weaponshop_story[9]->options.push_back("Try to open the lights.");//story10
	weaponshop_story[9]->options.push_back("Investigate in the darkness.");//story11
	weaponshop_story[9]->options.push_back("It seems horrible,leave here.");//story12
	//story10 Main3 Branch1 
	weaponshop_story[10]->text="The zombies in the warehouse noticed you,it becomes a little tricky.";
	if (gs.bullet>=4)//here will be gs.bullet*gs.weaponlevel
	{
		weaponshop_story[10]->options.push_back("Kill them all!!!");
		weaponshop_story[10]->reward={"bullet -4"};/*here will be bullet -4/weaponlevel*/
	}
        weaponshop_story[10]->options.push_back("Run!!!");
	//story11 Main3 Branch2
	weaponshop_story[11]->text="Oops!You accidentally triggered something!";
	if (!gs.health>=2)
	{
		//You lose
	}
	weaponshop_story[11]->options.push_back("It seems that it is a trap set by others.");
	weaponshop_story[11]->next.push_back(nullptr);
	weaponshop_story[11]->reward={"health -1"};
	//story12 Main3 Branch3
	weaponshop_story[12]->text="You leaved the warehouse.";
	weaponshop_story[12]->next.push_back(nullptr);
	//story13 after story10
	weaponshop_story[13]->text="That's really narrow!!";
	weaponshop_story[13]->options.push_back("End.");
	weaponshop_story[13]->next.push_back(nullptr);
	weaponshop_story[9]->next=vector<story*>{weaponshop_story[10],weaponshop_story[11],weaponshop_story[12]};
	weaponshop_story[10]->next.push_back(weaponshop_story[13]);
	


	
	//story14 Main story4
	weaponshop_story[14]->text="You walk pass a counter,and noticed the medicine on it.";
	weaponshop_story[14]->options.push_back("Get the medicine.");
	weaponshop_story[14]->next.push_back(nullptr);
	weaponshop_story[14]->reward={"inventory medicine"};

	//story15 Main story5
	weaponshop_story[15]->text="You find a thin iron wire.";
	weaponshop_story[15]->options.push_back("Pick it up.");
	weaponshop_story[15]->options.push_back("Ignore it.");
	//story16 Main5 Branch1
	weaponshop_story[16]->text="I can use it to open some locked doors.";
	weaponshop_story[16]->options.push_back("End.");
	weaponshop_story[16]->next.push_back(nullptr);
	weaponshop_story[16]->reward={"inventory thin_iron_wire"};
	//story17 Main5 Branch2
	weaponshop_story[17]->text="It seems useless.";
	weaponshop_story[17]->options.push_back("End.");
	weaponshop_story[17]->next.push_back(nullptr);
	
	weaponshop_story[15]->next=vector<story*>{weaponshop_story[16],weaponshop_story[17]};
	//story18 Main story6
	weaponshop_story[18]->text="You find a locked room.";
     	weaponshop_story[18]->options.push_back("Pry open the window with the crowbar and enter.");//if have a crowbar
    	weaponshop_story[18]->options.push_back("Force open the door lock");//health need to >3
    	weaponshop_story[18]->options.push_back("Leave here.");
	//story19 Main6 Branch1,2
    	weaponshop_story[19]->text="Here seems to be an abandoned shelter.\nYou noticed a bulletproof vest on the wall.";
    	weaponshop_story[19]->options.push_back("Put on the bulletproof vest.");
    	weaponshop_story[19]->next.push_back(nullptr);
  	weaponshop_story[19]->reward={"bulletproof_vest effect"};

    	weaponshop_story[18]->next=vector<story*>{weaponshop_story[19],weaponshop_story[19],nullptr};

    	//story20 Main story7
    	weaponshop_story[20]->text="You step into a dark room, a huge spider suddenly attacks you.";
    	/*if (gs.bullet*gs.weaponlevel>2)*/
    	weaponshop_story[20]->options.push_back("Try to kill it.");
    	weaponshop_story[20]->options.push_back("Run!!");
	//story21 Main7 Branch1
    	weaponshop_story[21]->text="You killed the spider and obtained its eyes.";
    	weaponshop_story[21]->options.push_back("What can spider eyes do?");
    	weaponshop_story[21]->reward={"health -1","bullet -1","inventory spider_eyes"};
    	weaponshop_story[21]->next={nullptr};
	//story22 Main7 Branch2
    	weaponshop_story[22]->text="You escaped, but got hurted.";
    	weaponshop_story[22]->options.push_back("End.");
    	weaponshop_story[22]->reward={"health -1"};//if health>1
    	weaponshop_story[22]->next={nullptr};
    	weaponshop_story[20]->next=vector<story*>{weaponshop_story[21],weaponshop_story[22]};

    	//story23 Main story8
    	weaponshop_story[23]->text="The hidden door behind the counter slowly opened.";
    	weaponshop_story[23]->options.push_back("Explore.");
	//story24 Possible1  Bad
	weaponshop_story[24]->text="A mutant hound runs towards you. ";
        if (gs.bullet>6)
        {
                weaponshop_story[24]->options.push_back("Kill it.");
		weaponshop_story[24]->next=vector<story*>{weaponshop_story[25],weaponshop_story[26]};
        }
        weaponshop_story[24]->options.push_back("Run away.");
	//story25 Possible1 branch1
	
	//story Possible2  Bad
	//story Possible3  Good
	//story Possible4  Good
	//story Possible5  Good
	//story Possible6  Good
    	
	
}
void initialize_hospital_story()
{
    srand(time(0));
    hospital_story.push_back(new story);
    hospital_story[0]->text = "You see a zombie nurse walking like a zombie.";
    hospital_story[0]->options.push_back("Talk to the nurse");
    hospital_story[0]->options.push_back("Ignore the nurse");
    hospital_story[0]->reward = {"inventory bandage"};

    hospital_story.push_back(new story);
    hospital_story[1]->text = "The nurse tells you that you are in a hospital. She asks you if you are feeling better.";
    hospital_story[1]->options.push_back("Why zombies can talk?");

    hospital_story[1]->reward = {"health -1"};

    hospital_story.push_back(new story);
    hospital_story[2]->text = "You're bitten, so that's why";
    hospital_story[2]->options.push_back("End conversation");
    hospital_story[2]->next.push_back(nullptr);
    hospital_story[2]->reward = {"health -1"};

    hospital_story[1]->next.push_back(hospital_story[2]);

    hospital_story.push_back(new story);
    hospital_story[3]->text = "You see a doctor's gown.";
    hospital_story[3]->options.push_back("ask for help");
    hospital_story[3]->options.push_back("grab the pancake in his pocket");

    hospital_story.push_back(new story);
    hospital_story[4]->text = "Why are you talking to a gown?";
    hospital_story[4]->options.push_back("End conversation");
    hospital_story[4]->next.push_back(nullptr);

    hospital_story.push_back(new story);
    hospital_story[5]->text = "you got a pancake";
    hospital_story[5]->options.push_back("End");
    hospital_story[5]->next.push_back(nullptr);
    hospital_story[5]->reward = {"inventory pancake"};

    hospital_story[3]->next = vector<story *>{hospital_story[4], hospital_story[5]};

    hospital_story.push_back(new story);
    hospital_story[6]->text = "nothing happened then";
    hospital_story[6]->options.push_back("End conversation");
    hospital_story[6]->next.push_back(nullptr);

    hospital_story[0]->next = vector<story *>{hospital_story[1], hospital_story[6]};

    // Story 7
    hospital_story.push_back(new story);
    hospital_story[7]->text = "You find a locked cabinet with a strange symbol on it.";
    hospital_story[7]->options.push_back("Try to open the cabinet");
    hospital_story[7]->next = vector<story *>{nullptr};

    // Story 8
    hospital_story.push_back(new story);
    hospital_story[8]->text = "The cabinet opens, revealing a glowing syringe.";
    hospital_story[8]->options.push_back("Take the syringe");
    hospital_story[8]->options.push_back("Look at it closer");
    hospital_story[8]->next = vector<story *>{nullptr, nullptr};

    // Story 9
    hospital_story.push_back(new story);
    hospital_story[9]->text = "You feel a surge of energy after using the syringe.";
    hospital_story[9]->options.push_back("End conversation");
    hospital_story[9]->next.push_back(nullptr);
    hospital_story[9]->reward = {"health +2"};

    // Story 10
    hospital_story.push_back(new story);
    hospital_story[10]->text = "You hear a faint whisper: 'Don't trust the syringe...'";
    hospital_story[10]->options.push_back("Ignore the whisper");
    hospital_story[10]->options.push_back("Investigate the source of the whisper");
    hospital_story[10]->next = vector<story *>{nullptr, nullptr};

    // Story 11
    hospital_story.push_back(new story);
    hospital_story[11]->text = "You find a hidden, locked, room with strange medical equipment.";
    hospital_story[11]->options.push_back("Try number 651149114 by the strange man");
    hospital_story[11]->options.push_back("Too dangerous, leave the room");
    hospital_story[11]->next = vector<story *>{nullptr, nullptr};

    // Story 12
    hospital_story.push_back(new story);
    hospital_story[12]->text = "The equipment activates, and you feel a strange sensation. The effect is unknown.";
    hospital_story[12]->options.push_back("End conversation");
    hospital_story[12]->next.push_back(nullptr);
    // hospital_story[12]->reward = "unknown effect";

    // Story 13
    hospital_story.push_back(new story);
    hospital_story[13]->text = "You encounter a patient who seems to know you.";
    hospital_story[13]->options.push_back("Talk to the patient");
    hospital_story[13]->options.push_back("Attack him");
    hospital_story[13]->next = vector<story *>{nullptr, nullptr};

    // Story 14
    hospital_story.push_back(new story);
    hospital_story[14]->text = "The patient reveals a series of number 651149114, no idea what it means.";
    hospital_story[14]->options.push_back("Leave him alone");
    hospital_story[14]->next.push_back(nullptr);
    //hospital_story[14]->reward = {"start story 11"}; i havent implemented the program to print out weird stuff so it will core dumped when the reward is something other than the described type

    // Story 15
    hospital_story.push_back(new story);
    hospital_story[15]->text = "You find a journal with cryptic notes.";
    hospital_story[15]->options.push_back("Read the journal");
    hospital_story[15]->next = vector<story *>{nullptr};

    // Story 16
    hospital_story.push_back(new story);
    hospital_story[16]->text = "The journal mentions a hidden exit from the hospital.";
    hospital_story[16]->options.push_back("Search for the exit");
    hospital_story[16]->options.push_back("Ignore the journal");
    hospital_story[16]->next = vector<story *>{nullptr, nullptr};
    hospital_story[16]->reward = {"inventory clue"};

    // Story 17
    hospital_story.push_back(new story);
    hospital_story[17]->text = "the patient is dead";
    hospital_story[17]->options.push_back("Feel sorry for him");
    hospital_story[17]->next.push_back(nullptr);
    hospital_story[17]->reward = {"bullet -1"};

    // Story 18 after 16
    // Story 18: Finding the hidden exit
    hospital_story.push_back(new story);
    hospital_story[18]->text = "You find a hidden exit in the hospital. The door is locked, but there's a keypad next to it.";
    hospital_story[18]->options.push_back("Try to guess the code");
    hospital_story[18]->options.push_back("Look around for clues");
    hospital_story[18]->next = vector<story *>{nullptr, nullptr};

    // Story 19: Guessing the code
    hospital_story.push_back(new story);
    hospital_story[19]->text = "The keypad locks after three failed attempts.";
    hospital_story[19]->options.push_back("Leave");
    hospital_story[19]->next.push_back(nullptr);

    // Story 20: Searching for clues
    hospital_story.push_back(new story);
    hospital_story[20]->text = "You find a note nearby with the numbers '651149114' scribbled on it.";
    hospital_story[20]->options.push_back("Try the code on the keypad");
    hospital_story[20]->next = vector<story *>{nullptr};

    // Story 21: Unlocking the exit
    hospital_story.push_back(new story);
    hospital_story[21]->text = "The keypad beeps, and the door unlocks. You step outside into a dark alley.";
    hospital_story[21]->options.push_back("Explore the alley");
    hospital_story[21]->options.push_back("Go back inside");
    hospital_story[21]->next = vector<story *>{nullptr, nullptr};
    hospital_story[21]->reward = {"inventory freedom"};

    // Story 22: Exploring the alley
    hospital_story.push_back(new story);
    hospital_story[22]->text = "You walk down the alley and find a backpack with supplies.";
    hospital_story[22]->options.push_back("Take the supplies and leave");
    hospital_story[22]->options.push_back("Leave the backpack and return to the hospital");
    hospital_story[22]->next = vector<story *>{nullptr, nullptr};
    hospital_story[22]->reward = {"inventory supplies"};

    // Story 23: Returning to the hospital
    hospital_story.push_back(new story);
    hospital_story[23]->text = "You decide to return to the hospital, leaving the hidden exit behind.";
    hospital_story[23]->options.push_back("End conversation");
    hospital_story[23]->next.push_back(nullptr);

    hospital_story.push_back(new story);
    hospital_story[24]->text = "You try to guess the code, successfully open the door";
    hospital_story[24]->options.push_back("open the door");
    hospital_story[24]->next.push_back(hospital_story[21]);

    // story 25: meeting a crazy man
    hospital_story.push_back(new story);
    hospital_story[25]->text = "You saw a strange man";
    hospital_story[25]->options.push_back("talk to him");
    hospital_story[25]->options.push_back("ignore him");

    hospital_story.push_back(new story);
    hospital_story[26]->text = "Turns out he's a crazy man, talking to him makes you question your existence";
    hospital_story[26]->options.push_back("End conversation");
    hospital_story[26]->next = vector<story *>{nullptr, nullptr};
    hospital_story[26]->reward = {"sanity -1"};

    hospital_story.push_back(new story);
    hospital_story[27]->text = "Turns out he's a crazy man and suddenly he attacked you because you ignored him";
    hospital_story[27]->options.push_back("End conversation");
    hospital_story[27]->next = vector<story *>{nullptr, nullptr};
    hospital_story[27]->reward = {"health -1"};

    hospital_story[25]->next = vector<story *>{hospital_story[26], hospital_story[27]};


    hospital_story.resize(50);

    // Story 28
    hospital_story[28] = new story;
    hospital_story[28]->text = "You discover a locked medical storage room.";
    hospital_story[28]->options.push_back("Try to pick the lock");
    hospital_story[28]->options.push_back("Leave it alone");

    // Branch for Story 28
    hospital_story[29] = new story;
    hospital_story[29]->text = "You successfully unlock the door and find medical supplies, but the lock picking makes you feel insane.";
    hospital_story[29]->options.push_back("Take the supplies");
    hospital_story[29]->next.push_back(nullptr);
    hospital_story[29]->reward = {"health +1", "sanity -1"};

    // Story 30
    hospital_story[30] = new story;
    hospital_story[30]->text = "A chilling voice whispers your name from the shadows.";
    hospital_story[30]->options.push_back("Investigate the source");
    hospital_story[30]->options.push_back("Run away");
    hospital_story[30]->next.push_back(hospital_story[31]);

    // Branch for Story 30
    hospital_story[31] = new story;
    hospital_story[31]->text = "You find a ghostly figure begging for help, he just wanted to talk.";
    hospital_story[31]->options.push_back("Talk to him");
    hospital_story[31]->options.push_back("Flee in terror");
    hospital_story[31]->next.push_back(hospital_story[38]);

    // Story 38 branch of 30
    hospital_story[38] = new story;
    hospital_story[38]->text = "You feel happy after talking to the ghost";
    hospital_story[38]->options.push_back("End conversation");
    hospital_story[38]->next.push_back(nullptr);
    hospital_story[38]->reward = {"sanity +2"};

    // Story 32
    hospital_story[32] = new story;
    hospital_story[32]->text = "You stumble upon an eerie surgical room.";
    hospital_story[32]->options.push_back("Search the room");
    hospital_story[32]->options.push_back("Leave quickly");
    hospital_story[32]->next.push_back(hospital_story[33]);

    // Branch for Story 32
    hospital_story[33] = new story;
    hospital_story[33]->text = "You found a notebook of an insane patient.";
    hospital_story[33]->options.push_back("Read it");
    hospital_story[33]->options.push_back("Leave it behind");
    hospital_story[33]->next.push_back(hospital_story[39]);

    // Branch for story 32
    hospital_story[39] = new story;
    hospital_story[39]->text = "His notes make you feel uncomfortable and questioning your existence";
    hospital_story[39]->options.push_back("Finished reading");
    hospital_story[39]->next.push_back(nullptr);
    hospital_story[39]->reward = {"sanity -1"};

    // Story 34
    hospital_story[34] = new story;
    hospital_story[34]->text = "You encounter a nurse who offers you a choice of treatments.";
    hospital_story[34]->options.push_back("Accept the treatment");
    hospital_story[34]->options.push_back("Decline the offer");

    // Branch for Story 34
    hospital_story[35] = new story;
    hospital_story[35]->text = "The treatment has unexpected side effects.";
    hospital_story[35]->options.push_back("Embrace the change");
    hospital_story[35]->options.push_back("Reject the treatment");

    // Story 40 branch of 30
    hospital_story[40] = new story;
    hospital_story[40]->text = "You feel good after the treatment but your head hurts";
    hospital_story[40]->options.push_back("Continue");
    hospital_story[40]->next.push_back(nullptr);
    hospital_story[40]->reward = {"sanity -1", "health +2"};

    // Story 36
    hospital_story[36] = new story;
    hospital_story[36]->text = "You find an old patient record with strange notes.";
    hospital_story[36]->options.push_back("Examine the notes");
    hospital_story[36]->options.push_back("Discard the record");

    // Branch for Story 36
    hospital_story[37] = new story;
    hospital_story[37]->text = "The notes mention a hidden room in the hospital.";
    hospital_story[37]->options.push_back("Search for the hidden room");
    hospital_story[37]->options.push_back("Ignore the notes");

    // Branch for Story 36
    hospital_story[41] = new story;
    hospital_story[41]->text = "After searching the room you found some bullets";
    hospital_story[41]->options.push_back("End the search");
    hospital_story[41]->next.push_back(nullptr);
    hospital_story[41]->reward = {"bullets +1"};


    
    hospital_story[28]->next = vector<story *> {hospital_story[29], nullptr};
    hospital_story[30]->next = vector<story *>{hospital_story[31], nullptr};
    hospital_story[31]->next = vector<story *>{hospital_story[38], nullptr};
    hospital_story[32]->next = vector<story *>{hospital_story[33], nullptr};
    hospital_story[33]->next = vector<story *>{hospital_story[39], nullptr};
    hospital_story[34]->next = vector<story *>{hospital_story[35], nullptr};
    hospital_story[35]->next = vector<story *>{hospital_story[40], nullptr};
    hospital_story[36]->next = vector<story *>{hospital_story[37], nullptr};
    hospital_story[37]->next = vector<story *>{hospital_story[41], nullptr}; 
    
    // Linking the new stories
    hospital_story[16]->next[0] = hospital_story[18]; // Search for the exit
    hospital_story[16]->next[1] = hospital_story[6];  // Ignore the journal
    if (rand() % 10 > 4 + gs.difficulty)
    { // successfully open the door
        // mvprintw(3,0,"%d cf %d",rand(),INT_MAX/2 - gs.difficulty*1000);
        hospital_story[18]->next[0] = hospital_story[24];
    }
    else
    {
        hospital_story[18]->next[0] = hospital_story[19]; // Guess the code wrong
    }
    hospital_story[18]->next[1] = hospital_story[20]; // Look for clues
    srand(time(0));
    if (rand() % 10 > 4 + gs.difficulty)
    { // successfully open the door
        // mvprintw(3,0,"%d cf %d",rand(),INT_MAX/2 - gs.difficulty*1000);
        hospital_story[20]->next[0] = hospital_story[21];
    }
    else
    {
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
    hospital_story[13]->next[1] = hospital_story[17];

    hospital_story[15]->next[0] = hospital_story[16];
}

vector<int> supermarket_head_story = {0, 8,13,25,32,42, 46,55,60,65,70,75,80};
void initialize_supermarket_story()
{
    supermarket_story.push_back(new story);
    supermarket_story[0]->text = "An ornate brass key with a note that read: \"Choose wisely, for this key unlocks more than just doors.\"";
    supermarket_story[0]->options.push_back("Take the key and note");

    supermarket_story.push_back(new story);
    supermarket_story[1]->text = "The key starts to  emit two beams of light.";
    supermarket_story[1]->options.push_back("Toward a door with a bumping sound behind it");
    supermarket_story[0]->next.push_back(supermarket_story[1]);

    supermarket_story.push_back(new story);
    supermarket_story[2]->text = "The door opens, a boy is trapped by a zombie, he's crying for help.";
    supermarket_story[2]->options.push_back("Help him");
    supermarket_story[2]->options.push_back("Leave him alone");
    supermarket_story[1]->next.push_back(supermarket_story[2]);

    supermarket_story.push_back(new story);
    supermarket_story[3]->text = "You got bitten on the hand, the boy ran away.";
    supermarket_story[3]->options.push_back("Use a gun");
    supermarket_story[3]->options.push_back("Fight with bare hands");
    supermarket_story[2]->next.push_back(supermarket_story[3]);
    supermarket_story[2]->next.push_back(nullptr);

    supermarket_story.push_back(new story);
    supermarket_story[4]->text = "You shot two bullets, the zombie is dead";
    supermarket_story[4]->options.push_back("Take a deep breath");
    supermarket_story[3]->next.push_back(supermarket_story[4]);

    supermarket_story.push_back(new story);
    supermarket_story[5]->text = "You killed the zombie, but yourself badly injured";
    supermarket_story[5]->options.push_back("Take a deep breath");
    supermarket_story[3]->next.push_back(supermarket_story[5]);

    supermarket_story.push_back(new story);
    supermarket_story[6]->text = "You're a hero, undoubtedly.";
    supermarket_story[6]->options.push_back("Take it as a compliment");
    supermarket_story[4]->next.push_back(supermarket_story[6]);
    supermarket_story[5]->next.push_back(supermarket_story[6]);
    supermarket_story[5]->next.push_back(nullptr);
    supermarket_story[6]->reward = vector<string>{"health -1", "bullet -2"}; // game ends here

    supermarket_story.push_back(new story);
    supermarket_story[7]->text = "You closed the door";
    supermarket_story[7]->options.push_back("Feel a little bit guilty");
    supermarket_story[7]->next.push_back(nullptr);

    supermarket_story.push_back(new story);
    supermarket_story[8]->text = "An ornate brass key with a note that read: \"Choose wisely, for this key unlocks more than just doors.\"";
    supermarket_story[8]->options.push_back("Take the key and note");

    supermarket_story.push_back(new story);
    supermarket_story[9]->text = "The key starts to  emit two beams of light.";
    supermarket_story[9]->options.push_back("Toward a doll with a lock on its head");
    supermarket_story[8]->next.push_back(supermarket_story[9]);

    supermarket_story.push_back(new story);
    supermarket_story[10]->text = "The doll is locked, but you can hear a voice inside it.";
    supermarket_story[10]->options.push_back("Open the doll");
    supermarket_story[10]->options.push_back("Leave it alone");
    supermarket_story[9]->next.push_back(supermarket_story[10]);

    supermarket_story.push_back(new story);
    supermarket_story[11]->text = "The doll starts to sing a lullaby, and you feel......crazy";
    supermarket_story[11]->options.push_back("Leave it alone with a headache");
    supermarket_story[10]->next.push_back(supermarket_story[11]);
    supermarket_story[11]->next.push_back(nullptr);
    supermarket_story[11]->reward = vector<string>{"sanity -1"}; // game ends here

    supermarket_story.push_back(new story);
    supermarket_story[12]->text = "You left the doll on the shelf";
    supermarket_story[12]->options.push_back("Walk away");
    supermarket_story[12]->next.push_back(nullptr);
    supermarket_story[10]->next.push_back(supermarket_story[12]);

    supermarket_story.resize(88); // Resize to 50 to accommodate all nodes

    supermarket_story[13] = new story;
    supermarket_story[13]->text = "In the supermarket, you spot two odd things: a can glowing like a tiny star and a shopping cart that moves on its own.";
    supermarket_story[13]->options.push_back("Check the can");
    supermarket_story[13]->options.push_back("Follow the cart");

    // --- Branch 1: The Glowing Can ---
    // Node 14
    supermarket_story[14] = new story;
    supermarket_story[14]->text = "You pick up the can. Its soft glow feels almost alive.";
    supermarket_story[14]->options.push_back("Examine the can");
    // Connect "Check the can" option (first option of node 13) to node 14.
    supermarket_story[13]->next.push_back(supermarket_story[14]);

    // Node 15
    supermarket_story[15] = new story;
    supermarket_story[15]->text = "At the far end of the aisle, you hear a quiet cry. A man is sitting by a sealed door.";
    supermarket_story[15]->options.push_back("Help him");
    supermarket_story[15]->options.push_back("Ignore him");
    // Connect node 14 to node 15.
    supermarket_story[14]->next.push_back(supermarket_story[15]);

    // Node 16: Outcome when you choose "Help him"
    supermarket_story[16] = new story;
    supermarket_story[16]->text = "You rush to help, but you get a small cut on your arm.";
    supermarket_story[16]->options.push_back("Use a bandage");
    supermarket_story[16]->options.push_back("Run away quickly");
    // Connect first option of node 15 ("Help him") to node 16.
    supermarket_story[15]->next.push_back(supermarket_story[16]);

    // Node 17: Outcome for "Use a bandage"
    supermarket_story[17] = new story;
    supermarket_story[17]->text = "You wrap the cut with a bandage and feel a warm rush of relief.";
    supermarket_story[17]->options.push_back("Continue");
    // Connect "Use a bandage" (first option of node 16) to node 17.
    supermarket_story[16]->next.push_back(supermarket_story[17]);
    supermarket_story[17]->reward = vector<string>{"health +1"};

    // Node 18: Outcome for "Run away quickly"
    supermarket_story[18] = new story;
    supermarket_story[18]->text = "You bolt away and the pain sharpens, leaving you weaker.";
    supermarket_story[18]->options.push_back("Continue");
    // Connect "Run away quickly" (second option of node 16) to node 18.
    supermarket_story[16]->next.push_back(supermarket_story[18]);
    supermarket_story[18]->reward = vector<string>{"health -1"};

    // Node 19: Outcome for "Ignore him"
    supermarket_story[19] = new story;
    supermarket_story[19]->text = "You walk past the crying man. A cold wave of regret hits you.";
    supermarket_story[19]->options.push_back("Continue");
    // Connect second option of node 15 ("Ignore him") to node 19.
    supermarket_story[15]->next.push_back(supermarket_story[19]);
    supermarket_story[19]->reward = vector<string>{"sanity -1"};

    // --- Branch 2: The Moving Cart ---
    // Node 20
    supermarket_story[20] = new story;
    supermarket_story[20]->text = "You follow the cart as it creaks down a quiet aisle, its wheels clicking a strange tune.";
    supermarket_story[20]->options.push_back("Open the door");
    // Connect "Follow the cart" option (second option of node 13) to node 20.
    supermarket_story[13]->next.push_back(supermarket_story[20]);

    // Node 21
    supermarket_story[21] = new story;
    supermarket_story[21]->text = "The door opens to a hidden aisle filled with odd, colorful items.";
    supermarket_story[21]->options.push_back("Enter the aisle");
    // Connect node 20 to node 21.
    supermarket_story[20]->next.push_back(supermarket_story[21]);

    // Node 22
    supermarket_story[22] = new story;
    supermarket_story[22]->text = "Inside, strange products are arranged like clues in a puzzle.";
    supermarket_story[22]->options.push_back("Pick an item");
    supermarket_story[22]->options.push_back("Walk away");
    // Connect node 21 to node 22.
    supermarket_story[21]->next.push_back(supermarket_story[22]);

    // Node 23: Outcome for "Pick an item"
    supermarket_story[23] = new story;
    supermarket_story[23]->text = "You grab a dazzling item, and suddenly, extra bullets clatter in your pocket.";
    supermarket_story[23]->options.push_back("Continue");
    // Connect first option of node 22 to node 23.
    supermarket_story[22]->next.push_back(supermarket_story[23]);
    supermarket_story[23]->reward = vector<string>{"bullet +1"};

    // Node 24: Outcome for "Walk away"
    supermarket_story[24] = new story;
    supermarket_story[24]->text = "You leave the aisle quickly, feeling a strange emptiness as your mind grows cloudy.";
    supermarket_story[24]->options.push_back("Continue");
    // Connect second option of node 22 to node 24.
    supermarket_story[22]->next.push_back(supermarket_story[24]);
    supermarket_story[24]->reward = vector<string>{"sanity -1"};




    // Node 25: Starting node
    supermarket_story[25] = new story;
    supermarket_story[25]->text = "In the supermarket, the power flickers, and you hear a faint voice near the frozen food aisle.";
    supermarket_story[25]->options.push_back("Investigate the voice");
    supermarket_story[25]->options.push_back("Ignore it and keep shopping");

    // --- Branch 1: Investigate the voice ---
    // Node 26
    supermarket_story[26] = new story;
    supermarket_story[26]->text = "You walk to the frozen food aisle and see a freezer with its door slightly ajar.";
    supermarket_story[26]->options.push_back("Open the freezer");
    supermarket_story[25]->next.push_back(supermarket_story[26]);

    // Node 27
    supermarket_story[27] = new story;
    supermarket_story[27]->text = "Inside the freezer, you find a frosty key and an old, torn map.";
    supermarket_story[27]->options.push_back("Take the key and map");
    supermarket_story[26]->next.push_back(supermarket_story[27]);

    // Node 28: You find a locked supply room.
    supermarket_story[28] = new story;
    supermarket_story[28]->text = "The map leads you to a locked supply room near the storage area.";
    supermarket_story[28]->options.push_back("Use the frosty key");
    supermarket_story[27]->next.push_back(supermarket_story[28]);

    // Node 29: Inside the supply room.
    supermarket_story[29] = new story;
    supermarket_story[29]->text = "The room holds emergency supplies, including some extra bullets.";
    supermarket_story[29]->options.push_back("Take the bullets");
    supermarket_story[28]->next.push_back(supermarket_story[29]);
    supermarket_story[29]->reward = vector<string>{"bullet +1"};

    // --- Branch 2: Ignore the voice ---
    // Node 30
    supermarket_story[30] = new story;
    supermarket_story[30]->text = "You decide to ignore the voice and continue shopping, but the strange sounds persist.";
    supermarket_story[30]->options.push_back("Leave the store quickly");
    supermarket_story[30]->reward = vector<string>{"sanity -1"};
    supermarket_story[25]->next.push_back(supermarket_story[30]);

    // Node 32: Starting node
    supermarket_story[32] = new story;
    supermarket_story[32]->text = "In the supermarket, a flickering LED sign above an empty aisle catches your eye.";
    supermarket_story[32]->options.push_back("Enter the mysterious aisle");

    // --- Branch 1: Enter the mysterious aisle ---
    // Node 33
    supermarket_story[33] = new story;
    supermarket_story[33]->text = "You step into the aisle and notice a rickety cart rolling by on its own.";
    supermarket_story[33]->options.push_back("Follow the cart");
    supermarket_story[33]->options.push_back("Examine the shelves");
    // Connect "Enter the mysterious aisle" option to node 33.
    supermarket_story[32]->next.push_back(supermarket_story[33]);

    // Branch 1.1: "Follow the cart"
    // Node 34
    supermarket_story[34] = new story;
    supermarket_story[34]->text = "You follow the cart to a locked backroom door.";
    supermarket_story[34]->options.push_back("Force the door open");
    supermarket_story[34]->options.push_back("Look for a key nearby");
    // Connect "Follow the cart" option (first option of node 33) to node 34.
    supermarket_story[33]->next.push_back(supermarket_story[34]);

    // Node 35: Outcome for "Force the door open"
    supermarket_story[35] = new story;
    supermarket_story[35]->text = "You break the door with a loud crash, but scrape your arm.";
    supermarket_story[35]->options.push_back("Move on");
    supermarket_story[35]->reward = vector<string>{"health -1"};
    // Connect first option of node 34 to node 35.
    supermarket_story[34]->next.push_back(supermarket_story[35]);

    // Node 36: Outcome for "Look for a key nearby"
    supermarket_story[36] = new story;
    supermarket_story[36]->text = "You find a rusty key behind a display that fits the lock perfectly.";
    supermarket_story[36]->options.push_back("Enter the backroom");
    // Connect second option of node 34 to node 36.
    

    // Branch 1.2: "Examine the shelves"
    // Node 37
    supermarket_story[37] = new story;
    supermarket_story[37]->text = "You inspect the shelves and discover a hidden snack cabinet.";
    supermarket_story[37]->options.push_back("Grab some snacks");
    supermarket_story[37]->reward = vector<string>{"health +1"};
    // Connect second option of node 33 to node 37.
    supermarket_story[33]->next.push_back(supermarket_story[37]);

    // --- Branch 2: Keep shopping normally ---
    // Node 38
    supermarket_story[38] = new story;
    supermarket_story[38]->text = "You continue shopping. A blinking security camera catches your eye.";
    supermarket_story[38]->options.push_back("Investigate the camera");
    supermarket_story[38]->options.push_back("Ignore it");
    // Connect "Keep shopping normally" option to node 38.
    supermarket_story[32]->next.push_back(supermarket_story[38]);

    // Branch 2.1: "Investigate the camera"
    // Node 39
    supermarket_story[39] = new story;
    supermarket_story[39]->text = "The camera shows a dark staff room where strange shadows dance.";
    supermarket_story[39]->options.push_back("Enter the staff room");
    supermarket_story[39]->reward = vector<string>{"sanity -1"};
    // Connect first option of node 38 to node 39.
    supermarket_story[38]->next.push_back(supermarket_story[39]);

    // Branch 2.2: "Ignore it"
    // Node 40
    supermarket_story[40] = new story;
    supermarket_story[40]->text = "You ignore the camera, yet the unsettling feeling lingers as you finish shopping.";
    supermarket_story[40]->options.push_back("Finish shopping");
    supermarket_story[40]->reward = vector<string>{"sanity +1"};
    // Connect second option of node 38 to node 40.
    supermarket_story[38]->next.push_back(supermarket_story[40]);

    //you cannot find a key
    supermarket_story[41] = new story;
    supermarket_story[41]-> text = "You search for a key, but the door remains locked.";
    supermarket_story[41]-> options.push_back("Leave the backroom");
    supermarket_story[41]-> next.push_back(nullptr);

    if (rand() % 10 > 4 + gs.difficulty)
    { // successfully open the door
        // mvprintw(3,0,"%d cf %d",rand(),INT_MAX/2 - gs.difficulty*1000);
        supermarket_story[34]->next.push_back(supermarket_story[36]);
    }
    else
    {
        supermarket_story[34]->next.push_back(supermarket_story[41]); // fail to open
    }

    

    supermarket_story[42] = new story;
    supermarket_story[42]->text = "In the supermarket, you find a strange hatch hidden beneath stacks of flour bags.";
    supermarket_story[42]->options.push_back("Open the hatch");
    supermarket_story[42]->options.push_back("Ignore it and keep shopping");

    // --- Branch 1: Open the hatch ---
    // Node 43: Describe the hatch.
    supermarket_story[43] = new story;
    supermarket_story[43]->text = "The hatch is heavy and locked tight. You notice a faint glow coming from inside.";
    supermarket_story[43]->options.push_back("Try to force it open");
    supermarket_story[42]->next.push_back(supermarket_story[43]);

    // Pre-create the outcome nodes for the difficulty check.
    // Node 47: Success outcome.
    supermarket_story[47] = new story;
    supermarket_story[47]->text = "You force the hatch open, revealing a hidden stash of supplies.";
    supermarket_story[47]->options.push_back("Take the supplies");
    supermarket_story[47]->reward = vector<string>{"bullet +1"};

    // Node 48: Failure outcome.
    supermarket_story[48] = new story;
    supermarket_story[48]->text = "The hatch resists your efforts, leaving you tired and bruised.";
    supermarket_story[48]->options.push_back("Step back");
    supermarket_story[48]->reward = vector<string>{"health -1"};

    // Node 44: Attempt to open the hatch.
    supermarket_story[44] = new story;
    supermarket_story[44]->text = "You brace yourself and try to open the hatch.";
    supermarket_story[44]->options.push_back("Give it your best shot");

    // Difficulty check to determine if the hatch opens.
    if (rand() % 10 > 4 + gs.difficulty)
    { 
        // Successfully open the hatch.
        // mvprintw(3,0,"%d cf %d",rand(),INT_MAX/2 - gs.difficulty*1000);
        supermarket_story[44]->next.push_back(supermarket_story[47]);
    }
    else
    {
        // Fail to open the hatch.
        supermarket_story[44]->next.push_back(supermarket_story[48]);
    }
    // Connect the option "Try to force it open" at Node 43 to Node 44 (the attempt logic).
    supermarket_story[43]->next.push_back(supermarket_story[44]);

    // --- Branch 2: Ignore the hatch ---
    // Node 45: Alternative branch from Node 42.
    supermarket_story[45] = new story;
    supermarket_story[45]->text = "You walk away from the hatch, but its eerie glow sticks in your mind.";
    supermarket_story[45]->options.push_back("Keep shopping");
    supermarket_story[45]->reward = vector<string>{"sanity -1"};
    supermarket_story[42]->next.push_back(supermarket_story[45]);





    supermarket_story[46] = new story;
    supermarket_story[46]->text = "In a quiet corner of the supermarket, a cooler hums loudly. Inside, you see a strange glowing jar.";
    supermarket_story[46]->options.push_back("Take the jar");
    supermarket_story[46]->options.push_back("Leave it alone");

    // --- Branch 1: Take the jar ---
    // Node 47: Describe taking the jar.
    supermarket_story[47] = new story;
    supermarket_story[47]->text = "You grab the jar. It feels heavier than it looks.";
    supermarket_story[47]->options.push_back("Open the jar");
    supermarket_story[46]->next.push_back(supermarket_story[47]);

    // Pre-create the outcome nodes for the difficulty check.
    // Node 50: Success outcome.
    supermarket_story[50] = new story;
    supermarket_story[50]->text = "The jar opens easily, revealing extra ammo hidden inside.";
    supermarket_story[50]->options.push_back("Take the ammo");
    supermarket_story[50]->reward = vector<string>{"bullet +1"};

    // Node 51: Failure outcome.
    supermarket_story[51] = new story;
    supermarket_story[51]->text = "The jar slips from your hands, shattering on the ground. The strange glow fades.";
    supermarket_story[51]->options.push_back("Step away");
    supermarket_story[51]->reward = vector<string>{"sanity -1"};

    // Node 48: Attempt to open the jar.
    supermarket_story[48] = new story;
    supermarket_story[48]->text = "You try to open the jar. The lid is stuck tight.";
    supermarket_story[48]->options.push_back("Keep twisting the lid");

    // Difficulty check to determine if the jar opens.
    if (rand() % 10 > 5 + gs.difficulty)
    { 
        // Successfully open the jar.
        // mvprintw(3,0,"%d cf %d",rand(),INT_MAX/2 - gs.difficulty*1000);
        supermarket_story[48]->next.push_back(supermarket_story[50]);
    }
    else
    {
        // Fail to open the jar.
        supermarket_story[48]->next.push_back(supermarket_story[51]);
    }
    // Connect the option "Open the jar" at Node 47 to Node 48 (the attempt logic).
    supermarket_story[47]->next.push_back(supermarket_story[48]);

    // --- Branch 2: Leave the jar alone ---
    // Node 49: Alternative branch from Node 46.
    supermarket_story[49] = new story;
    supermarket_story[49]->text = "You leave the glowing jar untouched, but its hum lingers in your ears.";
    supermarket_story[49]->options.push_back("Walk away quickly");
    supermarket_story[49]->reward = vector<string>{"sanity +1"};
    supermarket_story[46]->next.push_back(supermarket_story[49]);



    supermarket_story[55] = new story;
    supermarket_story[55]->text = "In the noisy supermarket, you notice a small quiet lounge tucked away near the exit.";
    supermarket_story[55]->options.push_back("Sit and relax");
    supermarket_story[55]->options.push_back("Keep rushing");

    // --- Branch 1: Sit and relax (leads to sanity plus) ---
    // Node 56: You decide to take a break.
    supermarket_story[56] = new story;
    supermarket_story[56]->text = "You step into the lounge, where soft music and comfortable chairs invite you to unwind.";
    supermarket_story[56]->options.push_back("Close your eyes and breathe");
    supermarket_story[55]->next.push_back(supermarket_story[56]);

    // Node 57: Meditation success resulting in sanity improvement.
    supermarket_story[57] = new story;
    supermarket_story[57]->text = "As you focus on your breath, a deep calm washes over you. The store's chaos fades away, leaving you renewed.";
    supermarket_story[57]->options.push_back("Open your eyes, feeling refreshed");
    supermarket_story[57]->reward = vector<string>{"sanity +1"};
    supermarket_story[56]->next.push_back(supermarket_story[57]);

    // --- Branch 2: Keep rushing ---
    // Node 58: You choose not to take a break.
    supermarket_story[58] = new story;
    supermarket_story[58]->text = "You decide there’s no time to rest and push on with your frantic shopping.";
    supermarket_story[58]->options.push_back("Race to the checkout");
    supermarket_story[55]->next.push_back(supermarket_story[58]);

    // Node 59: The consequence of rushing leaves you more stressed.
    supermarket_story[59] = new story;
    supermarket_story[59]->text = "In your rush, the noise and bustle overwhelm you, leaving you feeling unsettled and distracted.";
    supermarket_story[59]->options.push_back("Try to calm down later");
    // (No reward is given here—this branch lacks the calming effect.)
    supermarket_story[58]->next.push_back(supermarket_story[59]);


    // =================== Story 1: "The Self-Checkout Enigma" ===================
    // Starting at index 60.
    supermarket_story[60] = new story;
    supermarket_story[60]->text = "At the self-checkout, a glitchy kiosk stares at you.";
    supermarket_story[60]->options.push_back("Try to scan");
    supermarket_story[60]->options.push_back("Ask for help");

    // Branch 1.1: "Try to scan" (from the first option).
    supermarket_story[61] = new story;
    supermarket_story[61]->text = "You press the scan button repeatedly.";
    supermarket_story[61]->options.push_back("Wait for it...");
    supermarket_story[60]->next.push_back(supermarket_story[61]);

    // Difficulty branch for scanning:
    // Node 62: Success outcome.
    supermarket_story[62] = new story;
    supermarket_story[62]->text = "The machine prints your receipt flawlessly.";
    supermarket_story[62]->options.push_back("Collect receipt");
    supermarket_story[62]->reward = vector<string>{"bullet +1"};
    // Node 63: Failure outcome.
    supermarket_story[63] = new story;
    supermarket_story[63]->text = "The machine jams and zaps you with a shock.";
    supermarket_story[63]->options.push_back("Step back");
    supermarket_story[63]->reward = vector<string>{"sanity -1"};

    if (rand() % 10 > 4 + gs.difficulty) {
        supermarket_story[61]->next.push_back(supermarket_story[62]);
    } else {
        supermarket_story[61]->next.push_back(supermarket_story[63]);
    }

    // Branch 1.2: "Ask for help" (from the second option of node 60).
    supermarket_story[64] = new story;
    supermarket_story[64]->text = "An attendant helps reset the machine.";
    supermarket_story[64]->options.push_back("Thank them");
    supermarket_story[64]->reward = vector<string>{"sanity +1"};
    supermarket_story[60]->next.push_back(supermarket_story[64]);

    // =================== Story 2: "Dairy Aisle Dilemma" ===================
    // Starting at index 65.
    supermarket_story[65] = new story;
    supermarket_story[65]->text = "In the dairy aisle, you spot a shiny coupon on a milk carton.";
    supermarket_story[65]->options.push_back("Check the coupon");
    supermarket_story[65]->options.push_back("Ignore it");

    // Branch 2.1: "Check the coupon".
    supermarket_story[66] = new story;
    supermarket_story[66]->text = "You examine the coupon closely.";
    supermarket_story[66]->options.push_back("Scrutinize it");
    supermarket_story[65]->next.push_back(supermarket_story[66]);

    // Difficulty check for coupon authenticity:
    // Node 67: Success outcome.
    supermarket_story[67] = new story;
    supermarket_story[67]->text = "The coupon is valid — your day brightens with savings!";
    supermarket_story[67]->options.push_back("Smile");
    supermarket_story[67]->reward = vector<string>{"sanity +1"};
    // Node 68: Failure outcome.
    supermarket_story[68] = new story;
    supermarket_story[68]->text = "The coupon is expired. But you really don't care";
    supermarket_story[68]->options.push_back("Sigh");
    supermarket_story[68]->reward = vector<string>{"sanity +1"};

    if (rand() % 10 > 4 + gs.difficulty) {
        supermarket_story[66]->next.push_back(supermarket_story[67]);
    } else {
        supermarket_story[66]->next.push_back(supermarket_story[68]);
    }

    // Branch 2.2: "Ignore it".
    supermarket_story[69] = new story;
    supermarket_story[69]->text = "You walk away, feeling a slight twinge of regret.";
    supermarket_story[69]->options.push_back("Continue shopping");
    supermarket_story[69]->reward = vector<string>{"sanity -1"};
    supermarket_story[65]->next.push_back(supermarket_story[69]);

    // =================== Story 3: "Spooky Snack Aisle" ===================
    // Starting at index 70.
    supermarket_story[70] = new story;
    supermarket_story[70]->text = "The snack aisle whispers with eerie sounds.";
    supermarket_story[70]->options.push_back("Enter the aisle");
    supermarket_story[70]->options.push_back("Hurry along");

    // Branch 3.1: "Enter the aisle".
    supermarket_story[71] = new story;
    supermarket_story[71]->text = "Inside, a spectral figure appears among the chips.";
    supermarket_story[71]->options.push_back("Talk to the figure");
    supermarket_story[70]->next.push_back(supermarket_story[71]);

    // Difficulty check with the spectral figure:
    // Node 72: Success outcome.
    supermarket_story[72] = new story;
    supermarket_story[72]->text = "The spirit shares a secret recipe that eases your mind.";
    supermarket_story[72]->options.push_back("Listen intently");
    supermarket_story[72]->reward = vector<string>{"sanity +3"};
    // Node 73: Failure outcome.
    supermarket_story[73] = new story;
    supermarket_story[73]->text = "The spirit vanishes, leaving you more unsettled.";
    supermarket_story[73]->options.push_back("Flee");
    supermarket_story[73]->reward = vector<string>{"sanity -1"};

    if (rand() % 10 > 4 + gs.difficulty) {
        supermarket_story[71]->next.push_back(supermarket_story[72]);
    } else {
        supermarket_story[71]->next.push_back(supermarket_story[73]);
    }

    // Branch 3.2: "Hurry along".
    supermarket_story[74] = new story;
    supermarket_story[74]->text = "You rush by, yet a lingering chill shadows your steps.";
    supermarket_story[74]->options.push_back("Shake it off");
    supermarket_story[74]->reward = vector<string>{"sanity -1"};
    supermarket_story[70]->next.push_back(supermarket_story[74]);

    // =================== Story 4: "Gadget Gamble" ===================
    // Starting at index 75.
    supermarket_story[75] = new story;
    supermarket_story[75]->text = "At the electronics section, a discounted gadget catches your eye.";
    supermarket_story[75]->options.push_back("Try to grab it");
    supermarket_story[75]->options.push_back("Leave it");

    // Branch 4.1: "Try to grab it".
    supermarket_story[76] = new story;
    supermarket_story[76]->text = "You approach a locked display case guarding the gadget.";
    supermarket_story[76]->options.push_back("Attempt to unlock it");
    supermarket_story[75]->next.push_back(supermarket_story[76]);

    // Difficulty check for unlocking the case:
    // Node 77: Success outcome.
    supermarket_story[77] = new story;
    supermarket_story[77]->text = "You unlock the case and seize the gadget.";
    supermarket_story[77]->options.push_back("Claim the gadget");
    supermarket_story[77]->reward = vector<string>{"bullet +1"};
    // Node 78: Failure outcome.
    supermarket_story[78] = new story;
    supermarket_story[78]->text = "The case remains secure, and a small alarm startles you.";
    supermarket_story[78]->options.push_back("Step back");
    supermarket_story[78]->reward = vector<string>{"sanity -1"};

    if (rand() % 10 > 4 + gs.difficulty) {
        supermarket_story[76]->next.push_back(supermarket_story[77]);
    } else {
        supermarket_story[76]->next.push_back(supermarket_story[78]);
    }

    // Branch 4.2: "Leave it".
    supermarket_story[79] = new story;
    supermarket_story[79]->text = "You turn away from the gadget, surprisingly relieved.";
    supermarket_story[79]->options.push_back("Continue browsing");
    supermarket_story[79]->reward = vector<string>{"sanity +1"};
    supermarket_story[75]->next.push_back(supermarket_story[79]);

    // =================== Story 5: "Exotic Drink Riddle" ===================
    // Starting at index 80.
    supermarket_story[80] = new story;
    supermarket_story[80]->text = "In the beverage aisle, exotic drinks shimmer under neon lights.";
    supermarket_story[80]->options.push_back("Try a drink");
    supermarket_story[80]->options.push_back("Skip the shelf");

    // Branch 5.1: "Try a drink".
    supermarket_story[81] = new story;
    supermarket_story[81]->text = "You twist open a vibrant bottle.";
    supermarket_story[81]->options.push_back("Take a sip");
    supermarket_story[80]->next.push_back(supermarket_story[81]);

    // Difficulty check for the drink:
    // Node 82: Success outcome.
    supermarket_story[82] = new story;
    supermarket_story[82]->text = "The drink rejuvenates you, washing away your stress.";
    supermarket_story[82]->options.push_back("Sip happily");
    supermarket_story[82]->reward = vector<string>{"sanity +1"};
    // Node 83: Failure outcome.
    supermarket_story[83] = new story;
    supermarket_story[83]->text = "The drink is bitter, leaving an unwelcome aftertaste.";
    supermarket_story[83]->options.push_back("Wince");
    supermarket_story[83]->reward = vector<string>{"health -1"};

    if (rand() % 10 > 4 + gs.difficulty) {
        supermarket_story[81]->next.push_back(supermarket_story[82]);
    } else {
        supermarket_story[81]->next.push_back(supermarket_story[83]);
    }

    // Branch 5.2: "Skip the shelf".
    supermarket_story[84] = new story;
    supermarket_story[84]->text = "You pass by, with a faint regret at missing a taste of adventure.";
    supermarket_story[84]->options.push_back("Move ahead");
    supermarket_story[84]->reward = vector<string>{"sanity -1"};
    supermarket_story[80]->next.push_back(supermarket_story[84]);

    // =================== Story 6: "Secret Employee Lounge" ===================
    // Starting at index 85.
    supermarket_story[85] = new story;
    supermarket_story[85]->text = "Behind a hidden door, a quiet lounge offers a respite from the chaos.";
    supermarket_story[85]->options.push_back("Rest in the lounge");
    supermarket_story[85]->options.push_back("Keep shopping");

    // Branch 6.1: "Rest in the lounge".
    supermarket_story[86] = new story;
    supermarket_story[86]->text = "You sink into a comfy chair as soft music soothes your mind.";
    supermarket_story[86]->options.push_back("Relax fully");
    supermarket_story[86]->reward = vector<string>{"sanity +1"};
    supermarket_story[85]->next.push_back(supermarket_story[86]);

    // Branch 6.2: "Keep shopping".
    supermarket_story[87] = new story;
    supermarket_story[87]->text = "You pass the lounge, but an uneasy tension lingers.";
    supermarket_story[87]->options.push_back("Hurry on");
    supermarket_story[87]->reward = vector<string>{"sanity -1"};
    supermarket_story[85]->next.push_back(supermarket_story[87]);







    
}

void initialize_UI_stories()
{
    UI_stories.push_back(new story);
    UI_stories[0]->text = "Let's go directly back to the shelter";
    UI_stories[0]->options.push_back("Start Night Time");
    UI_stories[0]->next.push_back(nullptr);

    UI_stories.push_back(new story);
    UI_stories[1]->text = "☀The dawn is breaking after a sweat sweat night☀";
    UI_stories[1]->options.push_back("Wake up");
    UI_stories[1]->next.push_back(nullptr);

    UI_stories.push_back(new story);
    UI_stories[2]->text = "The boss is standing in front of you";
    UI_stories[2]->options.push_back("Check your status");
    UI_stories[2]->next.push_back(nullptr);

    UI_stories.push_back(new story);
    UI_stories[3]->text = "You shoot a bullet";
    UI_stories[3]->options.push_back("Continue shooting");
    UI_stories[3]->next.push_back(nullptr);

    UI_stories.push_back(new story);
    UI_stories[4]->text = "You hit the boss with bare hands";
    UI_stories[4]->options.push_back("Continue fighting");
    UI_stories[4]->next.push_back(nullptr);
    
    UI_stories.push_back(new story);
    UI_stories[5]->text = "The boss hit you";
    UI_stories[5]->options.push_back("Continue fighting");
    UI_stories[5]->next.push_back(nullptr);

    UI_stories.push_back(new story); // for boss fight use;

}

vector<story *> knocking_door;

void initialize_knocking_door()
{

    for (int i = 0; i <= 16; i++)
    {
        knocking_door.push_back(new story);
    }

    knocking_door[0]->text = "You hear someone knocking the door";
    knocking_door[0]->options.push_back("Go to check the peekhole"); // Random: 1. Nothing Outside 2.A weird guy 3.A giant cockroach

    // 1. Nothing Outside story
    knocking_door[1]->text = "You see nothing outside, you wonder who knocked the door";
    knocking_door[1]->options.push_back("Go out and check");
    knocking_door[1]->options.push_back("Lock the door and go back to the bedroom");
    knocking_door[2]->text = "After walking a few steps in the dark, you hear a scream and suddenly got scrached by a woman covered in blood.";
    knocking_door[2]->options.push_back("Fight the woman");
    knocking_door[2]->options.push_back("Run back home");
    knocking_door[3]->text = "The woman killed you before you can draw your weapon, you should've never come outside at night";
    knocking_door[3]->options.push_back("End Game");
    knocking_door[3]->next.push_back(nullptr);
    knocking_door[3]->reward = {"death"}; // game ends here
    knocking_door[4]->text = "You rushed back home and slamed the door behind you";
    knocking_door[4]->options.push_back("End conversation");
    knocking_door[4]->next.push_back(nullptr);
    knocking_door[5]->text = "The knocking started again and continued for a while, but ended eventually";
    knocking_door[5]->options.push_back("End conversation");
    knocking_door[5]->next.push_back(nullptr);

    // 2. A weird guy story
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
    knocking_door[8]->reward = {"food -1", "bullet +1"};
    knocking_door[9]->text = "You pushed him away and locked the door again";
    knocking_door[9]->options.push_back("End conversation");
    knocking_door[9]->next.push_back(nullptr);
    knocking_door[10]->text = "You poke him in the eye, but got stabbed by him; you killed him with his own knife";
    knocking_door[10]->options.push_back("Search his body");
    knocking_door[11]->text = "You found a silver key inside his pocket";
    knocking_door[11]->options.push_back("End conversation");
    knocking_door[11]->next.push_back(nullptr);
    knocking_door[11]->reward = {"inventory silver key"};

    // 3. A giant cockroach story
    knocking_door[12]->text = "You see a giant cockroach standing outside";
    knocking_door[12]->options.push_back("Go out to check the cockroach");
    knocking_door[12]->options.push_back("Lock the door and go back to the bedroom");
    knocking_door[13]->text = "The cockroach saw you, and quickly runs away";
    knocking_door[13]->options.push_back("Chase it");               // 14
    knocking_door[13]->options.push_back("Shoot it with a bullet"); // 15
    knocking_door[13]->options.push_back("Go back home");           // 16
    knocking_door[14]->text = "You chase the cockroach for a while, and suddenly fall in to a pit; you got eaten alive by a number of cockroaches";
    knocking_door[14]->options.push_back("End Game");
    knocking_door[14]->next.push_back(nullptr);
    knocking_door[14]->reward = {"death"}; // game ends here
    knocking_door[15]->text = "You shot a bullet at the cockroach, but you missed since it's too dark outside";
    knocking_door[15]->options.push_back("Chase the cockroach");
    knocking_door[15]->options.push_back("Go back home");
    knocking_door[15]->reward = {"bullet -1"};
    knocking_door[16]->text = "You got back home safely";
    knocking_door[16]->options.push_back("End conversation");
    knocking_door[16]->next.push_back(nullptr);

    int random_branch = generate_random_num(0, 2);

    if (random_branch == 0)
    {
        // 1. Nothing Outside branch
        knocking_door[0]->next = vector<story *>{knocking_door[1]};
        knocking_door[1]->next = vector<story *>{knocking_door[2], knocking_door[5]};
        knocking_door[2]->next = vector<story *>{knocking_door[3], knocking_door[4]};
    }
    else if (random_branch == 1)
    {
        // 2. A weird guy branch
        knocking_door[0]->next = vector<story *>{knocking_door[6]};
        knocking_door[6]->next = vector<story *>{knocking_door[7], knocking_door[5]};
        knocking_door[7]->next = vector<story *>{knocking_door[8], knocking_door[9], knocking_door[10]};
        knocking_door[10]->next = vector<story *>{knocking_door[11]};
    }
    else
    {
        // 3. Giant cockroach story
        knocking_door[0]->next = vector<story *>{knocking_door[12]};
        knocking_door[12]->next = vector<story *>{knocking_door[13], knocking_door[5]};
        knocking_door[13]->next = vector<story *>{knocking_door[14], knocking_door[15], knocking_door[16]};
        knocking_door[15]->next = vector<story *>{knocking_door[14], knocking_door[16]};
    }
}

vector<story *> glass_breaking_noise;

void initialize_glass_breanking_noise()
{

    for (int i = 0; i <= 14; i++)
    {
        glass_breaking_noise.push_back(new story);
    }

    glass_breaking_noise[0]->text = "You hear the sound of glass breaking, it's likely from the kitchen";
    glass_breaking_noise[0]->options.push_back("Go to kitchen to check");
    glass_breaking_noise[0]->options.push_back("Ignore the noise");

    // 1. cockroach story
    glass_breaking_noise[1]->text = "You see a giant cockroach with a broken leg, and some shattered glasses on the ground";
    glass_breaking_noise[1]->options.push_back("Go to help the cockroach and fix its leg");   // 2
    glass_breaking_noise[1]->options.push_back("Kill the cockroach");                         // 3
    glass_breaking_noise[1]->options.push_back("Leave the cockroach bleeding on the ground"); // 4
    glass_breaking_noise[2]->text = "The cockroach spits a bottle, there is a paper slip inside";
    glass_breaking_noise[2]->options.push_back("End conversation");
    glass_breaking_noise[2]->next.push_back(nullptr);
    glass_breaking_noise[2]->reward = {"inventory paper slip"}; // might link to main story
    glass_breaking_noise[3]->text = "Green blood exploded from the cockroach and corroded your skin";
    glass_breaking_noise[3]->options.push_back("End conversation");
    glass_breaking_noise[3]->next.push_back(nullptr);
    glass_breaking_noise[3]->reward = {"health -1"};
    glass_breaking_noise[4]->text = "You went back to the bedroom";
    glass_breaking_noise[4]->options.push_back("End conversation");
    glass_breaking_noise[4]->next.push_back(nullptr);

    // 2. intruder story
    glass_breaking_noise[5]->text = "You see a guy in the kitchen, acting like a thief";
    glass_breaking_noise[5]->options.push_back("Go talk to him");                                   // 6
    glass_breaking_noise[5]->options.push_back("Quitely aim at him and shoot him");                 // 9
    glass_breaking_noise[5]->options.push_back("Quitely go back to the bedroom and lock the door"); // 4
    glass_breaking_noise[6]->text = "He got suprised by you, he said he thought this is a ruined place and he is only looking for food";
    glass_breaking_noise[6]->options.push_back("Give hime some food");
    glass_breaking_noise[6]->options.push_back("Quickly shoot at him");
    glass_breaking_noise[7]->text = "He thanked you and give you two bullets for return";
    glass_breaking_noise[7]->options.push_back("End conversation");
    glass_breaking_noise[7]->next.push_back(nullptr);
    glass_breaking_noise[7]->reward = {"bullet +1", "food -1"};
    glass_breaking_noise[8]->text = "The gun shot killed him instently, you searched him and found a water bottle";
    glass_breaking_noise[8]->options.push_back("End conversation");
    glass_breaking_noise[8]->next.push_back(nullptr);
    glass_breaking_noise[8]->reward = {"bullet -1, water +1"};
    glass_breaking_noise[9]->text = "You missed, he run away through the window";
    glass_breaking_noise[9]->options.push_back("End conversation");
    glass_breaking_noise[9]->next.push_back(nullptr);
    glass_breaking_noise[9]->reward = {"bullet - 1"};

    // 3. cat story
    glass_breaking_noise[10]->text = "You see a cute cat";
    glass_breaking_noise[10]->options.push_back("Shoot it");               // 11
    glass_breaking_noise[10]->options.push_back("Get close to examin it"); // 12
    glass_breaking_noise[10]->options.push_back("Go back to the bedroom"); // 4
    glass_breaking_noise[11]->text = "Congrats, you kill a cat, your sanity drops because of the shame";
    glass_breaking_noise[11]->options.push_back("End conversation");
    glass_breaking_noise[11]->next.push_back(nullptr);
    glass_breaking_noise[11]->reward = {"sanity -1"};
    glass_breaking_noise[12]->text = "The cat got scared, it run out of the window";
    glass_breaking_noise[12]->options.push_back("Chase it");               // 13
    glass_breaking_noise[12]->options.push_back("Go back to the bedroom"); // 4
    glass_breaking_noise[13]->text = "You chased it for a while, but you lost track and the cat disappreared";
    glass_breaking_noise[13]->options.push_back("Go find the cat"); // 14
    glass_breaking_noise[13]->options.push_back("Go back home");    // 4
    glass_breaking_noise[14]->text = "You suddently run into a pit, and you got eaten by a bunch of cockroaches";
    glass_breaking_noise[14]->options.push_back("End game");
    glass_breaking_noise[14]->next.push_back(nullptr);
    glass_breaking_noise[14]->reward = {"death"};

    int random_branch = generate_random_num(0, 2);

    if (random_branch == 0)
    {
        // cockroach branch
        glass_breaking_noise[0]->next = vector<story *>{glass_breaking_noise[1], glass_breaking_noise[4]};
        glass_breaking_noise[1]->next = vector<story *>{glass_breaking_noise[2], glass_breaking_noise[3], glass_breaking_noise[4]};
    }
    else if (random_branch == 1)
    {
        // intruder branch
        glass_breaking_noise[0]->next = vector<story *>{glass_breaking_noise[5], glass_breaking_noise[4]};
        glass_breaking_noise[5]->next = vector<story *>{glass_breaking_noise[6], glass_breaking_noise[9], glass_breaking_noise[4]};
        glass_breaking_noise[6]->next = vector<story *>{glass_breaking_noise[7], glass_breaking_noise[8]};
    }
    else
    {
        // cat branch
        glass_breaking_noise[0]->next = vector<story *>{glass_breaking_noise[10], glass_breaking_noise[4]};
        glass_breaking_noise[10]->next = vector<story *>{glass_breaking_noise[11], glass_breaking_noise[12], glass_breaking_noise[4]};
        glass_breaking_noise[12]->next = vector<story *>{glass_breaking_noise[13], glass_breaking_noise[4]};
        glass_breaking_noise[13]->next = vector<story *>{glass_breaking_noise[14], glass_breaking_noise[4]};
    }
}

vector<story *> lights_off;

void initialize_lights_off()
{

    for (int i = 0; i <= 15; i++)
    {
        lights_off.push_back(new story);
    }

    lights_off[0]->text = "You are chilling in the room, but the light suddenly goes off";
    lights_off[0]->options.push_back("Go to the window to check");
    lights_off[0]->options.push_back("Ignore the light");

    //1:spider story
    lights_off[1]->text = "You see a spider biting the cable, that might be the reason of why light went off";
    lights_off[1]->options.push_back("Go out to check the spider"); //3
    lights_off[1]->options.push_back("Stay inside"); //2
    lights_off[2]->text = "After a while the light went back on, but the darkness scared you";
    lights_off[2]->options.push_back("End conversation");
    lights_off[2]->next.push_back(nullptr);
    lights_off[2]->reward = {"sanity -1"};
    lights_off[3]->text = "The spider rushed towards you";
    lights_off[3]->options.push_back("Fight it with your fist"); //4
    lights_off[3]->options.push_back("Shoot it with a gun"); //5
    lights_off[3]->options.push_back("Run back home"); //6
    lights_off[4]->text = "You killed the spider but you also got severly hurt, the meat from the spider is good quality protein";
    lights_off[4]->options.push_back("End conversation");
    lights_off[4]->next.push_back(nullptr);
    lights_off[4]->reward = {"food +1, health -2"};
    lights_off[5]->text = "You killed the spider with a bullet, the meat from the spider is good quality protein";
    lights_off[5]->options.push_back("End conversation");
    lights_off[5]->next.push_back(nullptr);
    lights_off[5]->reward = {"food +1", "bullet -1"};
    lights_off[6]->text = "The spider is too fast, he bite your neck from the back, you died";
    lights_off[6]->options.push_back("End game");
    lights_off[6]->next.push_back(nullptr);
    lights_off[6]->reward = {"death"};

    //2: Zombie story
    lights_off[7]->text = "You see a zombie kicking the cable, that might be the reason of why light went off";
    lights_off[7]->options.push_back("Go out to check the zombie"); //8
    lights_off[7]->options.push_back("Stay inside"); //2
    lights_off[8]->text = "The zombie sees you and starts to move towards you";
    lights_off[8]->options.push_back("Fight it with your fist"); //9
    lights_off[8]->options.push_back("Shoot it with a gun"); //11
    lights_off[8]->options.push_back("Run back home"); //12
    lights_off[9]->text = "You killed the zombie with your fist but you also got injured";
    lights_off[9]->options.push_back("Search the zombie"); //10
    lights_off[10]->text = "The zombie's body is disgusting, but you got an apple in its pocket";
    lights_off[10]->options.push_back("End conversation"); 
    lights_off[10]->next.push_back(nullptr);
    lights_off[10]->reward = {"sanity -1, health -2, food +1"};
    lights_off[11]->text = "You killed the zombie with a bullet, and got an apple that falled out of its pocket";
    lights_off[11]->options.push_back("End conversation");
    lights_off[11]->next.push_back(nullptr);
    lights_off[11]->reward = {"bullet -1, food +1"};
    lights_off[12]->text = "You got back home";
    lights_off[12]->options.push_back("Continue");//2

    //3: water story
    lights_off[13]->text = "There is heavy rain outside, and the flood destroyed the cable";
    lights_off[13]->options.push_back("Co out to fix the cable"); //14
    lights_off[13]->options.push_back("Open the window to collect rain water"); //15
    lights_off[13]->options.push_back("Stay inside and keep the door locked"); //2
    lights_off[14]->text = "You got electricuted when you got close to the cable"; 
    lights_off[14]->options.push_back("End game"); 
    lights_off[14]->next.push_back(nullptr);
    lights_off[14]->reward = {"death"};
    lights_off[15]->text = "You got some clean rain water"; 
    lights_off[15]->options.push_back("End conversation"); 
    lights_off[15]->next.push_back(nullptr);
    lights_off[15]->reward = {"water +1"};

    int random_branch = generate_random_num(0, 2);
    if (random_branch == 0)
    {
        // spider branch
        lights_off[0]->next = vector<story *>{lights_off[1], lights_off[2]};
        lights_off[1]->next = vector<story *>{lights_off[3], lights_off[2]};
        lights_off[3]->next = vector<story *>{lights_off[4], lights_off[5], lights_off[6]};
    }
    else if (random_branch == 1)
    {
        // zombie branch
        lights_off[0]->next = vector<story *>{lights_off[7], lights_off[2]};
        lights_off[7]->next = vector<story *>{lights_off[8], lights_off[2]};
        lights_off[8]->next = vector<story *>{lights_off[9], lights_off[11], lights_off[12]};
        lights_off[9]->next = vector<story *>{lights_off[10]};
        lights_off[12]->next = vector<story *>{lights_off[2]};
    }
    else
    {
        // water branch
        lights_off[0]->next = vector<story *>{lights_off[13], lights_off[2]};
        lights_off[13]->next = vector<story *>{lights_off[14], lights_off[15], lights_off[2]};
    }
}

vector<story *> temperature_drop;

void initialize_tempreature_drop(){
    for (int i = 0; i <= 2; i++)
    {
        temperature_drop.push_back(new story);
    }
    temperature_drop[0]->text = "You are chilling in the room, but the room gets very chill and you could visibly see your breath";
    temperature_drop[0]->options.push_back("Eat food to get warmer"); //1
    temperature_drop[0]->options.push_back("Endured the cold"); //2
    temperature_drop[1]->text = "You endured the cold night by eating some food";
    temperature_drop[1]->options.push_back("End conversation"); 
    temperature_drop[1]->next.push_back(nullptr);
    temperature_drop[1]->reward.push_back("food -1"); 
    temperature_drop[2]->text = "Your got sick because of the cold";
    temperature_drop[2]->options.push_back("End conversation"); 
    temperature_drop[2]->next.push_back(nullptr);
    temperature_drop[2]->reward.push_back("health -1"); 
    
    temperature_drop[0]->next = vector<story *>{temperature_drop[1], temperature_drop[2]};
}

void initialize_stories()
{
    initialize_hospital_story();
    //nighttime stories
    initialize_knocking_door(); 
    initialize_glass_breanking_noise();
    initialize_lights_off();
    initialize_tempreature_drop();

    initialize_supermarket_story();
    initialize_UI_stories();

}
