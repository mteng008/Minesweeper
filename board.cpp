fndef BOARD_CPP
#define BOARD_CPP

#include "board.h"

void Board::init(char realBoard[][MAXSIDE], char myBoard[][MAXSIDE])
{
	srand(time(nullptr));

	for (int i = 0; i < sideLength; i++)
	{
		for (int j = 0; j < sideLength; j++)
		{
			myBoard[i][j] = realBoard[i][j] = '-';
		}
	}

	return;
}

void Board::placeMines(int mines[][2], char realBoard[][MAXSIDE])
{
	bool mark[MAXSIDE * MAXSIDE];

	memset(mark, false, sizeof(mark));

	for (int i = 0; i < numMines;)
	{
		int random = rand() % (sideLength * sideLength);
		int randx = random / sideLength;
		int randy = random % sideLength;

		if (mark[random] == false)
		{
			mines[i][0] = randx;

			mines[i][1] = randy;

			realBoard[mines[i][0]][mines[i][1]] = '*';
			mark[random] = true;
			i++;
		}
	}

	return;
}

void Board::printBoard(char myBoard[][MAXSIDE])
{
	cout << "    ";

	for (int i = 0; i < sideLength; i++)
	{
		cout << setw(2) << left << i << " ";
	}

	cout << endl << endl;

	for (int i = 0; i < sideLength; i++)
	{
		cout << setw(2) << right << i << "  ";

		for (int j = 0; j < sideLength; j++)
		{
			cout << myBoard[i][j] << "  ";
		}
		cout << endl;
	}
	return;
}

void Board::makeMove(int* x, int* y)
{
	cout << "Enter your move, (row, column): ";
	cin >> *x;
	cin >> *y;
	return;
}

void Board::replaceMine(int row, int col, char board[][MAXSIDE])
{
	for (int i = 0; i < sideLength; i++)
	{
		for (int j = 0; j < sideLength; j++)
		{
			if (board[i][j] != '*')
			{
				board[i][j] = '*';
				board[row][col] = '-';
				return;
			}
		}
	}
	return;
}

bool Board::isMine(int row, int col, char board[][MAXSIDE])
{
	if (board[row][col] == '*')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Board::isValid(int row, int col)
{
	return (row >= 0) && (row < sideLength) && (col >= 0) && (col < sideLength);
}

bool Board::playMinesweeper(char myBoard[][MAXSIDE], char realBoard[][MAXSIDE], int mines[][2], int row, int col, int* movesLeft)
{

	if (myBoard[row][col] != '-')
	{
		return false;
	}

	if (realBoard[row][col] == '*')
	{
		myBoard[row][col] = '*';

		for (int i = 0; i < numMines; i++)
		{
			myBoard[mines[i][0]][mines[i][1]] = '*';
		}

		system("CLS");
		cout << "   _____  .__                _________                                          " << endl
			<< "  /     \\ |__| ____   ____  /   _____/_  _  __ ____   ____ ______   ___________ " << endl
			<< " /  \\ /  \\|  |/    \\_/ __ \\ \\_____  \\\\ \\/ \\/ // __ \\_/ __ \\\\____ \\_/ __ \\_  __ \\" << endl
			<< "/    Y    \\  |   |  \\  ___/ /        \\\\     /\\  ___/\\  ___/|  |_> >  ___/|  | \\/" << endl
			<< "\\____|__  /__|___|  /\\___  >_______  / \\/\\_/  \\___  >\\___  >   __/ \\___  >__|   " << endl
			<< "        \\/        \\/     \\/        \\/             \\/     \\/|__|        \\/       " << endl;

		printBoard(myBoard);
		cout << endl << "You lost!" << endl;
		return true;
	}
	else
	{
		int count = countAdjacentMines(row, col, mines, realBoard);
		(*movesLeft)--;

		myBoard[row][col] = count + '0';

		if (!count)
		{
			if (isValid(row - 1, col) == true)
			{
				if (isMine(row - 1, col, realBoard) == false)
					playMinesweeper(myBoard, realBoard, mines, row - 1, col, movesLeft);
			}

			if (isValid(row + 1, col) == true)
			{
				if (isMine(row + 1, col, realBoard) == false)
					playMinesweeper(myBoard, realBoard, mines, row - 1, col, movesLeft);
			}

			if (isValid(row, col + 1) == true)
			{
				if (isMine(row, col + 1, realBoard) == false)
					playMinesweeper(myBoard, realBoard, mines, row, col + 1, movesLeft);
			}

			if (isValid(row, col - 1) == true)
			{
				if (isMine(row, col - 1, realBoard) == false)
					playMinesweeper(myBoard, realBoard, mines, row, col - 1, movesLeft);
			}

			if (isValid(row - 1, col + 1) == true)
			{
				if (isMine(row - 1, col + 1, realBoard) == false)
					playMinesweeper(myBoard, realBoard, mines, row - 1, col + 1, movesLeft);
			}

			if (isValid(row - 1, col - 1) == true)
			{
				if (isMine(row - 1, col - 1, realBoard) == false)
					playMinesweeper(myBoard, realBoard, mines, row - 1, col - 1, movesLeft);
			}

			if (isValid(row + 1, col + 1) == true)
			{
				if (isMine(row + 1, col + 1, realBoard) == false)
					playMinesweeper(myBoard, realBoard, mines, row + 1, col + 1, movesLeft);
			}

			if (isValid(row + 1, col + 1) == true)
			{
				if (isMine(row + 1, col + 1, realBoard) == false)
					playMinesweeper(myBoard, realBoard, mines, row + 1, col + 1, movesLeft);
			}
		}

		return false;
	}
}

int Board::countAdjacentMines(int row, int col, int mines[][2], char realBoard[][MAXSIDE])
{
	int count = 0;

	if (isValid(row - 1, col) == true)
	{
		if (isMine(row - 1, col, realBoard) == true)
		{
			count++;
		}
	}

	if (isValid(row + 1, col) == true)
	{
		if (isMine(row + 1, col, realBoard) == true)
		{
			count++;
		}
	}

	if (isValid(row, col + 1) == true)
	{
		if (isMine(row, col + 1, realBoard) == true)
		{
			count++;
		}
	}

	if (isValid(row, col - 1) == true)
	{
		if (isMine(row, col - 1, realBoard) == true)
		{
			count++;
		}
	}

	if (isValid(row - 1, col + 1) == true)
	{
		if (isMine(row - 1, col + 1, realBoard) == true)
		{
			count++;
		}
	}

	if (isValid(row - 1, col - 1) == true)
	{
		if (isMine(row - 1, col - 1, realBoard) == true)
		{
			count++;
		}
	}

	if (isValid(row + 1, col + 1) == true)
	{
		if (isMine(row + 1, col + 1, realBoard) == true)
		{
			count++;
		}
	}

	if (isValid(row + 1, col - 1) == true)
	{
		if (isMine(row + 1, col - 1, realBoard) == true)
		{
			count++;
		}
	}

	return count;
}

void Board::play()
{
	while (gameOver == false)
	{
		system("CLS");
		cout << "   _____  .__                _________                                          " << endl
			<< "  /     \\ |__| ____   ____  /   _____/_  _  __ ____   ____ ______   ___________ " << endl
			<< " /  \\ /  \\|  |/    \\_/ __ \\ \\_____  \\\\ \\/ \\/ // __ \\_/ __ \\\\____ \\_/ __ \\_  __ \\" << endl
			<< "/    Y    \\  |   |  \\  ___/ /        \\\\     /\\  ___/\\  ___/|  |_> >  ___/|  | \\/" << endl
			<< "\\____|__  /__|___|  /\\___  >_______  / \\/\\_/  \\___  >\\___  >   __/ \\___  >__|   " << endl
			<< "        \\/        \\/     \\/        \\/             \\/     \\/|__|        \\/       " << endl;

		printBoard(myBoard);
		makeMove(&x, &y);

		if (currentMove == 0)
		{
			if (isMine(x, y, realBoard) == true)
			{
				replaceMine(x, y, realBoard);
			}
		}

		currentMove++;

		gameOver = playMinesweeper(myBoard, realBoard, mines, x, y, &movesLeft);

		if ((gameOver == false) && (movesLeft == 0))
		{
			cout << endl << "You lost !" << endl;
			gameOver = true;
		}
	}
}

Easy::Easy()
{
	sideLength = 9;
	numMines = 10;
	currentMove = 0;
	gameOver = false;
	movesLeft = sideLength * sideLength - numMines;
	init(realBoard, myBoard);
	placeMines(mines, realBoard);
}

Medium::Medium()
{
	sideLength = 16;
	numMines = 40;
	currentMove = 0;
	gameOver = false;
	movesLeft = sideLength * sideLength - numMines;
	init(realBoard, myBoard);
	placeMines(mines, realBoard);
}

Hard::Hard()
{
	sideLength = 24;
	numMines = 99;
	currentMove = 0;
	gameOver = false;
	movesLeft = sideLength * sideLength - numMines;
	init(realBoard, myBoard);
	placeMines(mines, realBoard);
}

Custom::Custom(int sideLength, int numMines)
{
	this->sideLength = sideLength;
	this->numMines = numMines;
	currentMove = 0;
	gameOver = false;
	movesLeft = sideLength * sideLength - numMines;
	init(realBoard, myBoard);
	placeMines(mines, realBoard);
}

#endif
