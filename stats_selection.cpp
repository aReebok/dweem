#include"../react.h"
#include"Entity2.h"

int main()
{
    init();
    const int index0 = 10;
    const int index1 = 25;
    const int index2 = 40;
    const int index3 = 55;
    const int index4 = 70;
    const int index5 = 85;
    const int buttonIndex = 100;
    const int strengthIndex = 130;
    const int speedIndex = 140;
    const int dexterityIndex = 150;
    const int intelligenceIndex = 160;
    const int wisdomIndex = 170;
    const int charismaIndex = 180;
    add_yaml("stats_selection.yaml", {{"index0", index0}, {"index1", index1}, {"index2", index2}, {"index3", index3}, {"index4", index4}, {"index5", index5}, {"button_index", buttonIndex}, {"StrengthInput", strengthIndex}, {"SpeedInput", speedIndex}, {"DexterityInput", dexterityIndex}, {"IntelligenceInput", intelligenceIndex}, {"WisdomInput", wisdomIndex}, {"CharismaInput", charismaIndex}});
    print_at(index0, "Strength:");
    print_at(index1, "Speed:");
    print_at(index2, "Dexterity:");
    print_at(index3, "Intelligence:");
    print_at(index4, "Wisdom:");
    print_at(index5, "Charisma:");
    print_at(buttonIndex, "View Character!");
    
    if (received_event())
    {
        if (event_id_is("to_game"))
        {
            float str = as_integer(130);

            float sp = as_integer(140);
            float dex = as_integer(150);
            float intel = as_integer(160);
            float wis = as_integer(170);
            float ch = as_integer(180);

            Human Hal(str,sp,dex,intel,wis,ch);

            add_yaml()
        }
    }

    quit();

}