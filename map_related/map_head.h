#ifndef MAP_HEAD_H
#define MAP_HEAD_H

#include <string>       // For string
#include <vector>       // For std::vector
#include <ncurses.h>
using namespace std;

extern string map1; // Declare the external variable
extern vector<string> hospital; // Declare the external variable
extern vector<int> head_story;
struct story {
    string text;
    vector<string> options;
    vector<story*> next;
    string reward="";
};
struct story_spot{
    story* target_story;
    int x;
    int y;
};

extern vector<story*> hospital_story;
extern vector<story_spot> story_spots;

vector<vector<char> > string_to_vector(vector<string> s); // Declare the function

void clearnear(int x,int y,vector<vector<char> > map, int , int);

void drawmap(vector<vector<char> > map , int , int);

void initialize_stories();

void play_story(story* current_story, int height , int width);

void create_story_spot(int num , int original_x , int original_y, int height , int width  );


#endif