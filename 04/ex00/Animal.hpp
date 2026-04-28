#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

#include <string>

class Animal {
 public:
  Animal();
  Animal(const std::string &);
  Animal(const Animal &);
  Animal &operator=(const Animal &);
  virtual ~Animal();

  std::string getType() const;

  virtual void makeSound() const;

 protected:
  std::string type;
};

#endif
