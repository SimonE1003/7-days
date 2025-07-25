#include <vector>  // For vector
#include <string>  // For string
#include "../include/map_head.h"
using namespace std;

//make sure the map is rectangular
string map1 =    
    "####################################################################################################\n"
    "#                                                                                                  #\n"
    "#                                                                                                  #\n"
    "#                                                                                                  #";
vector<string> hospital = {
		"Hospital                                             ",
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
        "#                                            Door   #",
        "#####################################################"};
vector<string> shelter = {
	"Shelter                                             ",
	"####################################################",
	"# #############                                    #",
	"# #           #                                    #",
	"# #  S    E   #                                    #",
	"#                                                  #",
	"#          #####################                   #",
	"#                                                  #",
	"#                                                  #",
	"#                                                  #",
	"#      ######          ###                         #",
	"#                      # #                         #",
	"#          ######      # #                         #",
	"#                      ###                         #",
	"#                                                  #",
	"#                                                  #",
	"#                                                  #",
	"#                                                  #",
	"#                                             Door #",
	"####################################################",
	"Press I to Check Status                             ",
	"Save at S              			                 ",
	"Exit at E                                           "};

vector<string> weaponshop{
	"Weapon Shop                                         ",
	"####################################################",
	"#                                      #############",
	"#                                      #############",
	"#############                          #############",
	"#                                      #############",
	"#                                      #############",
	"#############                          #############",
	"#                                                  #",
	"#                                                  #",
	"#############                                      #",
	"#                                                  #",
	"#                                                  #",
	"#############                                      #",
	"#                                                  #",
	"#                                                  #",
	"#############                                      #",
	"#                                                  #",
	"#                                             Door #",
	"####################################################"};

vector<string> supermarket{
	"Supermarket                                         ",
	"####################################################",
	"#                                                  #",
	"#                                                  #",
	"#    ##########################                    #",
	"#                                                  #",
	"#                                                  #",
	"#                                                  #",
	"#    ##########################                    #",
	"#                                                  #",
	"#                                                  #",
	"#                                                  #",
	"#    ##########################                    #",
	"#                                                  #",
	"#                                                  #",
	"#                                                  #",
	"#               ###        ###                     #",
	"#               ##############                     #",
	"#               ##############                Door #",
	"####################################################"};

vector<string> gameName = {
	R"( _______ _______ ___ ___ _______ _______      _____  _______ ___ ___ _______ )", 
	R"(|     __|    ___|   |   |    ___|    |  |    |     \|   _   |   |   |     __|)",
	R"(|__     |    ___|   |   |    ___|       |    |  --  |       |\     /|__     |)",
	R"(|_______|_______|\_____/|_______|__|____|    |_____/|___|___| |___| |_______|)"
};

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
