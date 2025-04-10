#include <ncurses.h> // For ncurses functions
#include <vector>    // For ector
#include <string>    // For string
#include <cstdio>    // For printf-style formatting in mvprintw
#include "../include/map_head.h"
#include <iostream>
#include <set>
#include "../include/game_state.h"
#include "../include/save_load.h"
using namespace std;

void cleanwholescreen(int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            mvprintw(i, j, " ");
        }
    }
}
void clearnear(int x, int y, vector<vector<char>> map, int height, int width)
{
    int map_height = map.size();
    int map_width = map[0].size();
    int newX = x - (height - map_height) / 2;
    int newY = y - (width - map_width) / 2;
    if (newX >= 0 && newX < map.size() && newY >= 0 && newY < map[0].size())
    {
        mvprintw(x, y, "%c", map[newX][newY]);
    }
    else
    {
        cout << "out of bound\n";
        ;
    }
    for (auto k : story_spots)
    {
        if (x == k.x && y == k.y)
        {
            mvprintw(k.x, k.y, "S");
        }
    }
}
void drawmap(vector<vector<char>> map, int height, int width)
{
    int map_height = map.size();
    int map_width = map[0].size();
    // mvprintw(6,0,"len of story_spots: %zu",story_spots.size());

    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            mvprintw(i + (height - map_height) / 2, j + (width - map_width) / 2, "%c", map[i][j]);
            for (auto k : story_spots)
            {

                if (i + (height - map_height) / 2 == k.x && j + (width - map_width) / 2 == k.y)
                {
                    mvprintw(k.x, k.y, "S");
                }
            }
        }
    }
}
void run_shelter()
{
    string current_map;
    vector<vector<char>> map;
    /*cout << "choose a map\n0 : hospital\n1 : shelter\n2 : weaponshop\n3 : supermarket\n";
    string input;
    cin >> input;*/
    map = string_to_vector(shelter);
    current_map = "shelter";
    /*
    if (input == "0")
    {
        map = string_to_vector(hospital);
        current_map = "hospital";
    }
    else if (input == "1")
    {
        map = string_to_vector(shelter);
        current_map = "shelter";
    }
    else if (input == "2")
    {
        map = string_to_vector(weaponshop);
        current_map = "weaponshop";
    }
    else if (input == "3")
    {
        map = string_to_vector(supermarket);
        current_map = "supermarket";
    }
    else
    {
        cout << "invalid input\n";
        return;
    }*/
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);  // Enable function keys and arrow keys
    nodelay(stdscr, TRUE); // Make getch() non-blocking
    // Get the size of the window
    int height, width;
    getmaxyx(stdscr, height, width);
    

    int ch;
    int charactorpos[2] = {height / 2, width / 2};
    mvprintw(charactorpos[0], charactorpos[1], "X");
    // create_story_spot(2, (height - map.size()) / 2, (width - map[0].size()) / 2, map.size(), map[0].size(), map, current_map);
    drawmap(map, height, width);

    // mvprintw(3, 0, "map size: %zu %zu", map.size(), map[0].size());
    while ((ch = getch()) != 'q')
    { // Press 'q' to exit the loop
        // mvprintw(5,0,"story_spots size: %zu",story_spots.size());
        clearnear(charactorpos[0], charactorpos[1], map, height, width);
        int checkX, checkY;
        // check if standing on story
        vector<story_spot>::iterator it = story_spots.begin();
        for (; it != story_spots.end(); it++)
        {
            story_spot k = *it;
            if (charactorpos[0] == k.x && charactorpos[1] == k.y)
            {
                mvprintw((height + map.size()) / 2, (width + map[0].size()) / 2 + 1, "Press A to play story");
                // refresh();
                if (ch == 'a' || ch == 'A')
                {
                    play_story(k.target_story, height, width);
                    story_spots.erase(it);
                    drawmap(map, height, width);
                }
                break;
            }
            else
            {
                mvprintw((height + map.size()) / 2, (width + map[0].size()) / 2 + 1, "                          ");
            }
        }

        if (current_map == "shelter")
        {
            set<char> valid = {'D', 'o', 'r'};
            char current_char = map[charactorpos[0] - (height - map.size()) / 2][charactorpos[1] - (width - map[0].size()) / 2];
            mvprintw(4, 0, "current_char: %c", current_char);
            if (valid.find(current_char) != valid.end())
            {
                if ((int)(gs.day / 0.5) % 2 == 0)
                {
                    mvprintw(map.size() / 2 + height / 2 - 1, map[0].size() / 2 + width / 2 + 1, "Press Enter to start daytime");
                    if (ch == '\n')
                    {
                        int choice;
                        cleanwholescreen(height, width);
                        choice = menu();
                        charactorpos[0] = height / 2;
                        charactorpos[1] = width / 2;
                        cleanwholescreen(height, width);
                        switch (choice)
                        {
                        case 0:
                            map = string_to_vector(shelter);
                            current_map = "shelter";

                            break;
                        case 1:
                            map = string_to_vector(supermarket);
                            current_map = "supermarket";
                            break;
                        case 2:
                            map = string_to_vector(hospital);
                            current_map = "hospital";
                            break;
                        case 3:
                            map = string_to_vector(weaponshop);
                            current_map = "weaponshop";
                            break;
                        }
                        create_story_spot(2, (height - map.size()) / 2, (width - map[0].size()) / 2, map.size(), map[0].size(), map, current_map);
                        drawmap(map, height, width);
                        refresh();
                    }
                }
                else
                {
                    mvprintw(map.size() / 2 + height / 2 - 1, map[0].size() / 2 + width / 2 + 1, "You cannot go out at night");
                }
            } /*
             else if (current_char == 'M')
             {
                 mvprintw(map.size() / 2 + height / 2 - 1, map[0].size() / 2 + width / 2 + 1, "Press A to check status");
                 if (ch == 'a' || ch == 'A')
                 {
                     cleanwholescreen(height, width);
                     display_status(gs);
                     cleanwholescreen(height, width);
                     drawmap(map, height, width);
                     refresh();
                 }
             }
             else
             {
                 mvprintw(map.size() / 2 + height / 2 - 1, map[0].size() / 2 + width / 2 + 1, "                             ");
             }*/
            else if (current_char == 'S')
            {
                mvprintw(map.size() / 2 + height / 2 - 1, map[0].size() / 2 + width / 2 + 1, "Press A to save game       ");
                if (ch == 'a' || ch == 'A')
                {
                    cleanwholescreen(height, width);
                    save();
                    cleanwholescreen(height, width);
                    drawmap(map, height, width);
                    refresh();
                }
            }

            else if (current_char == 'E')
            {
                mvprintw(map.size() / 2 + height / 2 - 1, map[0].size() / 2 + width / 2 + 1, "Press A to quit game       ");
                if (ch == 'a' || ch == 'A')
                {
                    cleanwholescreen(height, width);
                    //save_game(gs);
                    gs.day = 100;
                    return;
                    cleanwholescreen(height, width);
                    drawmap(map, height, width);
                    refresh();
                }
            }
            else if ((int)(gs.day/0.5)%2==1){
                mvprintw(map.size() / 2 + height / 2 - 1, map[0].size() / 2 + width / 2 + 1, "Press P to start night time");
            }
            else
            {
                mvprintw(map.size() / 2 + height / 2 - 1, map[0].size() / 2 + width / 2 + 1, "                                    ");
            }
        }
        if (current_map == "weaponshop" or current_map == "hospital" or current_map == "supermarket")
        {
            set<char> valid = {'D', 'o', 'r'};
            if (valid.find(map[charactorpos[0] - (height - map.size()) / 2][charactorpos[1] - (width - map[0].size()) / 2]) != valid.end())
            {
                mvprintw(map.size() / 2 + height / 2 - 1, map[0].size() / 2 + width / 2 + 1, "Press Enter to leave %s", current_map.c_str());
                if (ch == '\n')
                {
                    play_story(UI_stories[0], height, width);
                    map = string_to_vector(shelter);
                    current_map = "shelter";
                    gs.day += 0.5;
                    charactorpos[0] = height / 2;
                    charactorpos[1] = width / 2;
                    story_spots.clear();
                    drawmap(map, height, width);
                    refresh();
                /*int choice;
                    story_spots.clear();
                    cleanwholescreen(height, width);
                    choice = menu();
                    charactorpos[0] = height / 2;
                    charactorpos[1] = width / 2;
                    cleanwholescreen(height, width);
                    switch (choice)
                    {
                    case 0:
                        map = string_to_vector(shelter);
                        current_map = "shelter";
                        gs.day += 0.5;
                        break;
                    case 1:
                        map = string_to_vector(supermarket);
                        current_map = "supermarket";
                        break;
                    case 2:
                        map = string_to_vector(hospital);
                        current_map = "hospital";
                        break;
                    case 3:
                        map = string_to_vector(weaponshop);
                        current_map = "weaponshop";
                        break;
                    }
                    drawmap(map, height, width);
                    refresh();*/
                }
            }
            else
            {
                mvprintw(map.size() / 2 + height / 2 - 1, map[0].size() / 2 + width / 2 + 1, "                                    ");
            }
        }
        switch (ch)
        {
        case KEY_UP:
            mvprintw(0, 0, "Up arrow key pressed");
            checkY = charactorpos[0] - 1 - (height - map.size()) / 2;
            checkX = charactorpos[1] - (width - map[0].size()) / 2;
            // mvprintw(4, 0, "checkX: %d", checkX);
            // mvprintw(4, 11, "checkY: %d", checkY);
            if (map[checkY][checkX] != '#')
            {
                charactorpos[0] -= 1;
            }
            break;
        case KEY_DOWN:
            mvprintw(0, 0, "Down arrow key pressed");
            checkY = charactorpos[0] + 1 - (height - map.size()) / 2;
            checkX = charactorpos[1] - (width - map[0].size()) / 2;
            // mvprintw(4, 0, "checkX: %d", checkX);
            // mvprintw(4, 11, "checkY: %d", checkY);
            if (map[checkY][checkX] != '#')
            {
                charactorpos[0] += 1;
            }
            break;
        case KEY_LEFT:
            mvprintw(0, 0, "Left arrow key pressed");
            checkY = charactorpos[0] - (height - map.size()) / 2;
            checkX = charactorpos[1] - 1 - (width - map[0].size()) / 2;
            // mvprintw(4, 0, "checkX: %d", checkX);
            // mvprintw(4, 11, "checkY: %d", checkY);
            if (map[checkY][checkX] != '#')
            {
                charactorpos[1] -= 1;
            }
            break;
        case KEY_RIGHT:
            mvprintw(0, 0, "Right arrow key pressed");
            checkY = charactorpos[0] - (height - map.size()) / 2;
            checkX = charactorpos[1] + 1 - (width - map[0].size()) / 2;
            // mvprintw(4, 0, "checkX: %d", checkX);
            // mvprintw(4, 11, "checkY: %d", checkY);
            if (map[checkY][checkX] != '#')
            {
                charactorpos[1] += 1;
            }
            break;
        case ERR:
            break;
        case 'p': // just for testing the story
            play_story(temperature_drop[0], height, width);
            drawmap(map, height, width);
            return;
            break;
        case 'k': // reset the current map just for testing
            create_story_spot(2, (height - map.size()) / 2, (width - map[0].size()) / 2, map.size(), map[0].size(), map, current_map);

            drawmap(map, height, width);
            refresh();
        case 'i':
            cleanwholescreen(height, width);
            display_status(gs);
            cleanwholescreen(height, width);
            drawmap(map, height, width);
            refresh();
        default:
            mvprintw(0, 0, "Key pressed: %c       ", ch);
            break;
        }

        mvprintw(charactorpos[0], charactorpos[1], "X");
        mvprintw(1, 0, "Position: %d, %d      ", charactorpos[0], charactorpos[1]);
        mvprintw(2, 0, "Window size: %d, %d", height, width);

        refresh();
    }

    // End ncurses mode
    endwin();

    return;
}

// cd /mnt/c/Users/User/OneDrive/1340/Project-Repo
