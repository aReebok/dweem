#include"../react.h"
#include"Entity2.h"

int main() {
    init();
    int &x = int_at(1500);

    const int startmain = 5;
    print_at(5, "start");

    const int human = 20;
    print_at(20, "human");
    const int elf = 170;
    print_at(170, "elf");
    const int dwarf = 180;
    print_at(180, "dwarf");

    const int confirm = 30;
    print_at(30, "confirm");
    const int cancel = 110;
    print_at(110, "cancel");

    const int hbonus1 = 40;
    print_at(40, "strength: +1");
    const int hbonus2 = 60;
    print_at(60, "speed: +2");
    const int hbonus3 = 70;
    print_at(70, "dexterity: +2");
    const int hbonus4 = 90;
    print_at(90, "wisdom: +1");

    const int ebonus1 = 120;
    print_at(120, "speed: +3");
    const int ebonus2 = 130;
    print_at(130, "intelligence: +1");
    const int ebonus3 = 150;
    print_at(150, "wisdom: +2");

    const int dbonus1 = 190;
    print_at(190, "strength: +3");
    const int dbonus2 = 210;
    print_at(210, "speed: +1");
    const int dbonus3 = 220;
    print_at(220, "dexterity: +2");


    if (just_starting()) {x = 0;}
    if (received_event()) {
        if (event_id_is("startgame")) x = 1;
        if (event_id_is("human")) x = 2;

        if (event_id_is("cancel")) x = 1;
        if (event_id_is("elf")) x = 3;
        if (event_id_is("dwarf")) {x = 4;}
        if (event_id_is("confirm"))
        {
            if (x == 2)
            {
                Human H;
            }
            if (x==3)
            {

            }
        }; //goes to Nick's YAML file //creats entity object 
    }

    if (x == 0) {add_yaml("startingmenu.yaml", {{"startmain", startmain}});}
    if (x == 1) {add_yaml("characterselection.yaml", {{"human", human}, {"elf", elf}, {"dwarf", dwarf}});}
    if (x == 2) {add_yaml("humanconfirm.yaml", {{"confirm", confirm}, {"cancel", cancel}, {"hbonus1", hbonus1}, {"hbonus2", hbonus2}, {"hbonus3", hbonus3}, {"hbonus4", hbonus4}});}
    if (x == 3) {add_yaml("elfconfirm.yaml", {{"confirm", confirm}, {"cancel", cancel}, {"ebonus1", ebonus1}, {"ebonus2", ebonus2}, {"ebonus3", ebonus3}});}
    if (x == 4) {add_yaml("dwarfconfirm.yaml", {{"confirm", confirm}, {"cancel", cancel}, {"dbonus1", dbonus1}, {"dbonus2", dbonus2}, {"dbonus3", dbonus3}});}
    


    //if (x == 6) {add_yaml(NICK'S YAMl FILE);}
    quit();
}

//with event_id, call entity (human/elf/dwarf) constructor