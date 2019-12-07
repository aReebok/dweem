#include"../react.h"
<<<<<<< HEAD
//#include"Entity2.h"
=======
#include"Entity2.h"
>>>>>>> 2d44fdc6ebef508e07ec13eb21c8b55320a0ad22

int main() {
    init();
    int &x = int_at(1500);

    const int title = 240;
    print_at(240, "Dweem Conquest");
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
    print_at(40, "strength: +2");
    const int hbonus2 = 60;
    print_at(60, "speed: +2");
    const int hbonus3 = 70;
    print_at(70, "dexterity: +2");

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
        }; //goes to Nick's YAML file //creats entity object */
    }

    if (x == 0) {add_yaml("startingmenu.yaml", {{"startmain", startmain}, {"title", title}});}
    if (x == 1) {add_yaml("characterselection.yaml", {{"human", human}, {"elf", elf}, {"dwarf", dwarf}});}
    if (x == 2) {add_yaml("characterconfirm.yaml", {{"image", "pngfind.com-shovel-knight-sprite-png-5030555.png"}, {"confirm", confirm}, {"cancel", cancel}, {"bonus1", hbonus1}, {"bonus2", hbonus2}, {"bonus3", hbonus3}});}
    if (x == 3) {add_yaml("characterconfirm.yaml", {{"image", "pngfind.com-elf-png-51586.png"}, {"confirm", confirm}, {"cancel", cancel}, {"bonus1", ebonus1}, {"bonus2", ebonus2}, {"bonus3", ebonus3}});}
    if (x == 4) {add_yaml("characterconfirm.yaml", {{"image", "pngfind.com-dwarf-token-png-4433841.png"}, {"confirm", confirm}, {"cancel", cancel}, {"bonus1", dbonus1}, {"bonus2", dbonus2}, {"bonus3", dbonus3}});}
    


    //if (x == 6) {add_yaml(NICK'S YAMl FILE);}
    quit();
}

//with event_id, call entity (human/elf/dwarf) constructor
