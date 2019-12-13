#include "Entity.h"
#include "Enchantment.h"

//ENTITY CLASS FUNCTIONS ----------------------------------
//=========================================================
//constructors -

Entity :: Entity(): health(10), mana(10), level(1), damage (1), type("entity"), armor(0){
	// Enchantment health1 (1, 2);
    // item.push_back(health1); 
	//cout << "creating default entity" << endl; 
}
Entity :: Entity(int h, int m, int l, int d, string t, int a) : health(h), mana(m), level(l), damage(d), type(t), armor(a) { 
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

void Entity :: HUD() {
	cout<<"health: "<< health << endl;
	cout<<"mana: "<< mana << endl;
	cout<<"number of items: "<< item.size() << endl;
	for (int i = 0; i < item.size(); i++) {
		cout << i+1 <<". you have a " << item[i].get_name() << " with magnitude: " << item[i].get_magnitude() << endl;
	}
}
void Entity :: decrease_var( int &var ){
	// decrease health or mana by 10 
	if (var < 10) { cout<<"player's death"<<endl; }
	else { var -= 10; }
} 
// void Entity :: add_item( Enchantment e ) { item.push_back(e);}
// int& Entity :: get_health() { return health; }
// int& Entity :: get_mana() { return mana; } 

void Entity :: use_item(int i) {
	i -= 1;
	if (i < 0 || i > item.size()) { cout << "out of bound index" << endl;}
	if (i < 0) { i = 0; }
	else if (i>item.size()-1){ i = item.size()-1; }

	if (item[i].get_type() == 1) {
		health += item[i].get_magnitude();
	} else if (item[i].get_type() == 2) {
		mana += item[i].get_magnitude();
	} else if (item[i].get_type() == 3) {
		damage += item[i].get_magnitude();
	} else {
		armor += item[i].get_magnitude();
	}
	cout << item[i].get_name() << " used!" << endl;
	item.erase(item.begin()+i);
	HUD();
}

//==========================================================
// PLAYER CLASS FUNCTIONS ----------------------------------

Player :: Player() : Entity() { 
	//cout << "creating default player" << endl; 
} 
Player :: Player (int h, int m, int l, int d, string t, int a) : Entity(h, m, l, d, t, a) { 
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
Enemy :: Enemy(int h, int m, int l, int d, string t, int a) : Entity(h, m, l, d, t, a) {
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

//need to check if enemy died 
// or if player died -- 
bool is_alive(Entity e) {
	if (e.get_health() != 0) return true;
	else {
		return false;
		if (e.get_type()!="player") {}
	}
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
