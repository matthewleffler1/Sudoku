#include <iostream>
#include <vector>
#include "Sudoku.h";

using namespace std;

void print(vector<vector<int>> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}

	cout << endl;
}

int main()
{
	Sudoku s;

	s.insertToInitialBoard(0, 0, 5);
	s.insertToInitialBoard(3, 0, 8);

	s.solvableBoard();
	
	print(s.getSolutions()[0]);

	cout << endl << endl;

	print(s.getSolutions()[1]);

	return 0;
}