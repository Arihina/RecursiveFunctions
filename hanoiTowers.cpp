#include <iostream>

using namespace std;

void hanoiTowers(int n, int start, int end) {

	if (n <= 0)
	{
		return;
	}

	int temp = 6 - start - end;
	hanoiTowers(n - 1, start, temp);
	cout << "put disk " << n << " from kernel " << start << " on kernel " << end << endl;
	hanoiTowers(n - 1, temp, end);
}

void startHanoiTowers() {

	cout << "Recursive rearranging disks in the Hanoi tower" << endl << endl;

	cout << "Enter number of disks ";
	int countDisk;
	cin >> countDisk;

	cout << "\nEnter start and end kernel? y/n  ";
	char answer;
	cin >> answer;

	if (answer == 'y')
	{
		int start, end;
		cout << "Enter start kernel ";
		cin >> start;

		cout << "Enter end kernel ";
		cin >> end;

		cout << endl;
		hanoiTowers(countDisk, start, end);
	}
	else if (answer == 'n')
	{
		cout << "Default value\n" <<
			"\t start = 1 kernel\n" <<
			"\t end = 3 kernel";

		cout << endl;
		hanoiTowers(countDisk, 1, 3);

	}
	else
	{
		cout << "Invalid input, set default value\n" <<
			"\t start = 1 kernel\n" <<
			"\t end = 3 kernel";

		cout << endl;
		hanoiTowers(countDisk, 1, 3);
	}

}