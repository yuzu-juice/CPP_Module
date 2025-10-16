#include <iostream>

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  // const AAnimal* meta = new AAnimal();
  const AAnimal* inu = new Dog();
  const AAnimal* neko = new Cat();

  // meta->makeSound();
  inu->makeSound();
  neko->makeSound();

  return 0;
}
