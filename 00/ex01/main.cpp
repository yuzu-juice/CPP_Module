#include <iostream>

#include "contact.class.hpp"
#include "phonebook.class.hpp"

void print_welcome_message(void);
void add(PhoneBook* phonebook);
void search(PhoneBook phonebook);

int main(int argc, char* argv[]) {
  PhoneBook phonebook;
  std::string input;

  print_welcome_message();
  while (true) {
    std::cout << "> ";
    if (!std::getline(std::cin, input))
      break;
    else if (input == "ADD") {
      add(&phonebook);
    } else if (input == "SEARCH") {
      search(phonebook);
    } else if (input == "EXIT") {
      std::cout << "bye." << std::endl;
      break;
    } else if (input.empty()) {
      continue;
    } else {
      continue;
    }
  }
  return (0);
}

void print_welcome_message(void) {
  std::cout << "Welcome to a phonebook." << std::endl;
  std::cout << "ADD, SEARCH and EXIT commands are accepted." << std::endl;
}

void add(PhoneBook* phonebook) {
  Contact contact;
  std::string last_name;
  std::string first_name;
  std::string nickname;
  std::string phone_number;
  std::string darkest_secret;

  while (last_name.empty()) {
    std::cout << "last name?: ";
    if (!std::getline(std::cin, last_name)) {
      std::cout << "Interrupted by user." << std::endl;
      return;
    }
  }
  while (first_name.empty()) {
    std::cout << "first name?: ";
    if (!std::getline(std::cin, first_name)) {
      std::cout << "Interrupted by user." << std::endl;
      return;
    }
  }
  while (nickname.empty()) {
    std::cout << "nickname?: ";
    if (!std::getline(std::cin, nickname)) {
      std::cout << "Interrupted by user." << std::endl;
      return;
    }
  }
  while (phone_number.empty()) {
    std::cout << "phone number?: ";
    if (!std::getline(std::cin, phone_number)) {
      std::cout << "Interrupted by user." << std::endl;
      return;
    }
  }
  while (darkest_secret.empty()) {
    std::cout << "darkest secret?: ";
    if (!std::getline(std::cin, darkest_secret)) {
      std::cout << "Interrupted by user." << std::endl;
      return;
    }
  }
  contact.setLastName(last_name);
  contact.setFirstName(first_name);
  contact.setNickname(nickname);
  contact.setPhoneNumber(phone_number);
  contact.setDarkestSecret(darkest_secret);
  phonebook->addContact(contact);
  std::cout << "Contact has successfully added." << std::endl;
}

void search(PhoneBook phonebook) {
  std::string input;
  std::array<Contact, 8> allContacts;
  size_t index;

  allContacts = phonebook.getAllContacts();
  phonebook.displayAllContacts(allContacts);
  std::cout << "index?: ";
  if (!std::getline(std::cin, input)) {
    std::cout << "Interrupted by user." << std::endl;
    return;
  }
  if (input.length() > 2) {
    std::cout << "index is invalid." << std::endl;
    return;
  }
  try {
    index = std::stoi(input);
  } catch (const std::invalid_argument& e) {
    std::cout << "index is invalid." << std::endl;
    return;
  }
  size_t phonebook_size = phonebook.getPhoneBookSize();
  if (phonebook_size == 0 || index < 0 || index >= phonebook_size) {
    std::cout << "index is invalid." << std::endl;
    return;
  }
  Contact contact = phonebook.getContact(index);
  phonebook.displayContact(contact);
}
