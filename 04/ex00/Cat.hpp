#ifndef CAT_HPP_
#define CAT_HPP_

#include <string>

#include "Animal.hpp"

class Cat : public Animal {
 public:
  Cat();
  Cat(const Cat &);
  Cat &operator=(const Cat &);
  ~Cat();

  void makeSound() const;
};

#endif
