#include "Zombie.hpp"

int main() {
  int N = 10;
  Zombie* horde = zombieHorde(N, "Foo");
  for (int i = 0; i < N; ++i) horde[i].annouce();
  delete[] horde;
  return 0;
}
