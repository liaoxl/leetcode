/*
 * word_search.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool find(vector< vector<char> > &board, int i, int j, string &word, int idx)
    {
        if (idx == word.size()) return true;
        if (i < board.size() && j < board[i].size()
        && i >= 0 && j >= 0 && board[i][j] == word[idx])
        {
            board[i][j] = '#';
            ++idx;
            bool res=find(board, i+1, j, word, idx)||find(board, i-1, j, word, idx)||find(board, i, j-1, word, idx)||find(board, i, j+1, word, idx);
            board[i][j]=word[idx-1];
            return res;
        }
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] == word[0])
                {
                    vector<vector<char> > tmp (board);
                    bool result = find(tmp, i, j, word, 0);
                    if (result) return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

