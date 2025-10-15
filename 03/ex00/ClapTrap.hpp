#ifndef CLAPTRAP_HPP_
#define CLAPTRAP_HPP_

#include <string>

namespace Limits {
static const unsigned int MAX_HP = 1000;
static const unsigned int MAX_EP = 1000;
static const unsigned int MAX_DAMAGE = 1000;
}  // namespace Limits

class ClapTrap {
 public:
  ClapTrap();
  ClapTrap(std::string);
  ClapTrap(const ClapTrap &);

  ~ClapTrap();

  ClapTrap &operator=(const ClapTrap &);

  void attack(const std::string &);
  void takeDamage(unsigned int);
  void beRepaired(unsigned int);

  void setName(const std::string &);
  void setHitPoints(const unsigned int);
  void setEnergyPoints(const unsigned int);
  void setAttackDamage(const unsigned int);

  std::string getName() const;
  unsigned int getHitPoints() const;
  unsigned int getEnergyPoints() const;
  unsigned int getAttackDamage() const;

 private:
  std::string _name;
  unsigned int _hit_points;
  unsigned int _energy_points;
  unsigned int _attack_damage;
};

#endif
