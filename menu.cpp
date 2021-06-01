#ifndef MENU_CPP
#define MENU_CPP

#include "menu.h"
#include "board.h"

void outputTitle();
void customSettings(char &side, int& numMines, int& sideLength);

void menu()
{
	char choice;
	char difficulty;
	bool reset;
	bool diffreset;

	do
	{
		reset = false;
		system("CLS");

		outputTitle();

		cout << endl;

		cout << setw(48)
			<< "[  New Game(N)  ]" << endl << endl
			<< setw(48)
			<< "[ Resume Game(R)]" << endl << endl
			<< setw(48)
			<< "[  Exit Game(E) ]" << endl << endl
			<< setw(49)
			<< "Enter your choice: ";

		cin >> choice;
		choice = toupper(choice);

		switch (choice)
		{
		case 'N':
			do
			{
				diffreset = false;
				system("CLS");

				outputTitle();

				cout << endl;

				cout << setw(48)
					<< "[    Easy(E)    ]" << endl << endl
					<< setw(48)
					<< "[   Medium(M)   ]" << endl << endl
					<< setw(48)
					<< "[    Hard(H)    ]" << endl << endl
					<< setw(48)
					<< "[   Custom(C)   ]" << endl << endl
					<< setw(48)
					<< "[    Back(B)    ]" << endl << endl
					<< setw(50)
					<< "Select a difficulty: ";

				cin >> difficulty;
				difficulty = toupper(difficulty);

				switch (difficulty)
				{
				case 'E':
				{
					Easy* easy = new Easy();
					easy->play();
				}
					break;
				case 'M':
				{
					Medium* medium = new Medium();
					medium->play();
				}
					break;
				case 'H':
				{
					Hard* hard = new Hard();
					hard->play();
				}
					break;
				case 'C':
				{
					char side;
					int numMines;
					int sideLength;

					customSettings(side, numMines, sideLength);

					if (side == 'B')
					{
						diffreset = true;
					}
					else
					{
						Custom* custom = new Custom(sideLength, numMines);
						custom->play();
					}
				}
					break;
				case 'B':
					reset = true;
					break;
				default:
					diffreset = true;
				}
			} while (diffreset == true);
			break;
		case 'R':
			break;
		case 'H':
			break;
		case 'E':
			break;
		default:
			reset = true;
		}
	} while (reset == true);
}

void outputTitle()
{
	cout << "   _____  .__                _________                                          " << endl
		<< "  /     \\ |__| ____   ____  /   _____/_  _  __ ____   ____ ______   ___________ " << endl
		<< " /  \\ /  \\|  |/    \\_/ __ \\ \\_____  \\\\ \\/ \\/ // __ \\_/ __ \\\\____ \\_/ __ \\_  __ \\" << endl
		<< "/    Y    \\  |   |  \\  ___/ /        \\\\     /\\  ___/\\  ___/|  |_> >  ___/|  | \\/" << endl
		<< "\\____|__  /__|___|  /\\___  >_______  / \\/\\_/  \\___  >\\___  >   __/ \\___  >__|   " << endl
		<< "        \\/        \\/     \\/        \\/             \\/     \\/|__|        \\/       " << endl;
}

void customSettings(char& side, int& numMines, int& sideLength)
{
	bool reset;
	
	do
	{
		reset = false;
		system("CLS");

		outputTitle();

		cout << endl;

		cout << setw(48)
			<< "[    Back(B)    ]" << endl << endl 
			<< setw(56)
			<< "Enter side length (1-30): ";
		cin >> side;

		side = toupper(side);

		if (side == 'B')
		{
			return;
		}

		if ((side - '0' >= 1) && (side - '0' <= 30))
		{
			sideLength = side - '0';
			cout << endl
				<< setw(57)
				<< "Enter number of mines (1-200): ";
			cin >> numMines;
		}
		else
		{
			reset = true;
		}

		if ((numMines < 1) || (numMines > 200) || (numMines > (sideLength * sideLength)))
		{
			reset = true;
		}
		
	} while (reset == true);
}

#endif
