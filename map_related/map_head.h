#ifndef MAP_HEAD_H
#define MAP_HEAD_H

#include <bits/stdc++.h>
#include <ncurses.h>
using namespace std;

extern string map1; // Declare the external variable

vector<vector<char>> string_to_vector(string s); // Declare the function

void clearnear(int x,int y,vector<vector<char>> map);

void drawmap(vector<vector<char>> map);



#endif