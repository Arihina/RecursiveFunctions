#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "findingMaximumElemArray.h"
#include "hanoiTowers.h"
#include "moveOfKnight.h"
#include "placementOfQueens.h"

using namespace std;

typedef void(*func) ();

int main()
{
	map<char, func> functions{
		{'1', startFindMaxElem},
		{'2', startHanoiTowers},
		{'3', startMoveKnight},
		{'4', startPlaceQueens}
	};
	
	char userInput;
	while (true) {

		cout << "Select a function" << endl;
		cout << "Find max elem in array - 1" << endl;
		cout << "Hanoi towers - 2 " << endl;
		cout << "Move of knight - 3" << endl;
		cout << "Place Queens - 4" << endl;
		cout << "Exit - 0" << endl;

		cin >> userInput;
		cout << endl;

		if (userInput == '0')
		{
			cout << "Exit" << endl;
			break;
		}
		else if (userInput != '1' && userInput != '2' && userInput != '3' && userInput != '4')
		{
			cout << "Invalid input" << endl;
			cout << endl;
			continue;
		}

		try
		{
			functions[userInput]();
			cout << endl;
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
		}
	}
}
