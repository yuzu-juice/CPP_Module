#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
 public:
  FragTrap();
  FragTrap(std::string);
  FragTrap(const FragTrap &);

  ~FragTrap();

  FragTrap &operator=(const FragTrap &);

  void attack(const std::string &);
  void takeDamage(unsigned int);
  void beRepaired(unsigned int);

  void highFivesGuys();
};
