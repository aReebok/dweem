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

void Entity :: attack()
{
    map <string, float> update;
    ifstream f("Character.txt");
    string s;
    while (f >> s)
    {
        int n;
        f >> n;
        string c;
        getline(f, c);
    }
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