#include <iostream>
#include <ncurses.h>
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include "../include/map_head.h"
using namespace std;

vector<string> menuMap = {
		R"(###############################################)",
		R"(#                                             #)",
		R"(#      _____ ______   ________  ________      #)",
		R"(#     |\   _ \  _   \|\   __  \|\   __  \     #)",
		R"(#     \ \  \\|__| \  \ \   __  \ \   ____\    #)",
		R"(#      \ \  \    \ \  \ \  \ \  \ \  \___|    #)",
		R"(#       \ \__\    \ \__\ \__\ \__\ \__\       #)",
		R"(#        \|__|     \|__|\|__|\|__|\|__|       #)",
		R"(#                                             #)",
		R"(#            Choose your destination          #)",
		R"(#               Shelter                       #)",
		R"(#               Supermarket                   #)",
		R"(#               Hospital                      #)",
		R"(#               Weapon Shop                   #)",
		R"(#               Exit                          #)",
		R"(#                                             #)",
		R"(###############################################)" };

/*vector<vector<char>> string_to_vector(vector<string> s)
{
	vector<vector<char>> v;
	for (int i = 0; i < s.size(); i++){
		v.push_back(vector<char>());
		for (int j = 0; j < s[0].size(); j++){
			v.back().push_back(s[i][j]);
		}
	}
	return v;
}*/

/*void clearnear(int x, int y, vector<vector<char>> map, int height, int width)
{
	int map_height = map.size();
	int map_width = map[0].size();
	int newX = x - (height - map_height) / 2;
	int newY = y - (width - map_width) / 2;
	if (newX >= 0 && newX < map_height && newY >= 0 && newY < map_width)
	{
		mvprintw(x,y, "%c", map[newX][newY]);
		mvprintw(x,y+1,"%c",map[newX][newY+1]);
	}
	else
	{
		cout << "out of bound\n";
	}
}*/

/*void drawmap (vector<vector<char>> map, int height, int width)
{
	int map_height = map.size();
        int map_width = map[0].size();
	for (int i = 0; i < map_height; i++)
	{
		for (int j = 0; j < map_width; j++)
		{
			mvprintw(i + (height - map_height) / 2, j + (width - map_width) / 2, "%c", map[i][j]);
		}
	}
}*/

int menu() // this will return an int value, 0 for shelter, 1 for hospital, 2 for weapon store, 3 for exit
{
	vector<vector<char>> map;
	map = string_to_vector(menuMap);
	initscr();
	noecho();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);

	int height, width;
	getmaxyx(stdscr, height, width);

	int ch;
	int characterpos[2] = {height / 2 + 2, width / 2 - 11};
	mvprintw(characterpos[0], characterpos[1], "->");
	drawmap(map, height, width);
	while ((ch = getch()) != 'q')
	{
		clearnear(characterpos[0], characterpos[1], map, height, width);
		clearnear(characterpos[0], characterpos[1]+1, map, height, width);
		mvprintw(1,0,"X %d Y %d", characterpos[0], characterpos[1]);
		int checkX, checkY, refX, refY;
		refX = characterpos[0] - (height - map.size()) / 2;
		refY = characterpos[1] - (width - map[0].size()) / 2;
		mvprintw(2,0, "refX %d refY %d", refX, refY);
		switch (ch)
        {
       		case KEY_UP:
            		mvprintw(0, 0, "Up arrow key pressed");
            		checkX = characterpos[0] - 1 - (height - map.size()) / 2;
            		checkY = characterpos[1] - (width - map[0].size()) / 2;
            		//mvprintw(4, 0, "checkX: %d", checkX);
            		//mvprintw(4, 11, "checkY: %d", checkY);
            		if (checkX != 9)
            		{
            		    	characterpos[0] -= 1;
            		}
			else
			{
				characterpos[0] += 4;
			}
            		break;
        	case KEY_DOWN:
            		mvprintw(0, 0, "Down arrow key pressed");
            		checkX = characterpos[0] + 1 - (height - map.size()) / 2;
            		checkY = characterpos[1] - (width - map[0].size()) / 2;
            		//mvprintw(4, 0, "checkX: %d", checkX);
            		//mvprintw(4, 11, "checkY: %d", checkY);
            		if (checkX != 15)
            		{
                		characterpos[0] += 1;
            		}
			else
			{
				characterpos[0] -= 4;
			}
            		break;
		case '\n':
			if (refX == 10) return 0; //this is shelter
			else if (refX == 11) return 1;
			else if (refX == 12) return 2;
			else if (refX == 13) return 3;
			else if (refX == 14) return 4;
        	/*case KEY_LEFT:
           		mvprintw(0, 0, "Left arrow key pressed");
            		checkY = characterpos[0] - (height - map.size()) / 2;
            		checkX = characterpos[1] - 1 - (width - map[0].size()) / 2;
            		//mvprintw(4, 0, "checkX: %d", checkX);
            		//mvprintw(4, 11, "checkY: %d", checkY);
            		if (map[checkY][checkX] != '#')
            		{
                		characterpos[1] -= 1;
            		}
            		break;
        	case KEY_RIGHT:
            		mvprintw(0, 0, "Right arrow key pressed");
            		checkY = characterpos[0] - (height - map.size()) / 2;
            		checkX = characterpos[1] + 1 - (width - map[0].size()) / 2;
            		//mvprintw(4, 0, "checkX: %d", checkX);
            		//mvprintw(4, 11, "checkY: %d", checkY);
            		if (map[checkY][checkX] != '#')
            		{	
                		characterpos[1] += 1;
            		}
            		break;*/
        	case ERR:
            		break;
		}
		mvprintw(characterpos[0], characterpos[1], "->");
	}
	return 0;
}
/*int main()
{
	menu();
	endwin();
	return 0;
}*/
