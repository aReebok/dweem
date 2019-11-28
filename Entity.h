#ifndef _ENTITY_H_
#define _ENTITY_H_


#include<iostream>
#include<string>
#include <stdlib.h>   
#include <time.h>      
#include<iostream>
using namespace std;

//ENTITY CLASS  -------------------------------------------
//=========================================================
class Entity  {
protected: 
	int health, mana, level, damage;
	string type;
public: 
	Entity();
	Entity(int h, int m, int l, int d, string t);
	Entity(const Entity& e);
	~Entity();
// setters + getters 
	string get_type() { return type; }
	int &get_health() { return health; }
	int &get_mana() { return mana; }
	int &get_lvl() { return level; }
//------------battle functions----------------------
	void heal ();
};

//PLAYER CLASS  -------------------------------------------
//=========================================================
class Player : public Entity {
public: 
	Player();
	Player(int h, int m, int l, int d, string t);
	~Player();
//combat methods: 
	void stats();
	void hit(Entity &enemy);
	void miss();
	void pop_potion();
};


//ENEMY CLASS  -------------------------------------------
//=========================================================
class Enemy : public Entity {
public:
	Enemy();
	Enemy(int h, int m, int l, int d, string t);
	Enemy (const Enemy &en);
	~Enemy();
//combat methods: 
	void stats();
	void hit(Player &p);
	void miss();
};
// can create sub enemies ---

//HELPER FUNCTIONS DECLERATIONS ---------------------------
bool die_roll ();
void combined_stats (Player p, Enemy e);
void init_combat(Player p, Enemy e);

#endif //_ENTITY_H_