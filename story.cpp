#include"../react.h"

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
  int state = 0;
  int prev = 0;

  
  if (just_starting()) state = 0;
  if (received_event()) {
    if (event_id_is("button_help")) {
      prev = state;
      state = 1;
    }
    if (event_id_is("button_000")) state = prev;
  }

  if (state == 0) {
    string bgimg = "https://i.pinimg.com/originals/89/fa/82/89fa825239b04567aa4b0b2bcf7c05b7.gif";
    string charimg = "https://cdna.artstation.com/p/assets/images/images/011/040/706/original/ismael-gil-sprite-walk.gif?1527559340";
    string enmimg ="";
    signed int bgTop = 195; // 195
    signed int charTop = -80;
    signed int charRight = 110;
    add_yaml("story_template.yaml",{{"bgimg", bgimg},{"charimg", charimg},\
    {"bgTop",bgTop},{"charTop", charTop}, {"charRight", charRight},\
    {"enmimg",enmimg}});

  }
  if (state == 1) add_yaml("help.yaml");

  if (state == 2) {
    string bgimg = "frame_1.png";
    string charimg = "";
    string enmimg ="enemy_s1.png";
    signed int bgTop = 100; // 195
    signed int charTop = -80;
    signed int charRight = 110;
      add_yaml("story_template.yaml",{{"bgimg", bgimg},{"charimg", charimg},\
  {"bgTop",bgTop},{"charTop", charTop}, {"charRight", charRight},\
  {"enmimg",enmimg}});
  }

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
