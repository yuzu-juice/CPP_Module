enable_testing()

add_executable(
  ex01_test
  ex01.test.cpp
  Contact.cpp
  Contact.hpp
  PhoneBook.cpp
  PhoneBook.hpp
)
target_link_libraries(
  ex01_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ex01_test)
