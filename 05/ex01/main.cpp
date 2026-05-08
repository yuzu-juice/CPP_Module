#include <exception>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  Bureaucrat b = Bureaucrat("Alice");
  Form f = Form("Form1", 150, 150);

  std::cout << b << std::endl;
  std::cout << f << std::endl;

  b.signForm(f);  // Success

  std::cout << "-------------------------------" << std::endl;

  Form g = Form("Form2", 100, 100);

  std::cout << b << std::endl;
  std::cout << g << std::endl;

  b.signForm(g);  // Error

  return 0;
}
