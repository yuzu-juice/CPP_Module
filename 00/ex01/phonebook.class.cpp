#include "phonebook.class.hpp"

#include <iostream>

PhoneBook::PhoneBook(void) : _last_index(0) {}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::addContact(Contact contact) {
  if (_last_index < 8) {
    _array[_last_index] = contact;
    _last_index++;
  } else {
    for (int i = 0; i < 7; i++) {
      _array[i] = _array[i + 1];
    }
    _array[7] = contact;
  }
}

Contact PhoneBook::getContact(size_t index) const { return _array[index]; }

const Contact (&PhoneBook::getAllContacts() const)[8] { return (_array); }

void PhoneBook::displayContact(Contact contact) const {
  std::cout << "first name: " + contact.getFirstName() << std::endl;
  std::cout << "last name: " + contact.getLastName() << std::endl;
  std::cout << "nickname: " + contact.getNickname() << std::endl;
  std::cout << "phone number: " + contact.getPhoneNumber() << std::endl;
  std::cout << "darkest secret: " + contact.getDarkestSecret() << std::endl
            << std::endl;
}

void PhoneBook::displayAllContacts(const Contact allContacts[8]) const {
  std::cout << "|     index|first name| last name|  nickname|" << std::endl;
  std::cout << "|----------|----------|----------|----------|" << std::endl;
  for (size_t i = 0; i < getPhoneBookSize(); ++i) {
    std::cout << "|";
    std::cout << format(std::to_string(i));
    std::cout << "|";
    std::cout << format(allContacts[i].getFirstName());
    std::cout << "|";
    std::cout << format(allContacts[i].getLastName());
    std::cout << "|";
    std::cout << format(allContacts[i].getNickname());
    std::cout << "|" << std::endl;
  }
  std::cout << std::endl;
}

size_t PhoneBook::getPhoneBookSize() const { return (_last_index); }

std::string PhoneBook::format(std::string str) const {
  std::string ret;
  int len = str.length();

  if (len < 10) {
    for (int i = 0; i < 10 - len; ++i) {
      ret += " ";
    }
    ret += str;
  } else if (len > 10) {
    ret = str.substr(0, 9) + ".";
  }
  return ret;
}
