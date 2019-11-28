#include "Entity.h"

int main () {
	srand(time(NULL));
	Player p;
	Enemy e;
	combined_stats(p,e);
	init_combat(p,e);
	cout << "-----------" <<endl;
}