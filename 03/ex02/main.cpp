#include <iostream>

#include "FragTrap.hpp"

void debug(FragTrap &test);

int main() {
  FragTrap test1("test1");
  FragTrap test2(test1);
  FragTrap test3;
  test3 = test2;

  debug(test1);
  debug(test2);
  debug(test3);

  return 0;
}

void debug(FragTrap &test) {
  std::cout << "Test==============================" << std::endl;
  std::cout << "hit points: " << test.getHitPoints() << std::endl;
  std::cout << "energy points: " << test.getEnergyPoints() << std::endl;
  std::cout << "attack damage: " << test.getAttackDamage() << std::endl
            << std::endl;

  test.attack("enemy");
  std::cout << "hit points: " << test.getHitPoints() << std::endl;
  std::cout << "energy points: " << test.getEnergyPoints() << std::endl;
  test.beRepaired(10);
  std::cout << "hit points: " << test.getHitPoints() << std::endl;
  std::cout << "energy points: " << test.getEnergyPoints() << std::endl;
  test.takeDamage(5);
  std::cout << "hit points: " << test.getHitPoints() << std::endl;
  test.highFivesGuys();
  std::cout << "==================================" << std::endl << std::endl;
}
