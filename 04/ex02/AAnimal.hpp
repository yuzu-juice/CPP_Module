#ifndef AANIMAL_HPP_
#define AANIMAL_HPP_

#include <string>

class AAnimal {
 public:
  AAnimal();
  AAnimal(const std::string&);
  AAnimal(const AAnimal&);
  AAnimal& operator=(const AAnimal&);
  virtual ~AAnimal();

  std::string getType() const;

  virtual void makeSound() const = 0;

 protected:
  std::string type;
};

#endif
