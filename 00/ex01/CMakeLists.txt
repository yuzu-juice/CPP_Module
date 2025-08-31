enable_testing()

add_executable(
  ex01_test
  ex01.test.cpp
  contact.class.cpp
  contact.class.hpp
  phonebook.class.cpp
  phonebook.class.hpp
)
target_link_libraries(
  ex01_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ex01_test)
