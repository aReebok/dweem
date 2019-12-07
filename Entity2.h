#ifndef _ENTITY2_H_
#define _ENTITY2_H_

#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<string>
#include<fstream>

class Entity{
public:
    int health;
    float strength;
    float speed;
    float dexterity;
    float intelligence;
    float wisdom;
    float charisma;
    map <string, float> stats;
    Entity() : health(10), speed(5), strength(2), dexterity(0), intelligence(5), wisdom(5), charisma(2){}

    Entity(float str, float sp, float dex, float intel, float wis, float ch)
    {
        stats = {{"strength", str}, {"speed", sp}, {"dexterity", dex}, {"intelligence", intel}, {"wisdom", wis}, {"charisma", ch}};
    }

    void attack();
};

class Human : protected Entity{
    string race = "Human";
    map <string, float> special_stats = {{"strength", 2}, {"speed", 1}, {"dexterity", 1}, {"intelligence", 1}, {"wisdom", 0}, {"charisma", 1}}; //{Strength, Speed, Dexterity, Intelligence, Wisdom, Charisma}
    
public:
    Human() {}

    Human(float str, float sp, float dex, float intel, float wis, float ch) : Entity(str, sp, dex, intel, wis, ch)
    {
        stats["strength"] += special_stats["strength"];
        stats["speed"] += special_stats["speed"];
        stats["dexterity"] += special_stats["dexterity"];
        stats["intelligence"] += special_stats["intelligence"];
        stats["wisdom"] += special_stats["wisdom"];
        stats["charisma"] += special_stats["charisma"];
    }

    void display_in_file();

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