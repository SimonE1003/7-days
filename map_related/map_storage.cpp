#include <bits/stdc++.h>
#include "map_head.h"
using namespace std;


string map1 =    
    "####################################################################################################\n"
    "#                                                                                                  #\n"
    "#                                                                                                  #\n"
    "#                                                                                                  #";
vector<string> hospital = {
		"#####################################################",
		"#                                                   #",
		"#############                          ##############",
		"#           #                          #            #",
		"#           #                          #            #",
		"#           #                          #            #",
		"#           #                          ##########   #",
		"########    #                                       #",
		"#           #                                       #",
		"#           #                                       #",
		"#           #                                       #",
		"#           #                                       #",
		"########    #                                       #",
		"#           #                                       #",
		"#           #                                       #",
		"#           #                                       #",
		"#           #                                       #",
		"########    #                                       #",
        "#                                                   #",
        "#####################################################"};
vector<vector<char> > string_to_vector(vector<string> s){
    vector<vector<char> > v;
    //v.push_back(vector<char>());
    
    for(int i=0;i<s.size();i++){
            v.push_back(vector<char>());
        for (int j=0;j<s[i].size();j++){
            v.back().push_back(s[i][j]);
            
        }
    }
    return v;
}
