#include <iostream>

#include "FragTrap.hpp"

void basic_test(FragTrap &test);
void hp_exhaustion_test(FragTrap &test);
void ep_exhaustion_test(FragTrap &test);
void hp_max_cap_test(FragTrap &test);
void take_big_damage_test(FragTrap &test);

int main() {
  FragTrap test1("test1");
  FragTrap test2(test1);
  FragTrap test3;
  FragTrap test4(test1);
  FragTrap test5(test1);
  test3 = test2;

  basic_test(test1);
  hp_exhaustion_test(test2);
  ep_exhaustion_test(test3);
  hp_max_cap_test(test4);
  take_big_damage_test(test5);

  return 0;
}

void basic_test(FragTrap &test) {
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

void hp_exhaustion_test(FragTrap &test) {
  std::cout << "HP_EXHAUSTION_TEST======================" << std::endl;
  std::cout << "hit points: " << test.getHitPoints() << std::endl;
  std::cout << "energy points: " << test.getEnergyPoints() << std::endl;
  std::cout << "attack damage: " << test.getAttackDamage() << std::endl
            << std::endl;

  test.takeDamage(101);
  std::cout << "hit points: " << test.getHitPoints() << std::endl;
  std::cout << "energy points: " << test.getEnergyPoints() << std::endl;

  test.attack("enemy");
  test.beRepaired(10);
  test.takeDamage(1);
  std::cout << "==================================" << std::endl << std::endl;
}

void ep_exhaustion_test(FragTrap &test) {
  std::cout << "EP_EXHAUSTION_TEST======================" << std::endl;
  std::cout << "hit points: " << test.getHitPoints() << std::endl;
  std::cout << "energy points: " << test.getEnergyPoints() << std::endl;
  std::cout << "attack damage: " << test.getAttackDamage() << std::endl
            << std::endl;

  for (int i = 0; i < 100; ++i) test.attack("enemy");
  std::cout << "hit points: " << test.getHitPoints() << std::endl;
  std::cout << "energy points: " << test.getEnergyPoints() << std::endl;

  test.attack("enemy");
  test.beRepaired(10);
  std::cout << "==================================" << std::endl << std::endl;
}

void hp_max_cap_test(FragTrap &test) {
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

void take_big_damage_test(FragTrap &test) {
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
