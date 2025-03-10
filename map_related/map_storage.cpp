#include <bits/stdc++.h>
#include "map_head.h"
using namespace std;


string map1 =    
    "####################################################################################################\n"
    "#                                                                                                  #\n"
    "#                                                                                                  #\n"
    "#                                                                                                  #";
vector<vector<char>> string_to_vector(string s){
    vector<vector<char>> v;
    v.push_back(vector<char>());
    
    for(int i=0;i<s.size();i++){
        if (s[i]=='\n'){
            v.push_back(vector<char>());
        }else{
            v.back().push_back(s[i]);
        }
    }
    return v;
}