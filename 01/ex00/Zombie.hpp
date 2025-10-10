#ifndef ZOMBIE_HPP_
#define ZOMBIE_HPP_

#include <string>

class Zombie {
 public:
  Zombie(std::string);
  ~Zombie();
  void annouce();

 private:
  std::string name;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
