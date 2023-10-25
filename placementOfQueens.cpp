#include <iostream>
#include <vector>

using namespace std;

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
