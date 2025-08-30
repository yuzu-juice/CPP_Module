enable_testing()

add_executable(
  ex00_test
  ex00_test.cpp
  megaphone.cpp
  main.h
)
target_link_libraries(
  ex00_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ex00_test)
