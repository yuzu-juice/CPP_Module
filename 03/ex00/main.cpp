#include <iostream>

#include "ClapTrap.hpp"

void basic_test(ClapTrap &test);
void hp_exhaustion_test(ClapTrap &test);
void ep_exhaustion_test(ClapTrap &test);
void hp_max_cap_test(ClapTrap &test);
void take_big_damage_test(ClapTrap &test);

int main() {
  ClapTrap test1("test1");
  ClapTrap test2(test1);
  ClapTrap test3;
  ClapTrap test4(test1);
  ClapTrap test5(test1);
  test3 = test2;

  basic_test(test1);
  hp_exhaustion_test(test2);
  ep_exhaustion_test(test3);
  hp_max_cap_test(test4);
  take_big_damage_test(test5);

  return 0;
}

void basic_test(ClapTrap &test) {
  std::cout << "BASIC_TEST==============================" << std::endl;
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
  std::cout << "==================================" << std::endl << std::endl;
}

void hp_exhaustion_test(ClapTrap &test) {
  std::cout << "HP_EXHAUSTION_TEST======================" << std::endl;
  std::cout << "hit points: " << test.getHitPoints() << std::endl;
  std::cout << "energy points: " << test.getEnergyPoints() << std::endl;
  std::cout << "attack damage: " << test.getAttackDamage() << std::endl
            << std::endl;

  test.takeDamage(11);
  std::cout << "hit points: " << test.getHitPoints() << std::endl;
  std::cout << "energy points: " << test.getEnergyPoints() << std::endl;

  test.attack("enemy");
  test.beRepaired(10);
  test.takeDamage(1);
  std::cout << "==================================" << std::endl << std::endl;
}

void ep_exhaustion_test(ClapTrap &test) {
  std::cout << "EP_EXHAUSTION_TEST======================" << std::endl;
  std::cout << "hit points: " << test.getHitPoints() << std::endl;
  std::cout << "energy points: " << test.getEnergyPoints() << std::endl;
  std::cout << "attack damage: " << test.getAttackDamage() << std::endl
            << std::endl;

  for (int i = 0; i < 10; ++i) test.attack("enemy");
  std::cout << "hit points: " << test.getHitPoints() << std::endl;
  std::cout << "energy points: " << test.getEnergyPoints() << std::endl;

  test.attack("enemy");
  test.beRepaired(10);
  std::cout << "==================================" << std::endl << std::endl;
}

void hp_max_cap_test(ClapTrap &test) {
  std::cout << "HP_MAX_CAP_TEST======================" << std::endl;
  std::cout << "hit points: " << test.getHitPoints() << std::endl;
  std::cout << "energy points: " << test.getEnergyPoints() << std::endl;
  std::cout << "attack damage: " << test.getAttackDamage() << std::endl
            << std::endl;

  test.beRepaired(Limits::MAX_HP);
  std::cout << "hit points: " << test.getHitPoints() << std::endl;
  std::cout << "energy points: " << test.getEnergyPoints() << std::endl;
  std::cout << "==================================" << std::endl << std::endl;
}

void take_big_damage_test(ClapTrap &test) {
  std::cout << "TAKE_BIG_DAMAGE_TEST=================" << std::endl;
  std::cout << "hit points: " << test.getHitPoints() << std::endl;
  std::cout << "energy points: " << test.getEnergyPoints() << std::endl;
  std::cout << "attack damage: " << test.getAttackDamage() << std::endl
            << std::endl;

  test.takeDamage(Limits::MAX_HP);
  std::cout << "hit points: " << test.getHitPoints() << std::endl;
  std::cout << "energy points: " << test.getEnergyPoints() << std::endl;
  std::cout << "==================================" << std::endl << std::endl;
}
