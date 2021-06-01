#include "menu.h"
#include "board.h"

#include "gtest/gtest.h"

TEST(BaseTest, Overall) {
  char* test_val[1]; test_val[0] = "./play_game";
}

TEST(Game, New) {
  char* test_val[2]; test_val[0] = "./play_game"; test_val[1] = "N";
}

TEST(DifficultyTest, Easy){
   char* test_val[3]; test_val[0] = "./play_game"; test_val[1] = "N"; test_val[3] = "E";
}


TEST(DifficultyTest, Medium){
   char* test_val[3]; test_val[0] = "./play_game"; test_val[1] = "N"; test_val[3] = "M";
}


TEST(DifficultyTest, Hard){
   char* test_val[3]; test_val[0] = "./play_game"; test_val[1] = "N"; test_val[3] = "H";
}


TEST(DifficultyTest, Custom){
   char* test_val[3]; test_val[0] = "./play_game"; test_val[1] = "N"; test_val[3] = "C";
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}



