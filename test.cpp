#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <string>
#include <vector>

using namespace std;


struct Player {

	int health;
	int hungry;
	int sanity;
};
Player P ={10, 10, 10};
void display_status(Player P)
{

	printw("Your Status\n");
	printw("Health:%d\n",P.health);
	printw("Hungry:%d\n",P.hungry);
	printw("Sanity:%d\n",P.sanity);

}

int main()
{


	initscr();
	cbreak();
	noecho();
	keypad(stdscr, true);
	nodelay(stdscr, true);

	printw("Press 'e' to check your status");
	printw("Press 'q' to quit");
	int ch;
	while (true)
	{
		ch=getch();
		if (ch=='e' || ch=='E')
		{
			display_status(P);
		}
		if (ch=='q' || ch=='Q')
		{
			break;
		}

	
		printw("1");
		refresh();
		usleep(100000);
	}

	endwin();
	return 0;
}
