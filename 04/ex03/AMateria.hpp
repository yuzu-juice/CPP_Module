#ifndef AMATERIA_HPP_
#define AMATERIA_HPP_

#include <string>

#include "ICharacter.hpp"

class AMateria {
 public:
  AMateria();
  AMateria(std::string const&);
  AMateria(const AMateria&);

  AMateria& operator=(const AMateria&);

  virtual ~AMateria();

  std::string const& getType() const;
  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter&);

 protected:
  std::string _type;
};

#endif
