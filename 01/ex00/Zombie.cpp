#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie() { std::cout << this->_name << " is dead." << std::endl; }

void Zombie::annouce() {
  std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
