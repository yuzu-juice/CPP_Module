#include "phonebook.class.hpp"

#include <iostream>

PhoneBook::PhoneBook(void) {}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::Add(Contact contact) {
  if (this->_que.size() >= 8) {
    this->_que.pop();
  }
  this->_que.push(contact);
  return;
}

size_t PhoneBook::ListSize() { return this->_que.size(); }