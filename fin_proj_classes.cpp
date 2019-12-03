#include <iostream>
using namespace std;

class Weapon {
protected:
    int att;  //adds onto strength
    float wt; //adds 
    int stamina_sub;  //how much stamina it take with each attack
    int crit_att;  //multiplier of attack
    float crit_att_perc; //chance of critical attack happening

public:
    Weapon() : att(6), wt(.5), stamina_sub(1), crit_att(2.5), crit_att_perc(12) { }  //dagger
    Weapon() : att(10), wt(2.5), stamina_sub(3), crit_att(1.3), crit_att_perc(7) { } //sword
    Weapon() : att(13), wt(7), stamina_sub(6), crit_att(1.1), crit_att_perc(5) { } //axe
    Weapon() : att(15), wt(10), stamina_sub(10), crit_att(1.05), crit_att_perc(4) { } //hammer
    Weapon() : att(7), wt(.75), stamina_sub(2), crit_att(1), crit_att_perc(0) { } //bow + arrow
};

class MagicWeapon : public Weapon {
    int crit_inc;  //increases critical attack
    int cont_att;  //causes continuous additional damage that lasts for several turns
    int stamina_sub_dec;  //decreases stamina_sub
    int enemy_dmg_dec;  //decreases enemy strength by a small percentage continuously

public:
    MagicWeapon() : crit_inc(0), cont_att(2.5), stamina_sub_dec(3), enemy_dmg_dec(0) { } //poisonous sword 
    MagicWeapon() : crit_inc(1.7), cont_att(0), stamina_sub_dec(3), enemy_dmg_dec(0) { } //assassin dagger
    MagicWeapon() : crit_inc(0), cont_att(2.0), stamina_sub_dec(3), enemy_dmg_dec(2) { } //fire axe
    MagicWeapon() : att(7), wt(.75), stamina_sub(2) { } //bow + arrow
};