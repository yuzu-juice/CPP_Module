#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 public:
  ScavTrap();
  ScavTrap(std::string);
  ~ScavTrap();
  void guardGate();
};
