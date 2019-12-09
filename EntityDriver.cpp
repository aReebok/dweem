#include "Entity.h"
#include "Entity.cpp"

int main () {
	srand(time(NULL));
	Player p(10,10,1,2,"player",5);
	p.add_item(Enchantment(1,5));
	p.HUD();
	// Enemy e;
	// combined_stats(p,e);
	// init_combat(p,e);
	// cout << "-----------" <<endl;
}