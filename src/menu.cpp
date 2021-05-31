#ifndef MENU_CPP
#define MENU_CPP

#include "../header/menu.h"

void menu()
{
	char choice;
	char difficulty;
	bool reset = false;
	bool diffreset = false;
	bool invalid = false;

	do
	{
		reset = false;
		system("CLS");

		cout << "   _____  .__                _________                                          " << endl
			<< "  /     \\ |__| ____   ____  /   _____/_  _  __ ____   ____ ______   ___________ " << endl
			<< " /  \\ /  \\|  |/    \\_/ __ \\ \\_____  \\\\ \\/ \\/ // __ \\_/ __ \\\\____ \\_/ __ \\_  __ \\" << endl
			<< "/    Y    \\  |   |  \\  ___/ /        \\\\     /\\  ___/\\  ___/|  |_> >  ___/|  | \\/" << endl
			<< "\\____|__  /__|___|  /\\___  >_______  / \\/\\_/  \\___  >\\___  >   __/ \\___  >__|   " << endl
			<< "        \\/        \\/     \\/        \\/             \\/     \\/|__|        \\/       " << endl;

		if (invalid == true)
		{
			cout << "Invalid input." << endl;
			invalid = false;
		}
		else
		{
			cout << endl;
		}

		cout << setw(48)
			<< "[  New Game(N)  ]" << endl << endl
			<< setw(48)
			<< "[ Resume Game(R)]" << endl << endl
			<< setw(48)
			<< "[ High Scores(H)]" << endl << endl
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

				if (invalid == true)
				{
					cout << "Invalid input." << endl;
					invalid = false;
				}
				else
				{
					cout << endl;
				}

				cout << setw(48)
					<< "[    Easy(E)    ]" << endl << endl
					<< setw(48)
					<< "[   Medium(M)   ]" << endl << endl
					<< setw(48)
					<< "[    Hard(H)    ]" << endl << endl
					<< setw(48)
					<< "[    Back(B)    ]" << endl << endl
					<< setw(50)
					<< "Select a difficulty: ";

				cin >> difficulty;
				difficulty = toupper(difficulty);

				switch (difficulty)
				{
				case 'E':
					break;
				case 'M':
					break;
				case 'H':
					break;
				case 'B':
					reset = true;
					break;
				default:
					diffreset = true;
					invalid = true;
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
			invalid = true;
		}
	} while (reset == true);
}

#endif
