#ifndef DOG_HPP_
#define DOG_HPP_

#include <string>

#include "Animal.hpp"

class Dog : public Animal {
 public:
  Dog();
  Dog(const Dog &);
  Dog &operator=(const Dog &);
  ~Dog();

  void makeSound() const;
};

#endif
