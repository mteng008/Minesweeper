#ifndef BOARDFACTORY_H
#define BOARDFACTORY_H
#include "board.h"

class BoardFactory
{
private:
	char mode;
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
			case 'B':
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
public:
	BoardFactory(){}
	~BoardFactory() {}
	Board* difficulty(char mode, bool& reset, bool &diffreset)
	{
		switch (mode)
		{
		case 'E':
		{
			return new Easy();
		}
		break;
		case 'M':
		{
			return new Medium();
		}
		break;
		case 'H':
		{
			return new Hard();
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
				return new Custom(sideLength, numMines);
			}
			else
			{
				diffreset = true;
				return nullptr;
			}
		}
		break;
		case 'B':
			reset = true;
			return nullptr;
			break;
		default:
			diffreset = true;
			return nullptr;
		}
	}
};

#endif
