#include <iostream>
#include <vector>
#include <string>

using namespace std;

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
	int* arr = new int[size];
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

	delete[] arr;
}