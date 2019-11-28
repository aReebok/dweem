#include "Enchantment.h"

Enchantment :: Enchantment (int t): magnitude(DEFAULT_MAGNITUDE), acquired (0), state (1){
    check_inbound (1,4,t,type); //checks that t is in bound then sets type = t
}
Enchantment :: Enchantment (int t, int mag): magnitude(mag){
    check_inbound (1,4,t,type); 
}
//Enchantment :: ~Enchantment () {}
//methods --------------------------
int Enchantment ::  get_type() { return type; } 
int Enchantment :: get_magnitude(){ return magnitude; }
int Enchantment :: get_state(){ return state; }

void Enchantment :: set_state(const int i){ state = i; }
void Enchantment :: set_magnitude(const int mag){ magnitude = mag; }

//helper methods -------------------

void Enchantment :: check_inbound (const int lbound, const int ubound, const int in, int &var) {
    if ( (in > ubound) || (in < lbound) ) //ensure that type is in bound
        cout << "warning: enchantment type is not in bounds" << endl;
    if (in > ubound) { var = ubound; }
    else if (in < 1) { var = lbound; }
    else { var = in; } 
}  
string Enchantment :: get_name(){
    if (type == 1) { return "health potion"; }
    else if (type == 2) { return "mana potion"; }
    else if (type == 3) { return "armor_buff"; }
    else { return "attack_buff";} 
}
