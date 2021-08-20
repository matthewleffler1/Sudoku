#pragma once
#include <vector>

using namespace std;

#define BOARD_SIZE	9

class Sudoku
{
public:
	Sudoku();
	vector<vector<int>> getInitialBoard();
	int getNumSolutions();
	vector<vector<vector<int>>> getSolutions();
	bool checkValid(int row, int col, int value, vector<vector<int>> board);
	bool checkRow(int row, int col, int value, vector<vector<int>> board);
	bool checkCol(int row, int col, int value, vector<vector<int>> board);
	bool checkBox(int row, int col, int value, vector<vector<int>> board);
	bool insertToInitialBoard(int row, int col, int value);
	bool solvableBoard();
	bool solvableBoardHelper(vector<vector<int>> board);

private:
	vector<vector<int>> initialBoard;
	vector<vector<vector<int>>> finalBoard;
	bool insert(int row, int col, int value, vector<vector<int>>& board);
};