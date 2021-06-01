#ifndef MENU_CPP
#define MENU_CPP

#include "menu.h"
#include "board.h"
#include "boardfactory.h"

void outputTitle();

void menu()
{
	char choice;
	char mode;
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

				cin >> mode;
				mode = toupper(mode);

				BoardFactory* select = new BoardFactory();

				Board* game = select->difficulty(mode, reset, diffreset);
				if (game != nullptr)
				{
					game->play();
					delete game;
				}

				delete select;
			} while (diffreset == true);
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

#endif
