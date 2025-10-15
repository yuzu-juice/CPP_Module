#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  const Animal* meta = new Animal();
  const Animal* inu = new Dog();
  const Animal* neko = new Cat();

  std::cout << inu->getType() << std::endl;
  std::cout << neko->getType() << std::endl;
  inu->makeSound();
  neko->makeSound();
  meta->makeSound();

  delete meta;
  delete inu;
  delete neko;

  const WrongAnimal* wrong_neko = new WrongCat();
  wrong_neko->makeSound();

  delete wrong_neko;

  return 0;
}
