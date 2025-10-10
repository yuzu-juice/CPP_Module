#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie() {}

Zombie::~Zombie() { std::cout << this->name << " is dead." << std::endl; }

void Zombie::annouce() {
  std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) { this->name = name; }
