#ifndef FRAGTRAP_HPP_
#define FRAGTRAP_HPP_

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
 public:
  FragTrap();
  FragTrap(const std::string &);
  FragTrap(const FragTrap &);

  ~FragTrap();

  FragTrap &operator=(const FragTrap &);

  void attack(const std::string &);
  void takeDamage(unsigned int);
  void beRepaired(unsigned int);

  void highFivesGuys();
};

#endif
