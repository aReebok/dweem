#include"../react.h"
#include"Entity2.h"
#include"Entity2.cpp"
#include<vector>

void update_enemy_health(int enemy_health)
{
    int health;
    map <string, float> enemy;
    ifstream e("Enemy.txt");
    e >> health;
    e.get();
    string s;
    while(e >> s)
    {
        int n;
        e >> n;
        enemy.insert({s,n});
    }
    e.close();

    ofstream en("Enemy.txt");
    en << enemy_health << endl;
    for (auto p : enemy)
    {
        en << p.first << ' ' << p.second << endl;
    }
    en.close();

}

void display_enemy_health(int enemy_health_index)
{
    int health;
    ifstream f("Enemy.txt");
    f >> health;
    f.close();

    print_at(enemy_health_index,"  health  " );

    for (int i = 0; i < health; i++)
    {
        print_at(enemy_health_index+10+i,"*" );
    }
}

void display_health(int health_index)
{
    int health;
    ifstream f("Character.txt");
    f >> health;
    f.close();

    print_at(health_index,"  health  " );

    for (int i = 0; i < health; i++)
    {
        print_at(health_index+10+i,"*" );
    }
}

void attack()
{
    ifstream c("Character.txt");
    int char_health;
    c >> char_health;
    c.get();
    int char_strength;
    string s;
    while (c >> s)
    {
        c.get();
        int n;
        c >> n;
        if (s == "strength")
        {
            char_strength = n;
        }
    }
    c.close();

    ifstream e("Enemy.txt");
    int enemy_health;
    e >> enemy_health;
    e.get();
    int enemy_strength;
    string d;
    while (e >> d)
    {

        e.get();
        
        int n;
        e >> n;
        if (d == "strength")
        {
            enemy_strength = n;
        }
    }
    e.close();

    enemy_health -= char_strength/10;

    update_enemy_health(enemy_health);
    cerr << enemy_health;
}

vector <float> chosen_stats = {0,0,0,0,0,0};
int main() {
    init();
    int &x = int_at(1500);

    //indecies for starting Menu
    const int title = 240;
    const int startmain = 5;
    const int human = 20;
    const int elf = 170;
    const int dwarf = 180;
    const int confirm = 30;
    const int cancel = 110;
    const int hbonus1 = 40;
    const int hbonus2 = 60;
    const int hbonus3 = 70;
    const int ebonus1 = 120;
    const int ebonus2 = 130;
    const int ebonus3 = 150;
    const int dbonus1 = 190;
    const int dbonus2 = 210;
    const int dbonus3 = 220;

    // indecies for stats_selection
    const int index0 = 260;
    const int index1 = 280;
    const int index2 = 300;
    const int index3 = 320;
    const int index4 = 340;
    const int index5 = 360;
    const int strengthIndex = 400;
    global_mem[399] = '\0';
    global_mem[402] = '\0';
    const int speedIndex = 800;
    global_mem[799] = '\0';
    global_mem[802] = '\0';
    const int dexterityIndex = 1200;
    global_mem[1199] = '\0';
    global_mem[1202] = '\0';
    const int intelligenceIndex = 1600;
    global_mem[1599] = '\0';
    global_mem[1602] = '\0';
    const int wisdomIndex = 2000;
    global_mem[1999] = '\0';
    global_mem[2002] = '\0';
    const int charismaIndex = 2400;
    global_mem[2399] = '\0';
    global_mem[2402] = '\0';
    const int buttonIndex = 520;

    const int health_index = 410;
    const int mana_index = 450;
    const int exit_index = 490;
    const int menu_index = 810;
    const int text_index = 8000;
    const int settings_index = 890;
    const int help_index = 920;
    const int enemy_health_index = 1100;
    const int enemy_mana_index = 1150;

    const int attack_index = 940;
    const int item_index = 960;
    const int leave_index = 980;
    const int talk_index = 1000;



    //STARTING MENU PRINTING
    print_at(240, "Dweem Conquest");
    print_at(5, "start");
    print_at(20, "human");
    print_at(170, "elf");
    print_at(180, "dwarf");
    print_at(30, "confirm");
    print_at(110, "cancel");
    print_at(40, "strength: +2");
    print_at(60, "speed: +2");
    print_at(70, "dexterity: +2");
    print_at(120, "speed: +3");
    print_at(130, "intelligence: +1");
    print_at(150, "wisdom: +2");
    print_at(190, "strength: +3");
    print_at(210, "speed: +1");
    print_at(220, "dexterity: +2");

    //FIGHT PRINTING
    print_at(attack_index, "attack");
    print_at(item_index, "item");
    print_at(talk_index, "speak");
    print_at(leave_index, "flee");

// HEALTH AND MANA STATS::

    display_health(health_index);
    print_at(mana_index, "  mana  *********");
    print_at(exit_index,"back");
    print_at (menu_index,"menu");
    print_at (text_index, ">");
    print_at(settings_index, "settings");
    print_at(help_index, "help");
    display_enemy_health(enemy_health_index);
    print_at(enemy_mana_index, " mana **********");

    //STATS SELECTION PRINTING
    print_at(index0, "Strength:");
    print_at(index1, "Speed:");
    print_at(index2, "Dexterity:");
    print_at(index3, "Intelligence:");
    print_at(index4, "Wisdom:");
    print_at(index5, "Charisma:");
    print_at(buttonIndex, "Choose Character!");


    vector <float> chosen_stats = {0,0,0,0,0,0};
    if (just_starting()) {x = 0;}

    if (received_event()) {
        if (event_id_is("startgame")) x = 5;
        if (event_id_is("choose_character"))
        {
            x = 1;
            if (global_mem[400] >= 48 && global_mem[400] <= 57 && global_mem[401] >= 48 && global_mem[401] <= 57) chosen_stats[0] = as_integer(400);
            else x = 5;
            if (global_mem[800] >= 48 && global_mem[800] <= 57 && global_mem[801] >= 48 && global_mem[801] <= 57) chosen_stats[1] = as_integer(800);
            else x = 5;
            if (global_mem[1200] >= 48 && global_mem[1200] <= 57 && global_mem[1201] >= 48 && global_mem[1201] <= 57) chosen_stats[2] = as_integer(1200);
            else x = 5;
            if (global_mem[1600] >= 48 && global_mem[1600] <= 57 && global_mem[1601] >= 48 && global_mem[1601] <= 57) chosen_stats[3] = as_integer(1600);
            else x = 5;
            if (global_mem[2000] >= 48 && global_mem[2000] <= 57 && global_mem[2001] >= 48 && global_mem[2001] <= 57) chosen_stats[4] = as_integer(2000);
            else x = 5;
            if (global_mem[2400] >= 48 && global_mem[2400] <= 57 && global_mem[2401] >= 48 && global_mem[2401] <= 57) chosen_stats[5] = as_integer(2400);
            else x = 5;

            int counter = 0;
            for (int i = 0; i < 6; i++)
            {
                if (chosen_stats[i] > 18) x = 5;
            }

            ofstream f("chosen_stats.txt");
            for (auto p : chosen_stats)
            {
                f << p << ' ';
            }
            f.close();
        }
        if (event_id_is("human")) x = 2; // choose human
        if (event_id_is("cancel")) x = 1; // go back to race choice
        if (event_id_is("elf")) x = 3; // choose elf
        if (event_id_is("dwarf")) {x = 4;} // choose dwarf
        if (event_id_is("confirm")) // confirm character race
        {
            if (x == 2)
            {
                ifstream f("chosen_stats.txt");
                int n;
                int i = 0;
                string s;
                while (i < 6)
                {
                    f >> n;
                    chosen_stats[i] = n;
                    i++;
                }
                Human H(chosen_stats[0], chosen_stats[1], chosen_stats[2], chosen_stats[3], chosen_stats[4], chosen_stats[5]);
                H.display_in_file();
            }
            if (x == 3)
            {
                ifstream f("chosen_stats.txt");
                int n;
                int i = 0;
                string s;
                while (i < 6)
                {
                    f >> n;
                    chosen_stats[i] = n;
                    i++;
                }
                Elf E(chosen_stats[0], chosen_stats[1], chosen_stats[2], chosen_stats[3], chosen_stats[4], chosen_stats[5]);
                E.display_in_file();
            }
            if (x == 4)
            {
                ifstream f("chosen_stats.txt");
                int n;
                int i = 0;
                string s;
                while (i < 6)
                {
                    f >> n;
                    chosen_stats[i] = n;
                    i++;
                }
                Dwarf D(chosen_stats[0], chosen_stats[1], chosen_stats[2], chosen_stats[3], chosen_stats[4], chosen_stats[5]);
                D.display_in_file();
            }
            x = 7;
        }
        if (event_id_is("button_attack"))
        {
            attack();
        }
    }

    if (x == 0) {add_yaml("startingmenu.yaml", {{"startmain", startmain}, {"title", title}});}
    if (x == 5) {add_yaml("stats_selection.yaml", {{"index0", index0}, {"index1", index1}, {"index2", index2}, {"index3", index3}, {"index4", index4}, {"index5", index5}, {"button_index", buttonIndex}, {"StrengthInput", strengthIndex}, {"SpeedInput", speedIndex}, {"DexterityInput", dexterityIndex}, {"IntelligenceInput", intelligenceIndex}, {"WisdomInput", wisdomIndex}, {"CharismaInput", charismaIndex}});}
    if (x == 1) {add_yaml("characterselection.yaml", {{"human", human}, {"elf", elf}, {"dwarf", dwarf}});}
    if (x == 2) {add_yaml("characterconfirm.yaml", {{"image", "pngfind.com-shovel-knight-sprite-png-5030555.png"}, {"confirm", confirm}, {"cancel", cancel}, {"bonus1", hbonus1}, {"bonus2", hbonus2}, {"bonus3", hbonus3}});}
    if (x == 3) {add_yaml("characterconfirm.yaml", {{"image", "pngfind.com-elf-png-51586.png"}, {"confirm", confirm}, {"cancel", cancel}, {"bonus1", ebonus1}, {"bonus2", ebonus2}, {"bonus3", ebonus3}});}
    if (x == 4) {add_yaml("characterconfirm.yaml", {{"image", "pngfind.com-dwarf-token-png-4433841.png"}, {"confirm", confirm}, {"cancel", cancel}, {"bonus1", dbonus1}, {"bonus2", dbonus2}, {"bonus3", dbonus3}});}
    if (x == 7) 
    {
        Witch W(4);
        W.display_in_file();
        add_yaml("fight_template.yaml", {{"health", health_index}, {"mana", mana_index}, {"exit", exit_index}, {"menu", menu_index}, {"text", text_index}, {"settings", settings_index}, {"help", help_index}, {"attack", attack_index}, {"item", item_index}, {"talk", talk_index}, {"leave", leave_index}, {"enemy_health", enemy_health_index}, {"enemy_mana", enemy_mana_index}});
    }

    quit();
}

//with event_id, call entity (human/elf/dwarf) constructor
