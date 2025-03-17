#include <iostream>
#include <vector>
#include <ncurses.h>

using namespace std;
int difficulty=0;
struct Player{
  string name;
  int health;
  int hungry;
  int sanity;
  string inventory;// vector<string>
};

Player p1={"player", 100, 100, 10};
void display_player_status()
{
  initscr();
  WINDOW* window=newwin(10,30,0,0);
  case '
}
void display_player_status()
{
  cout << "---YOUR STATUS---"<< endl;
  cout << "Name: " << p1.name << endl;
  cout << "Health: " << p1.health << endl;
  cout << "Hungry: " << p1.hungry << endl;
  cout << "Sanity: " << p1.sanity << endl;
  cout << "Inventory: "<< p1.inventory << endl;
}

case 'e'
