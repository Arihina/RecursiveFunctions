#include <iostream>

using namespace std;

void printBoard(int** board, int size) {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
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

void startMoveKnight() {

	cout << "the movement of the knight on the board through recursion" << endl << endl;

	int setMovesX[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int setMovesY[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	int size;
	cout << "Enter count of cells on board ";
	cin >> size;

	int** board = new int* [size];
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
		cout << "The final location of the moves" << endl;
		cout << endl;
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

