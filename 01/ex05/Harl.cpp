#include "Harl.hpp"

#include <iostream>

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(std::string level) {
  void (Harl::*fptrs[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning,
                                  &Harl::error};
  std::string complains[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  for (int i = 0; i < 4; i++) {
    if (complains[i] == level) (this->*fptrs[i])();
  }
}

void Harl::debug() {
  std::cout
      << "DEBUG:" << std::endl
      << "I love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
      << std::endl;
}

void Harl::info() {
  std::cout << "INFO:" << std::endl
            << "I cannot believe adding extra bacon costs more money. "
               "You didn’t put enough bacon in my burger! If you did, I "
               "wouldn’t be asking for more!"
            << std::endl;
}

void Harl::warning() {
  std::cout << "WARNING:" << std::endl
            << "I think I deserve to have some extra bacon for free. "
               "I’ve been coming for years, whereas you started working here "
               "just last month."
            << std::endl;
}

void Harl::error() {
  std::cout << "ERROR:" << std::endl
            << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
}
