#pragma once

#include <vector>

using namespace std;

void placeQueens(int, int, vector<int>&, vector<vector<int>>&);
void startPlaceQueens();
int check(int, int, vector<int>&);
void printResult(int, vector<vector<int>>&);
