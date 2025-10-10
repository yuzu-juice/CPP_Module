#ifndef ZOMBIE_HPP_
#define ZOMBIE_HPP_

#include <string>

class Zombie {
 public:
  Zombie();
  ~Zombie();
  void annouce();
  void setName(std::string);

 private:
  std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
