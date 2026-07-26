#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

namespace {

void testBothOverloads(Base* object) {
  std::cout << "pointer:   ";
  identify(object);
  std::cout << "reference: ";
  identify(*object);
}

}  // namespace

int main() {
  std::srand(static_cast<unsigned int>(std::time(NULL)));

  A a;
  B b;
  C c;

  std::cout << "fixed types\n";
  testBothOverloads(&a);
  testBothOverloads(&b);
  testBothOverloads(&c);

  std::cout << "generated types\n";
  for (int i = 0; i < 9; ++i) {
    Base* object = generate();
    testBothOverloads(object);
    delete object;
  }
  return 0;
}
