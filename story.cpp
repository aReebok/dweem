#include"../react.h"

int main() {
  init();
// HEALTH AND MANA STATS::
      print_at(1240,"  health  ************" );
      print_at(1290, "  mana  ************");
    print_at(1320,"back");
    //death
        print_at (1330,"menu");
    print_at ( 1100, ">");
    print_at(1200, "settings");
    print_at(1220, "help");


  add_yaml("fight_template.yaml");
  quit();

}
