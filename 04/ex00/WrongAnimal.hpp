#ifndef WRONGANIMAL_HPP_
#define WRONGANIMAL_HPP_

#include <string>

class WrongAnimal {
 public:
  WrongAnimal();
  WrongAnimal(const std::string &);
  WrongAnimal(const WrongAnimal &);
  WrongAnimal &operator=(const WrongAnimal &);
  virtual ~WrongAnimal();

  std::string getType() const;

  void makeSound() const;

 protected:
  std::string type;
};

#endif
