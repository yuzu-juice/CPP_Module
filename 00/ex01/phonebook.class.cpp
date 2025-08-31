#include "phonebook.class.hpp"

#include <iostream>

PhoneBook::PhoneBook(void) {}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::addContact(Contact contact) {
  if (_last_index < 7) {
    _array[_last_index] = contact;
    _last_index++;
    return;
  }

  for (int i = 0; i < 8; i++) {
    _array[i] = _array[i + 1];
  }
  _array[_last_index] = contact;
}

std::array<Contact, 8> PhoneBook::getAllContacts() const { return (_array); }

void PhoneBook::displayAllConacts(std::array<Contact, 8> allContacts) const {
  std::cout << "|     index|first name| last name|  nickname|" << std::endl;
  std::cout << "|----------|----------|----------|----------|" << std::endl;
  for (int i = 0; i < getPhoneBookSize(); i++) {
    std::cout << "|         " << i << "|" << allContacts[i].getFirstName()
              << "|" << allContacts[i].getLastName() << "|"
              << allContacts[i].getNickname() << "|" << std::endl;
  }
}

size_t PhoneBook::getPhoneBookSize() const { return (_last_index + 1); }
