#include "Bureaucrat.hpp"

int main() {
  Bureaucrat b = Bureaucrat();
  b.incrementGrade();
  std::cout << b.getGrade() << std::endl;
  return 0;
}
