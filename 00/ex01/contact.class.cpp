#include "contact.class.hpp"

#include <iostream>

Contact::Contact(void) {}

Contact::~Contact(void) {}

std::string Contact::getFirstName() const { return (_first_name); }
void Contact::setFirstName(std::string first_name) {
  this->_first_name = first_name;
}

std::string Contact::getLastName() const { return (_last_name); }
void Contact::setLastName(std::string last_name) {
  this->_last_name = last_name;
}

std::string Contact::getNickname() const { return (_nickname); }
void Contact::setNickname(std::string nickname) { this->_nickname = nickname; }

void Contact::setPhoneNumber(std::string phone_number) {
  this->_phone_number = phone_number;
}

void Contact::setDarkestSecret(std::string darkest_secret) {
  this->_darkest_secret = darkest_secret;
}
