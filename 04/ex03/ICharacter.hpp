#ifndef ICHARACTER_HPP_
#define ICHARACTER_HPP_

#include "AMateria.hpp"

class ICharacter {
 public:
  virtual ~ICharacter() {}
  virtual std::string const& getName() const = 0;
  virtual void equip(AMateria*) = 0;
  virtual void unequip(int) = 0;
  virtual void use(int, ICharacter&) = 0;

 private:
  std::string _name;
};

#endif
