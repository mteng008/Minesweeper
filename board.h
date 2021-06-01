fndef BOARD_H
#define BOARD_H

#include<time.h>
#include<stdlib.h>
#include<iostream>
#include <iomanip>
#include<cstring>
using namespace std;

#define MAXSIDE 31
#define MAXMINES 200

class Board {
protected:
	int sideLength;
	int numMines;
	int movesLeft;
	int mines[MAXMINES][2];
	int currentMove;
	int x;
	int y;
	bool gameOver;
	char realBoard[MAXSIDE][MAXSIDE];
	char myBoard[MAXSIDE][MAXSIDE];
	void init(char realBoard[][MAXSIDE], char myBoard[][MAXSIDE]);
	void placeMines(int mines[][2], char realBoard[][MAXSIDE]);
	void printBoard(char myBoard[][MAXSIDE]);
	void makeMove(int* x, int* y);
	void replaceMine(int row, int col, char board[][MAXSIDE]);
	bool isMine(int row, int col, char board[][MAXSIDE]);
	bool isValid(int row, int col);
	bool playMinesweeper(char myBoard[][MAXSIDE], char realBoard[][MAXSIDE],
		int mines[][2], int row, int col, int* movesLeft);
	int countAdjacentMines(int row, int col, int mines[][2], char realBoard[][MAXSIDE]);
public:
	void play();
};

class Easy : public Board {
public:
	Easy();
};

class Medium : public Board {
public:
	Medium();
};

class Hard : public Board {
public:
	Hard();
};

class Custom : public Board {
public:
	Custom(int sideLength, int numMines);
};

#endif
