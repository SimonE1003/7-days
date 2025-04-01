#include "game_state.h"
#include "init.h"
#include <string>

using namespace std;
int i=0;
void inventory()
{
	while (item_list[i])
	{
		
		if (items_list[i].name=="bullet")
		{
			gs.strength+=items_list[i].code;
		}
		if (items_list[i].name=="medicine")
		{
			gs.health+=items_list[i].code;
		}

		i++;

	}

}



