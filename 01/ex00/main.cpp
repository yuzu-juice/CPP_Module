#include "Zombie.hpp"

int main() {
  Zombie zom("Foo");
  zom.annouce();
  Zombie *zom2 = newZombie("Bar");
  zom2->annouce();
  randomChump("Hoge");
  delete zom2;
  return 0;
}
