#include <iostream>

#include "contact.class.hpp"
#include "phonebook.class.hpp"

int main(int argc, char *argv[]) {
  PhoneBook phonebook;
  Contact contact;
  std::string input;

  while (true) {
    std::cin >> input;
    if (input == "ADD") {
      std::cout << "last name?: ";
      std::cin >> contact.last_name;
      std::cout << "first name?: ";
      std::cin >> contact.first_name;
      std::cout << "nickname?: ";
      std::cin >> contact.nickname;
      std::cout << "phone number?: ";
      std::cin >> contact.phone_number;
      std::cout << "darkest secret?: ";
      std::cin >> contact.darkest_secret;
      phonebook.Add(contact);
      std::cout << "Current phonebook size is " << phonebook.ListSize()
                << std::endl;
    } else if (input == "SEARCH")
      std::cout << "SEARCH called" << std::endl;
    else if (input == "EXIT")
      break;
    else
      continue;
  }
  return (0);
}
