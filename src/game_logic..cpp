#include "../include/game_logic.h"
#include "../include/game_state.h"

bool checkgs(){
	int x=5,y=10;
	if (gs.food<0)
	{
		gs.hunger+=gs.food;
		mvprintw(x,y,"Your hunger level decreased due to insufficient food.");
	}
	if (gs.water<0)
	{
		gs.thist+=gs.water;
		x+=1;
		mvprintw(x,y,"Your thirst level decreased due to insufficient water.");
	}
	if(gs.sanity<0)
	{
		gs.health+=gs.sanity;
		x+=1;
		mvprintw(x,y,"Your health level decreased due to insufficient sanity.");
	}
	if (gs.hunger<0)
	{
		gs.health+=gs.hunger;
		x+=1;
		mvprintw(x,y,"Your health level decreased due to insufficient hunger.");
	}
	if (gs.thirst<0)
	{
		gs.health+=gs.thirst;
		x+=1;
		mvprintw(x,y,"Your health level decreased due to insufficient thirst.");
	}
	if (ill)
	{
		gs.health-=1;
		x+=1;
		mvprintw(x,y,"Your health level decreased due to illness.");
	}

	usleep(4000000);
	refresh();
	usleep(1000000);
	display_status(gs);
	if (gs.health<=0)
	{
		mvprintw(16,10,"You lose!!!");
		usleep(100000);
		retutn false;
	}
	return true;


}
void start_a_day() { /* Implementation */ }
void sixty_sec() { /* Implementation */ }
void end_a_day()
{
	if (gs.food>=1)
	{
		gs.food-=1;
	}
	else if (gs.food<1 && gs.hunger>0)
	{
		gs.hunger-=1;
	}
	else if (gs.food<1 && gs.hunger<1)
	{
		gs.health-=1;
	}
	if (gs.water>=1)
	{
		gs.water-=1;
	}
	else if (gs.water<1 && gs.thirst>0)
	{
		gs.thirst-=1;
	}
	else if (gs.water<1 && gs.thirst<1)
	{
		gs.health-=1;
	}
	if (gs.sanity>0)
	{
		gs.sanity-=1;
	}
	else
	{
		gs.health-=1;
	}	
}
void end() { /* Implementation */ }
