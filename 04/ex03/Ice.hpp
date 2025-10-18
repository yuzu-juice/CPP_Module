#ifndef ICE_HPP_
#define ICE_HPP_

#include "AMateria.hpp"

class Ice : public AMateria {
 public:
  Ice();
  Ice(const Ice&);
  Ice& operator=(const Ice&);
  ~Ice();

  AMateria* clone() const;
  void use(ICharacter&);
};

#endif
