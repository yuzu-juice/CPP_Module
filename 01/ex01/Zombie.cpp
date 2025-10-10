#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie() {}

Zombie::~Zombie() { std::cout << this->_name << " is dead." << std::endl; }

void Zombie::annouce() {
  std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) { this->_name = name; }
