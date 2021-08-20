#include "Sudoku.h"

//Initialize Sudoku boards to be empty in constructor
Sudoku::Sudoku()
{
	initialBoard = vector<vector<int>>(BOARD_SIZE, vector<int>(BOARD_SIZE, 0));
	finalBoard = vector<vector<vector<int>>>();
}


vector<vector<int>> Sudoku::getInitialBoard()
{
	return initialBoard;
}

int Sudoku::getNumSolutions()
{
	return finalBoard.size();
}

vector<vector<vector<int>>> Sudoku::getSolutions()
{
	return finalBoard;
}

bool Sudoku::checkValid(int row, int col, int value, vector<vector<int>> board)
{
	return (checkRow(row, col, value, board) 
			 && checkCol(row, col, value, board)
			 && checkBox(row, col, value, board));
}

bool Sudoku::checkRow(int row, int col, int value, vector<vector<int>> board)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (i == row)
			continue;
		else if (board[i][col] == value)
			return false;
	}

	return true;
}

bool Sudoku::checkCol(int row, int col, int value, vector<vector<int>> board)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (i == col)
			continue;
		else if (board[row][i] == value)
			return false;
	}

	return true;
}

bool Sudoku::checkBox(int row, int col, int value, vector<vector<int>> board)
{
	int horizontalQuad = row - (row % 3);
	int verticalQuad = col - (col % 3);

	for (int i = horizontalQuad; i < horizontalQuad + 3; i++)
	{
		for (int j = verticalQuad; j < verticalQuad + 3; j++)
		{
			if (i == row && j == col)
				continue;
			if (board[i][j] == value)
				return false;
		}
	}

	return true;
}

bool Sudoku::insertToInitialBoard(int row, int col, int value)
{
	if (insert(row, col, value, initialBoard))
		return true;

	return false;
}

bool Sudoku::insert(int row, int col, int value, vector<vector<int>>& board)
{
	if (checkValid(row, col, value, board))
	{
		board[row][col] = value;
		return true;
	}

	return false;
}

bool Sudoku::solvableBoard()
{
	vector<vector<int>> tempBoard = initialBoard;
	solvableBoardHelper(tempBoard);

	return false;
}

bool Sudoku::solvableBoardHelper(vector<vector<int>> board)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j] == 0)
			{
				for (int k = 0; k < BOARD_SIZE; k++)
				{
					if (this->getNumSolutions() == 3)
						return false;
					if (insert(i, j, k + 1, board))
					{
						//TODO: Re-appending the same sodoku solution every time
						if (solvableBoardHelper(board))
							continue;
					}
					else if (k + 1 == BOARD_SIZE)
						return false;
				}
			}
		}
	}

	finalBoard.push_back(board);
	return true;
}
