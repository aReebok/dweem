#include "../react.h"
include <stacks>
class Scene {
  string bgimg, charimg, enmimg;
  int ParaIndex;
  signed int bgTop, charTop, charRight;
public: 
  Scene () {
    bgimg = "https://i.pinimg.com/originals/89/fa/82/89fa825239b04567aa4b0b2bcf7c05b7.gif";
    charimg = "https://cdna.artstation.com/p/assets/images/images/011/040/706/original/ismael-gil-sprite-walk.gif?1527559340";
    enmimg = "";
    ParaIndex = 2000;
    bgTop = 195; // 195
    charTop = -80;
    charRight = 110;

  }
  Scene (string bg, string ch, string en, int para, signed int bgT, signed int charT, signed int charR){
    bgimg = bg;
    charimg = ch;
    enmimg = en;
    ParaIndex = para;
    bgTop = bgT;
    charTop = charT;
    charRight = charR;
  }
  //methods: 
  display_yaml() {
    add_yaml("story_template.yaml",{{"bgimg", bgimg},{"charimg", charimg},\
    {"bgTop",bgTop},{"charTop", charTop}, {"charRight", charRight},\
    {"enmimg",enmimg},{"paraIndex",ParaIndex}});
  }
  display(){ 

  }
};

int main() {
  init();
  //story button indecies
  print_at ( 1100, ">"); // next button
  print_at(1200, "settings");// settings button: doesnt do anything yet
  print_at(1220, "help"); // help button ---- 
  // HEALTH AND MANA STATS::
  print_at(1240,"  health  ************" );
  print_at(1290, "  mana  ************");
  //help button has a back button with this label:
  print_at(1320,"back");
  print_at (1400, "instructions:");
  print_at (1420, " Click on '>' button to procceed with story.\n Use button 'engage' to confront enemies.");
  //death
  print_at (1330,"menu");
  //COMBAT BUTTONS === 
  print_at(1340,"fight");
  print_at(1350,"items");
  print_at(1360,"talk");
  print_at(1370,"leave");

  //STORY PLOT ---
  print_at(2000,"Hello, you're running through the woods.\n\
Cool you hear something down the road\n\
you keep running lol ok.......");
  print_at(3000,"OH! looks like you ran into a ENEMY.\n\
Oh!! oh NOOOOOOOOOO!!!\n\
But you can probably defeat him!\n\
engage!");



    string bgimg = "https://i.pinimg.com/originals/89/fa/82/89fa825239b04567aa4b0b2bcf7c05b7.gif";
    string charimg = "https://cdna.artstation.com/p/assets/images/images/011/040/706/original/ismael-gil-sprite-walk.gif?1527559340";
    string enmimg = "";
    int ParaIndex = 2000;
    signed int bgTop = 195; // 195
    signed int charTop = -80;
    signed int charRight = 110;
    

    
    Scene();
    add_yaml("story_template.yaml",{{"bgimg", bgimg},{"charimg", charimg},\
    {"bgTop",bgTop},{"charTop", charTop}, {"charRight", charRight},\
    {"enmimg",enmimg},{"paraIndex",ParaIndex}});


    const int health_index = 410;
    const int mana_index = 450;
    const int exit_index = 490;
    const int menu_index = 810;
    const int text_index = 8000;
    const int settings_index = 890;
    const int help_index = 920;
    const int arr [] = {0,1000,2,3,4,5};
    int counter = 0;

    const int attack_index = 940;
    const int item_index = 960;
    const int leave_index = 980;
    const int talk_index = 1000;

    print_at(health_index,"  health  ************" );
    print_at(mana_index, "  mana  ************");
    print_at(exit_index,"back");
    print_at (menu_index,"menu");
    print_at (text_index, ">");
    print_at(settings_index, "settings");
    print_at(help_index, "help");

  int state = 0;
  int prev = 0;
  
  if (just_starting()) {
    state = 0;
    prev = 0;
  }
  if (received_event()) {
    if (event_id_is("button_help")) {
      prev = state;
      state = 99;
    }

    if (event_id_is("button_000")) {
      counter += 1;
      state = arr[counter];
    }

    if (event_id_is("button_next")) {
      counter += 1;
      state = arr[counter];
    }
  }

  if (state == 0) {
    string bgimg = "https://i.pinimg.com/originals/89/fa/82/89fa825239b04567aa4b0b2bcf7c05b7.gif";
    string charimg = "https://cdna.artstation.com/p/assets/images/images/011/040/706/original/ismael-gil-sprite-walk.gif?1527559340";
    string enmimg = "";
    int ParaIndex = 2000;
    signed int bgTop = 195; // 195
    signed int charTop = -80;
    signed int charRight = 110;
    add_yaml("story_template.yaml",{{"bgimg", bgimg},{"charimg", charimg},\
    {"bgTop",bgTop},{"charTop", charTop}, {"charRight", charRight},\
    {"enmimg",enmimg},{"paraIndex",ParaIndex}});
  }
  if (state == 99) add_yaml("help.yaml");

  if (state == 1000) {
    string bgimg = "frame_1.png";
    string charimg = "";
    string enmimg ="enemy_s1.png";
    int ParaIndex = 3000;
    signed int bgTop = 100; // 195
    signed int charTop = -80;
    signed int charRight = 110;
      add_yaml("story_template.yaml",{{"bgimg", bgimg},{"charimg", charimg},\
  {"bgTop",bgTop},{"charTop", charTop}, {"charRight", charRight},\
  {"enmimg",enmimg},{"paraIndex",ParaIndex}});
  }

  //if (state == 2) {add_yaml("fight_template.yaml", {{"health", health_index}, {"mana", mana_index}, {"exit", exit_index}, {"menu", menu_index}, {"text", text_index}, {"settings", settings_index}, {"help", help_index}, {"attack", attack_index}, {"item", item_index}, {"talk", talk_index}, {"leave", leave_index}});}


  //SCENE1:
  //string bgimg = "https://i.pinimg.com/originals/89/fa/82/89fa825239b04567aa4b0b2bcf7c05b7.gif";
  //string charimg = "https://cdna.artstation.com/p/assets/images/images/011/040/706/original/ismael-gil-sprite-walk.gif?1527559340";
  // string bgimg = "frame_1.png";
  // string charimg = "";
  // string enmimg ="enemy_s1.png";
  // signed int bgTop = 100; // 195
  // signed int charTop = -80;
  // signed int charRight = 110;
  // //attempt to interpolate 
  // add_yaml("story_template.yaml",{{"bgimg", bgimg},{"charimg", charimg},\
  // {"bgTop",bgTop},{"charTop", charTop}, {"charRight", charRight},\
  // {"enmimg",enmimg}});
  //add_yaml ("help.yaml"); 

  //

  quit();

}
