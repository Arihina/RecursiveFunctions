#include <iostream>
#include <format>
#include <vector>
#include <string>

using namespace std;


int findMaxElem(int[], int, int, 
	vector<string>&, vector<string>&);
void startFindMaxElem();
void printArray(int[], int);
void fillArray(int[], int, int);

void hanoiTowers(int, int start = 1, int end = 3);
void startHanoiTowers();

int main()
{
	startFindMaxElem();

	startHanoiTowers();
}


int findMaxElem(int arr[], int left, int right, 
	vector<string>& callStack1, vector<string>& callStack2) {

    int middle, firstPart, secondPart;
	string rec;

	if (left == right)
	{	
		return arr[left];
	}

	middle = (left + right) / 2;

	firstPart = findMaxElem(arr, left, middle,
		callStack1, callStack2);

	rec = "left = " + to_string(left) + " right = " + to_string(right);
	callStack1.push_back(rec);

	secondPart = findMaxElem(arr, middle + 1, right, 
		callStack1, callStack2);

	rec = "left = " + to_string(left) + " right = " + to_string(right);
	callStack2.push_back(rec);

	if (firstPart > secondPart)
	{
		rec = to_string(firstPart) + " > " + to_string(secondPart) + " return firstPart = " + to_string(firstPart);
		callStack1.push_back(rec);

		return firstPart;
	}
	else
	{
		rec = to_string(secondPart) + " > " + to_string(firstPart) + " return secondPart = " + to_string(secondPart);
		callStack2.push_back(rec);
		
		return secondPart;
	}
}


void fillArray(int arr[], int size, int range) {

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % range;
	}
}


void printArray(int arr[], int size) {

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


void startFindMaxElem() {

	cout << "Recursive search max elem in array" << endl << endl;
	
	int size;
	cout << "Enter a size of array ";
	cin >> size;
	int *arr = new int[size];
	int range;
	cout << "Enter a range of values ";
	cin >> range;
	cout << endl;

	fillArray(arr, size, range);
	cout << "Array:" << endl;
	printArray(arr, size);
	cout << endl;

	vector<string> callStack1, callStack2;


	int maxElem = findMaxElem(arr, 0, size - 1,
		callStack1, callStack2);


	cout << "first stack" << endl;
	cout << "\tcalling for firstPart in range: " << endl;
	for (string str : callStack1)
	{
		cout << "\t\t" << str << endl;
	}

	cout << endl;

	cout << "second stack" << endl;
	cout << "\tcalling for secondPart in range: " << endl;
	for (string str : callStack2)
	{
		cout << "\t\t" << str << endl;
	}

	cout << endl;
	cout << "max elem = " << maxElem << endl;
}


void hanoiTowers(int n, int start, int end) {

	if (n <= 0)
	{
		return;
	}

	int temp = 6 - start - end;
	hanoiTowers(n-1, start, temp);
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
		cout << "Default value\n"<<
			"\t start = 1 kernel\n" <<
			"\t end = 3 kernel";

		cout << endl;
		hanoiTowers(countDisk);

	}
	else
	{
		cout << "Invalid input, set default value\n" <<
			"\t start = 1 kernel\n" <<
			"\t end = 3 kernel";

		cout << endl;
		hanoiTowers(countDisk);
	}

}