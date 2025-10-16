#ifndef CAT_HPP_
#define CAT_HPP_

#include <string>

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
 public:
  Cat();
  Cat(const Cat&);
  Cat& operator=(const Cat&);
  ~Cat();

  void makeSound() const;

  Brain* getBrain() const;

 private:
  Brain* _brain;
};

#endif
