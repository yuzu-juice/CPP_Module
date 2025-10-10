#include <iostream>

int main() {
  std::string str = "HI THIS IS BRAIN";
  std::string* stringPTR = &str;
  std::string stringREF = str;

  std::cout << "the address of str: " << &str << std::endl;
  std::cout << "the address of stringPTR: " << stringPTR << std::endl;
  std::cout << "the address of stringREF: " << &stringREF << std::endl
            << std::endl;

  std::cout << "the value of str: " << str << std::endl;
  std::cout << "the value pointed to by stringPTR: " << *stringPTR << std::endl;
  std::cout << "the value pointed to by stringREF: " << stringREF << std::endl;
  return 0;
}
