#include <gtest/gtest.h>

#include "main.hpp"

TEST(MegaphoneTest, BasicAssertions) {
  EXPECT_EQ("AAA", megaphone("aaa"));
  EXPECT_EQ("AAA", megaphone("AAA"));
  EXPECT_EQ("", megaphone(""));
  EXPECT_EQ("___", megaphone("___"));
  EXPECT_EQ("_A!_'_A", megaphone("_A!_'_a"));
  EXPECT_EQ("SHHHHH... I THINK THE STUDENTS ARE ASLEEP...",
            megaphone("shhhhh... I think the students are asleep..."));
  EXPECT_EQ(
      "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.",
      megaphone("Damnit ! Sorry students, I thought this thing was off."));
}
