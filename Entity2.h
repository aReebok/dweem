#ifndef _ENTITY2_H_
#define _ENTITY2_H_

#include<iostream>
using namespace std;
#include<vector>

class Entity{
    int level;
    int xp;
    int health;
    int stamina;
    float strength;
    float speed;
    float dexterity;
    float intelligence;
    float wisdom;
    float charisma;
public:
    Entity() : level(1), xp(0), health(10), stamina(10), speed(5), strength(2), dexterity(0), intelligence(5), wisdom(5), charisma(2){}

    Entity(float str, float dex, float intel, float wis, float ch, float sp) : level(1), xp(0), health(10), stamina(10), speed(sp), strength(str), dexterity(dex), intelligence(intel), wisdom(wis), charisma(ch){}

    void set_strength(int s);
};

class Human : public Entity{
    string race = "Human";
    vector <float> stats;
    vector <float> special_stats = {2,1,1,1,0,1}; //{Strength, Speed, Dexterity, Intelligence, Wisdom, Charisma}
    
public:
    Human() {}

    Human(float str, float dex, float intel, float wis, float ch, float sp){
        stats = {str, dex, intel, wis, ch, sp};
    }

    void create_human(float str, float dex, float intel, float wis, float ch, float sp);


    // Use map weapon map<string, float, float> weapon
    // weapon["Sword0"] = 3, 0
    // weapon["Axe0"] = 4, 1
    // weapon["Hammer"] = 5, 2
};

// class Dwarf : public Entity{
//     string race = "Dwarf";
// public:
//     Dwarf() : Entity() {};

//     Dwarf(float str, float dex, float con, float intel, float wis, float ch, float sp){
//         Entity(str, dex, intel, wis, ch, sp);
//     }
// };

// class Elf : public Entity{
//     string race = "Elf";
// public:
//     Elf() : Entity() {};

//     Elf(float str, float dex, float con, float intel, float wis, float ch, float sp){
//         Entity(str, dex, intel, wis, ch, sp);
//     }
// };

// class Ogre : public Entity{
//     string race = "Ogre";
// public:

//     Ogre() 

//     Ogre(int lvl) {
        
//     }
// };

#endif //_ENTITY_H_