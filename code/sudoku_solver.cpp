/*
 * sudoku_solver.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131124/leetcode-ss/
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	bool isValid(vector<vector<char> > &board, int x, int y)
	{
		int i, j;
		for (i = 0; i < 9; i++)
			if (i != x && board[i][y] == board[x][y])
				return false;
		for (j = 0; j < 9; j++)
			if (j != y && board[x][j] == board[x][y])
				return false;
		for (i = 3 * (x / 3); i < 3 * (x / 3 + 1); i++)
			for (j = 3 * (y / 3); j < 3 * (y / 3 + 1); j++)
				if (i != x && j != y && board[i][j] == board[x][y])
					return false;
		return true;
	}
	bool solveSudoku(vector<vector<char> > &board)
	{
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
			{
				if ('.' == board[i][j])
				{
					for (int k = 1; k <= 9; ++k)
					{
						board[i][j] = '0' + k;
						if (isValid(board, i, j) && solveSudoku(board))
							return true;
						board[i][j] = '.';
					}
					return false;
				}
			}
		return true;
	}
};

int main(int argc, char* argv[])
{
	
	return 0;
}

