#ifndef WRONGCAT_HPP_
#define WRONGCAT_HPP_

#include <string>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 public:
  WrongCat();
  WrongCat(const WrongCat &);
  WrongCat &operator=(const WrongCat &);
  ~WrongCat();

  void makeSound() const;
};

#endif
