#include <gtest/gtest.h>

#include "Contact.hpp"
#include "PhoneBook.hpp"

TEST(AddContactTest, AddSingleContact) {
  PhoneBook pb;
  Contact contact;

  contact.setFirstName("hoge");
  contact.setLastName("fuga");
  contact.setNickname("piyo");
  contact.setPhoneNumber("123");
  contact.setDarkestSecret("secret");
  pb.addContact(contact);
  EXPECT_EQ(pb.getPhoneBookSize(), 1);
  Contact got = pb.getContact(0);
  EXPECT_EQ(got.getFirstName(), "hoge");
  EXPECT_EQ(got.getLastName(), "fuga");
  EXPECT_EQ(got.getNickname(), "piyo");
  EXPECT_EQ(got.getPhoneNumber(), "123");
  EXPECT_EQ(got.getDarkestSecret(), "secret");
}

TEST(PhoneBookTest, AllMaxCountContact) {
  PhoneBook pb;
  for (int i = 0; i < 8; ++i) {
    Contact contact;

    contact.setFirstName("Name" + std::to_string(i));
    contact.setLastName("Last" + std::to_string(i));
    contact.setNickname("Nick" + std::to_string(i));
    contact.setPhoneNumber(std::to_string(i));
    contact.setDarkestSecret("Secret" + std::to_string(i));
    pb.addContact(contact);
  }
  EXPECT_EQ(pb.getPhoneBookSize(), 8);
  Contact got = pb.getContact(7);
  EXPECT_EQ(got.getFirstName(), "Name7");
}

TEST(PhoneBookTest, AllOverflowContact) {
  PhoneBook pb;
  for (int i = 0; i < 9; ++i) {
    Contact contact;

    contact.setFirstName("Name" + std::to_string(i));
    contact.setLastName("Last" + std::to_string(i));
    contact.setNickname("Nick" + std::to_string(i));
    contact.setPhoneNumber(std::to_string(i));
    contact.setDarkestSecret("Secret" + std::to_string(i));
    pb.addContact(contact);
  }
  EXPECT_EQ(pb.getPhoneBookSize(), 8);
  Contact got = pb.getContact(0);
  EXPECT_EQ(got.getFirstName(), "Name1");
}
