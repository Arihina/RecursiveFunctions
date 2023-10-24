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

int moveKnight(int, int, int, int, int,
	int[], int[], int**);
void startMoveKnight();
void printBoard(int**, int);

void startPlaceQueens();
int check(int, int, vector<int>&);
void placeQueens(int, int, vector<int>&, vector<vector<int>>&);
void printResult(int, vector<vector<int>>&);


int main()
{
	//startFindMaxElem();

	//startHanoiTowers();

	//startMoveKnight();

	startPlaceQueens();
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

	delete[] arr;
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


void printBoard(int**board, int size) {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void startMoveKnight() {

	cout << "the movement of the knight on the board through recursion" << endl << endl;

	int setMovesX[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int setMovesY[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	int size;
	cout << "Enter count of cells on board ";
	cin >> size;

	int** board = new int*[size];
	for (int i = 0; i < size; i++)
	{
		board[i] = new int[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			board[i][j] = 0;
		}
	}

	int startX, startY;
	cout << "Enter start possition" << endl;
	cout << "x: "; cin >> startX;
	cout << "y: "; cin >> startY;

	board[startX][startY] = 1;
	if (moveKnight(2, startX, startY, size, 8, setMovesX, setMovesY, board))
	{
		printBoard(board, size);
	} 
	else {
		cout << "no solutions for this possition" << endl;
	}

	for (int i = 0; i < size; i++)
	{
		delete[] board[i];
	}
	delete[] board;
}

int moveKnight(int i, int xPos, int yPos, int sizeBoard, int countSteps,
	int setMovesX[], int setMovesY[], int** board) {

	int nextX, nextY, indexInMoves = 0, q = 0;

	while (q == 0 && indexInMoves < countSteps)
	{
		nextX = xPos + setMovesX[indexInMoves];
		nextY = yPos + setMovesY[indexInMoves];
		indexInMoves++;
		if (nextX >= 0 && nextX < sizeBoard &&
			nextY >= 0 && nextY < sizeBoard)
		{
			if (board[nextX][nextY] == 0)
			{
				board[nextX][nextY] = i;
				cout << "next move this x = " << nextX << " y = " << nextY << endl;
				printBoard(board, sizeBoard);
				cout << endl;
				int check = moveKnight(i + 1, nextX, nextY, sizeBoard, 8,
					setMovesX, setMovesY, board);
				if (i < sizeBoard * sizeBoard && check == 0)
				{
					board[nextX][nextY] = 0;
					cout << "canceling a move with x = " << nextX << " y = " << nextY << endl;
					printBoard(board, sizeBoard);
					cout << endl;
				}
				else {
					q = 1;
				}
			}
		}
	}
	return q;
}


void printResult(int size, vector<int>& result) {

	vector<vector<int>> matrixBoard;
	for (int i = 0; i < size; i++)
	{
		vector<int> temp;
		for (int j = 0; j < size; j++)
		{
			temp.push_back(0);
		}
		matrixBoard.push_back(temp);
	}

	for (int i = 0; i < size; i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		matrixBoard[i][result[i]] = 1;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << matrixBoard[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void startPlaceQueens() {

	cout << "recursive placement of disjoint queens" << endl << endl;

	vector<vector<int>> results;
	int size;
	cout << "Enter size of board ";
	cin >> size;
	vector<int> board(size);
	for (int i = 0; i < size; i++)
	{
		board[i] = -1;
	}

	placeQueens(size, 0, board, results);

	cout << "Print all results? y/n ";
	char userAnswer;
	cin >> userAnswer;
	if (userAnswer == 'y')
	{
		for (int i = 0; i < results.size(); i++)
		{
			printResult(size, results[i]);
		}
	}
	else if (userAnswer == 'n')
	{
		cout << "Print last result" << endl;
		printResult(size, results[results.size() - 1]);
	}
	else
	{
		cout << "Invalid input" << endl;
	}
}

int check(int row, int column, vector<int>& board) {

	for (int i = 0; i < row; i++)
	{
		if (board[i] == column || board[i] - i == column - row ||
			board[i] + i == column + row)
		{
			return 0;
		}
	}
	return 1;
}

void placeQueens(int size, int row, vector<int>& board, vector<vector<int>>& results) {

	if (row == size) 
	{
		results.push_back(board);
		return;
	}

	for (int i = 0; i < size; i++)
	{
		if (check(row, i, board))
		{
			board[row] = i;

			cout << "Queen place on " << row << " position" << endl;
			for (int i = 0; i < board.size(); i++)
			{
				cout << board[i] << " ";
			}
			cout << endl;

			placeQueens(size, row + 1, board, results);

			board[row] = -1;

			cout << "Queen delete from" << row << " position" << endl;
			for (int i = 0; i < board.size(); i++)
			{
				cout << board[i] << " ";
			}
			cout << endl;
		}
	}
}