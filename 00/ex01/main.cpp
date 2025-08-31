#include <iostream>

#include "contact.class.hpp"
#include "phonebook.class.hpp"

int main(int argc, char *argv[]) {
  PhoneBook phonebook;
  Contact contact;
  std::string input;
  std::array<Contact, 8> allContacts;

  while (true) {
    std::cout << "> ";
    std::cin >> input;
    if (std::cin.eof())
      break;
    else if (input == "ADD") {
      std::cout << "last name?: ";
      std::cin >> input;
      if (std::cin.eof()) break;
      contact.setLastName(input);
      std::cout << "first name?: ";
      std::cin >> input;
      if (std::cin.eof()) break;
      contact.setFirstName(input);
      std::cout << "nickname?: ";
      std::cin >> input;
      if (std::cin.eof()) break;
      contact.setNickname(input);
      std::cout << "phone number?: ";
      std::cin >> input;
      if (std::cin.eof()) break;
      contact.setPhoneNumber(input);
      std::cout << "darkest secret?: ";
      std::cin >> input;
      if (std::cin.eof()) break;
      contact.setDarkestSecret(input);
      phonebook.addContact(contact);
    } else if (input == "SEARCH") {
      allContacts = phonebook.getAllContacts();
      phonebook.displayAllConacts(allContacts);
    } else if (input == "EXIT") {
      break;
    } else {
      continue;
    }
  }
  return (0);
}
