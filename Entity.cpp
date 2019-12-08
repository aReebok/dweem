#include "Entity.h"

//ENTITY CLASS FUNCTIONS ----------------------------------
//=========================================================
//constructors -

Entity :: Entity(): health(10), mana(10), level(1), damage (1), type("entity") { 
	//cout << "creating default entity" << endl; 
}
Entity :: Entity(int h, int m, int l, int d, string t) : health(h), mana(m), level(l), damage(d), type(t) { 
	//cout << "creating entity" << endl; 
}
Entity :: Entity(const Entity& e) : health(e.health), mana(e.mana), level(e.level), damage(e.damage), type(e.type) { 
	//cout << "copying entity" << endl; 
}
Entity :: ~Entity() {
	//cout << "destroying entity" << endl; 
}
void Entity :: heal () {
	health += 1;
}

//==========================================================
// PLAYER CLASS FUNCTIONS ----------------------------------

Player :: Player() : Entity() { 
	//cout << "creating default player" << endl; 
} 
Player :: Player (int h, int m, int l, int d, string t) : Entity(h, m, l, d, t) { 
	//cout << "creating player" << endl; 
}
Player :: ~Player() { 
	//cout << "destroying player" << endl; 
}
//combat methods: 
void Player :: stats() {
	cout << "-- player's stats --" << endl;
	cout << "health: " << health << " || mana: " << mana << endl;
	cout << "current level: " << level << " || damage per auto: " << damage << endl;  
}
void Player :: hit(Entity &enemy) { // player hit the enemy
	cout << "player hit enemy!" << endl; 
	enemy.get_health() -= damage;
	mana -= 1;
}
void Player :: miss() {// player misses the enemy--
	cout << "You missed~!" << endl;
	mana -= 1;
} 
void Player :: pop_potion() {
	health += 1;
}

//==========================================================
// ENEMY CLASS FUNCTIONS ----------------------------------

Enemy :: Enemy() : Entity() { 
	//cout << "creating default Enemy" << endl; 
	} 
Enemy :: Enemy(int h, int m, int l, int d, string t) : Entity(h, m, l, d, t) {
	//cout << "creating Enemy" << endl; 
	}
Enemy :: Enemy (const Enemy &en) : Entity (en) {
		//cout << "copying enemy" << endl; 
	}
Enemy :: ~Enemy() { 
	//cout << "destroying Enemy" << endl; 
}
//combat methods: 
void Enemy :: stats() { 
	cout << "-- Enemy's stats --" << endl;
	cout << "health: " << health << " || mana: " << mana << endl;
	cout << "current level: " << level <<" || damage per auto: " << damage << endl << " -------------------------------------------- \n";  
}
void Enemy :: hit(Player &p) { // enemy hit the player
	cout << "enemy hit player!" << endl;
	p.get_health() -= damage;
	mana -= 1;
}
void Enemy :: miss() { // enemy misses the player--
	cout << "enemy missed you~!" << endl;
	mana -= 1;
} 

bool die_roll () {
	//random 1 or 2: 
	int roll = 0 ;
	roll = rand() % 20 + 1; // generates random number between 1 and 2 --
	cout << "--------******  die roll : " << roll << endl;
	if (roll<=5) {
		return true;
	} else { return false; }
} 
void combined_stats (Player p, Enemy e) {
	cout << "------------------------------------------------------" << endl; 
	cout << "              -----  battle stats  -----              " << endl;
	cout << "------------------------------------------------------" << endl; 
	cout << "     PLAYER                                ENEMY      "<< endl;
	cout << "| health: "<< p.get_health() << " | mana: " << p.get_mana() <<  "  ||||  health: " << e.get_health() << " | mana: " << e.get_mana() << "  |" << endl;
	cout << "------------------------------------------------------" << endl; 
	cout << "------------------------------------------------------" << endl; 
}

void init_combat(Player p, Enemy e) {
	cout << "combat initiated" << endl;
	string user_input;
	while ( (p.get_health() >= 0) && (e.get_health() >= 0) ) {		
		// while one of the either is alive, do this loop
		cout<< "chose to use fight or use health potion: f or h" << endl;
		cin >> user_input; //PLAYER's FUNCTIONS ---------------
		if ((user_input == "f") || (user_input == "h")) {
			cout << "valid input of" ; 
			if (user_input == "f") {
				cout << " fighting enemy" << endl;
				if (die_roll() == true){
					p.hit(e);
					if (e.get_health () == 0 ) { 
						cout << " ***** ***** ENEMY ELIMINATED ***** ***** " << endl;
					} else  { combined_stats (p,e); } 
				} else { p.miss(); }
			} else {
				cout << "wanting to use potion " << endl;
				cout << "wihch one? " << endl;
			}
		} else { cout << "invalid input: not f or h" << endl; }

		//ENEMY ATTACK BACK -------------------------------------
		bool roll = die_roll();
		if (roll == true) {
			cout << "enemy has hit player ---- " << endl;
			e.hit(p);
			if (e.get_health () == 0 ) { 
				cout << " ***** ***** HUMAN ELIMINATED ***** ***** " << endl;
			} else  { combined_stats (p,e); } 
		} else  { e.miss(); }
	}
} 
