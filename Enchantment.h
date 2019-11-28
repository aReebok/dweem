#ifndef _ENCHANTMENTS_H_
#define _ENCHANTMENTS_H_
#include<iostream>
#include<string>
using namespace std;

class Enchantment {
    protected:
    int type; 
    /* type 1 is health, type 2 is mana.
    3 is armor buff, 4 is attack buff , 
    when no type entered, then creates type 1*/
    int magnitude; // the magnitude of enchantment
    int acquired; // when aquired, == 1, when enchantment not aquired, 0.
    int state; //used = 0, unused = 1. Upon initialization, 
public: 
    static int DEFAULT_MAGNITUDE; 
    Enchantment (): type(1), magnitude(DEFAULT_MAGNITUDE), acquired(0), state(1) {} 
    // default creates a health potion w given def. mag. and unacqured and unused potion. 
    Enchantment (int t); 
    Enchantment (int t, int mag);
    //~Enchantment () {}
    //methods -------------------------
    int get_type();
    int get_magnitude();
    int get_state();

    void set_state(const int i);
    void set_magnitude(const int mag);

    void use_item();
    void remove_item();

    //helper methods -------------------
    void check_inbound (const int ubound, const int lbound, const int in, int &var); 
    //takes 2 upper and lower bound and makes sure that given int in is in between the two - -
    string get_name(); //gets the string form of name.

};
#endif  // _ENCHANTMENTS_H_
