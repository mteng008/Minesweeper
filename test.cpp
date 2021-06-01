#include "menu.h"
#include "board.h"

#include "gtest/gtest.h"

TEST(BaseTest, Overall) {
  char* test_val[1]; test_val[0] = "./play_game";
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}



