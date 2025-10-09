#include <gtest/gtest.h>

#include "Zombie.hpp"

TEST(ZombieTest, BasicAssertions) {
  Zombie test_zom("Foo");
  EXPECT_EQ("Foo:  BraiiiiiiinnnzzzZ...", test_zom.annouce());
}
