#ifndef CLAPTRAP_HPP_
#define CLAPTRAP_HPP_

#include <string>

class ClapTrap {
 public:
  ClapTrap();
  ClapTrap(std::string);
  ~ClapTrap();

  ClapTrap(const ClapTrap &);

  ClapTrap &operator=(const ClapTrap &);

  void attack(const std::string &);
  void takeDamage(unsigned int);
  void beRepaired(unsigned int);

  void setHitPoints(int);
  void setEnergyPoints(int);
  void setAttackDamage(int);

  int getHitPoints() const;
  int getEnergyPoints() const;
  int getAttackDamage() const;

 private:
  std::string _name;
  int _hit_points;
  int _energy_points;
  int _attack_damage;
};

#endif
