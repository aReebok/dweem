#include "../react.h"


int main() {
  init();
  print_at(1000,"continue");
  add_yaml("enemy_death.yaml", {{"enemy_img", "https://cdnb.artstation.com/p/assets/images/images/011/040/705/original/ismael-gil-death.gif?1527559338"}});
  quit();
}
