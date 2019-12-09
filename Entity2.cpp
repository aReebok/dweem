#include"Entity2.h"


void Human :: display_in_file()
{
    ofstream f("Character.txt");
    f << health << endl;
    for (auto p : stats)
    {
        f << p.first << ' ' << p.second << endl;
    }
    f.close();
}

void Dwarf :: display_in_file()
{
    ofstream f("Character.txt");
    f << health << endl;
    for (auto p : stats)
    {
        f << p.first << ' ' << p.second << endl;
    }
    f.close();
}


void Elf :: display_in_file()
{
    ofstream f("Character.txt");
    f << health << endl;
    for (auto p : stats)
    {
        f << p.first << ' ' << p.second << endl;
    }
    f.close();
}

void Witch :: display_in_file()
{
    ofstream f("Enemy.txt");
    f << health << endl;
    for (auto p : stats)
    {
        f << p.first << ' ' << p.second << endl;
    }
    f.close();
}