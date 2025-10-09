enable_testing()

add_executable(
  ex00_test
  ex00.test.cpp
  Zombie.cpp
  Zombie.hpp
  newZombie.cpp
  randomChump.cpp
)
target_link_libraries(
  ex00_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ex00_test)
