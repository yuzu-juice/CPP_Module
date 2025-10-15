#include <iostream>

#include "ScavTrap.hpp"

void debug(ScavTrap &test);

int main() {
  ScavTrap test1("test1");
  ScavTrap test2(test1);
  ScavTrap test3;
  test3 = test2;

  debug(test1);
  debug(test2);
  debug(test3);

  return 0;
}

void debug(ScavTrap &test) {
  std::cout << "Test==============================" << std::endl;
  std::cout << "hit points: " << test.getHitPoints() << std::endl;
  std::cout << "energy points: " << test.getEnergyPoints() << std::endl;
  std::cout << "attack damage:" << test.getAttackDamage() << std::endl
            << std::endl;

  test.attack("enemy");
  std::cout << "hit points: " << test.getHitPoints() << std::endl;
  std::cout << "energy points: " << test.getEnergyPoints() << std::endl;
  test.beRepaired(10);
  std::cout << "hit points: " << test.getHitPoints() << std::endl;
  std::cout << "energy points: " << test.getEnergyPoints() << std::endl;
  test.takeDamage(5);
  std::cout << "hit points: " << test.getHitPoints() << std::endl;
  test.guardGate();
  std::cout << "==================================" << std::endl << std::endl;
}
