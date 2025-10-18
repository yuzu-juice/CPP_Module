#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  const Animal* animals[10];
  for (int i = 0; i < 5; ++i) {
    animals[i] = new Dog();
  }
  for (int i = 5; i < 10; ++i) {
    animals[i] = new Cat();
  }
  for (int i = 0; i < 10; ++i) animals[i]->makeSound();
  for (int i = 0; i < 10; ++i) delete animals[i];

  Cat* neko1 = new Cat();
  if (neko1 == NULL) return 1;
  neko1->getBrain()->setIdea(0, "neko idea 0");
  neko1->getBrain()->setIdea(1, "neko idea 1");
  neko1->getBrain()->setIdea(2, "neko idea 2");

  std::cout << neko1->getBrain()->getIdea(0) << std::endl;
  std::cout << neko1->getBrain()->getIdea(1) << std::endl;
  std::cout << neko1->getBrain()->getIdea(2) << std::endl;

  Cat* neko2 = new Cat(*neko1);
  if (neko2 == NULL) {
    delete neko1;
    return 1;
  }

  delete neko1;

  std::cout << neko2->getBrain()->getIdea(0) << std::endl;
  std::cout << neko2->getBrain()->getIdea(1) << std::endl;
  std::cout << neko2->getBrain()->getIdea(2) << std::endl;

  delete neko2;

  Dog* inu1 = new Dog();
  if (inu1 == NULL) return 1;
  inu1->getBrain()->setIdea(0, "inu idea 0");
  inu1->getBrain()->setIdea(1, "inu idea 1");
  inu1->getBrain()->setIdea(2, "inu idea 2");

  std::cout << inu1->getBrain()->getIdea(0) << std::endl;
  std::cout << inu1->getBrain()->getIdea(1) << std::endl;
  std::cout << inu1->getBrain()->getIdea(2) << std::endl;

  Dog* inu2 = new Dog(*inu1);
  if (inu2 == NULL) {
    delete inu1;
    return 1;
  }

  delete inu1;

  std::cout << inu2->getBrain()->getIdea(0) << std::endl;
  std::cout << inu2->getBrain()->getIdea(1) << std::endl;
  std::cout << inu2->getBrain()->getIdea(2) << std::endl;

  delete inu2;

  return 0;
}
