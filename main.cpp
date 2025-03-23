#include <ncurses.h>
#include <bits/stdc++.h>//To be updated(when needed head files are clear)

using namespace std;

struct GameState{
    int day, food, water, difficulty, hunger, thirst, health,sanity;
    bool ill;//whether the player is ill
    int story_progress;//an integer to track where the player are on the main story line.
    int items[100];//numbers of items that the player owns
}; GameState gs={0,0,0,0,10,10,10,10,false,0,{0}};

struct Item{//each item owns a unique code and a name.
    int code;
    string name;
}; Item item_list[100];//list of all items that might appear in the game.

void init();
	//set all variables to initial value and read item_list from a file named "items".
void start();//show the start screen and options.
void load(string file);//if the player choose to load, load gamestate from a file
void save(string file);//save gamestate to a file.
void sixty_sec();//if the player choose to start a new game, do the "sixty seconds".
bool checkgs();//adjust and check the gamestate to determine whether to end the game or not after a day ends.
void start_a_day();
void start_explore();//explore in the daytime
void display_status(GameState gs)
{

	mvprintw(5,10,"Game Status\n");
	mvprintw(6,10,"Difficulty:%d\n",gs.difficulty);
	mvprintw(7,10,"Day:%d\n",gs.day);
	mvprintw(8,10,"Food:%d\n",gs.food);
	mvprintw(9,10,"Water:%d\n",gs.water);
	mvprintw(10,10,"Health:%d\n",gs.health);
	mvprintw(11,10,"Hunger:%d\n",gs.hunger);
	mvprintw(12,10,"Thirst:%d\n",gs.thirst);
	mvprintw(13,10,"Sanity:%d\n",gs.sanity);
	if (ill)
	{
		printw(14,10,"You are ill!!!");
	}

		

}



int main() {
    init();

    start();
    while (1){
        start_a_day()
        checkgs();
        gs.day++;
    }
    return 0;
}

void init(){
	char file[10]="items.txt";
	ifstream fin;
	int num=0;
	while (fin >> items_list[num].code >> items_list[num].name && num<100)
	{
		num++;
	}
	file.close();
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, true);
	nodelay(stdscr, true);

		

}

void start(){
    
}

void load(string file){
    
}

void save(string file){
    
}

void sixty_sec(){
    
}

bool checkgs(){
	int x=5,y=10;
	if (gs.food<0)
	{
		gs.hunger+=gs.food;
		mvprintw(x,y,"Your hunger level decreased due to insufficient food.");
	}
	if (gs.water<0)
	{
		gs.thist+=gs.water;
		x+=1;
		mvprintw(x,y,"Your thirst level decreased due to insufficient water.");
	}
	if(gs.sanity<0)
	{
		gs.health+=gs.sanity;
		x+=1;
		mvprintw(x,y,"Your health level decreased due to insufficient sanity.");
	}
	if (gs.hunger<0)
	{
		gs.health+=gs.hunger;
		x+=1;
		mvprintw(x,y,"Your health level decreased due to insufficient hunger.");
	}
	if (gs.thirst<0)
	{
		gs.health+=gs.thirst;
		x+=1;
		mvprintw(x,y,"Your health level decreased due to insufficient thirst.");
	}
	if (ill)
	{
		gs.health-=1;
		x+=1;
		mvprintw(x,y,"Your health level decreased due to illness.");
	}

	usleep(4000000);
	refresh();
	usleep(1000000);
	display_status(gs);
	if (gs.health<=0)
	{
		mvprintw(16,10,"You lose!!!");
		usleep(100000);
		retutn false;
	}
	return true;


}

void start_a_day(){

}

void start_explore(){

}
