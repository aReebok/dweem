#include<iostream>
#include<vector>
#include<string>
using namespace std;
#include "Enchantment.h"

class Human{
    int health, mana;
    int level;
    int attack, armor;
    vector <Enchantment> item; 
public:
    Human(int h, int m){
        health = h;
        mana = m;
        level = 0;
        attack = level*10+10;
        armor = 0;
        
        Enchantment health1 (1, 10);
        item.push_back(health1);
    }

    void display_stats() {
        cout<<"health: "<< health << endl;
        cout<<"mana: "<< mana << endl;
        cout<<"number of items: "<< item.size() << endl;
        for (int i = 0; i < item.size(); i++) {
            cout << i+1 <<". you have a " << item[i].get_name() << " with magnitude: " << item[i].get_magnitude() << endl;
        }
    }
    void decrease_var( int &var ){
        // decrease health or mana by 10 
        if (var < 10) { cout<<"player's death"<<endl; }
        else { var -= 10; }
    } 
    void add_item( Enchantment e ) { item.push_back(e);}
    int &get_health() { return health; }
    int &get_mana() { return mana; } 
    
    void use_item(int i) {
        i -= 1;
        if (i < 0 || i > item.size()) { cout << "out of bound index" << endl;}
        if (i < 0) { i = 0; }
        else if (i>item.size()-1){ i = item.size()-1; }

        if (item[i].get_type() == 1) {
            health += item[i].get_magnitude();
        } else if (item[i].get_type() == 2) {
            mana += item[i].get_magnitude();
        } else if (item[i].get_type() == 3) {
            attack += item[i].get_magnitude();
        } else {
            armor += item[i].get_magnitude();
        }
        cout << item[i].get_name() << " used!" << endl;
        item.erase(item.begin()+i);
        display_stats();
    }
};

int Enchantment::DEFAULT_MAGNITUDE = 5;
int main () {
    Human h(50,50);
    h.add_item(Enchantment(2,20));//mana
    h.add_item(Enchantment(0,200));//checking out of lbound: health
    h.add_item(Enchantment(6,10));//checking out of ubound: attack buff
    h.display_stats(); // displays
    h.decrease_var(h.get_health());//decrease health by 10
    h.decrease_var(h.get_mana());//decrease mana by 10
    cout << "----------------------------------------" << endl; 
    h.display_stats();
    cout << "----------------------------------------" << endl; 
    h.use_item(1);
    h.use_item(4);
    h.use_item(0);
    h.use_item(4);
    } 