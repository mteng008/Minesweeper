#ifndef MENU_CPP
#define MENU_CPP

#include "menu.h"
#include "board.h"

void outputTitle();
void customSettings(int& sideLength, int& numMines, bool& isB);

void menu()
{
	char choice;
	char difficulty;
	bool reset;
	bool diffreset;

	do
	{
		reset = false;
		system("clear");

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
				system("clear");

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
					delete easy;
				}
					break;
				case 'M':
				{
					Medium* medium = new Medium();
					medium->play();
					delete medium;
				}
					break;
				case 'H':
				{
					Hard* hard = new Hard();
					hard->play();
					delete hard;
				}
					break;
				case 'C':
				{
					int numMines = 0;
					int sideLength = 0;
					bool isB = false;

					customSettings(sideLength, numMines, isB);
					if (isB == false)
					{
						Custom* custom = new Custom(sideLength, numMines);
						custom->play();
						delete custom;
					}
					else
					{
						diffreset = true;
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

void customSettings(int& sideLength, int& numMines, bool& isB)
{
	bool reset = true;
	bool sideChosen = false;
	bool minesChosen = false;
	char choice;
	
	do
	{
		system("clear");

		outputTitle();

		cout << endl;

		cout << setw(48)
			<< "[    Side(S)    ]" << endl << endl
			<< setw(48)
			<< "[    Mines(M)   ]" << endl << endl
			<< setw(48)
			<< "[    Back(B)    ]" << endl << endl
			<< setw(49)
			<< "Enter your choice: ";

		cin >> choice;
		choice = toupper(choice);

		switch (choice)
		{
		case 'S':
			do
			{
				sideChosen = false;
				system("clear");

				outputTitle();

				cout << endl;

				cout << setw(48)
					<< "[    Side(S)    ]" << endl << endl
					<< setw(48)
					<< "[    Mines(M)   ]" << endl << endl
					<< setw(48)
					<< "[    Back(B)    ]" << endl << endl
					<< setw(56)
					<< "Enter side length (1-30): ";

				cin >> sideLength;

				if (sideLength >= 1 && sideLength <= 30)
				{
					sideChosen = true;
				}
			} while (sideChosen == false);

			break;
		case 'M':
			do
			{
				minesChosen = false;
				system("clear");

				outputTitle();

				cout << endl;

				cout << setw(48)
					<< "[    Side(S)    ]" << endl << endl
					<< setw(48)
					<< "[    Mines(M)   ]" << endl << endl
					<< setw(48)
					<< "[    Back(B)    ]" << endl << endl
					<< setw(56)
					<< "Enter mine count (1-200): ";

				cin >> numMines;

				if (numMines >= 1 && numMines <= 200)
				{
					minesChosen = true;

				}
			} while (minesChosen == false);
			
			break;
		case 'B' :
			isB = true;
			return;
			break;
		default:
			reset = true;
		}

		if (sideChosen == true && minesChosen == true)
		{
			reset = false;
		}
		
		
	} while (reset == true);
}

#endif
