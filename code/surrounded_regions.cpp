/*
 * surrounded_regions.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int cm, int cn, int m, int n, vector<vector<char> > &board)
    {
        if(cm>=m || cm<0 || cn>=n || cn<0 || board[cm][cn]!='O') return;
        board[cm][cn]='#';
        dfs(cm-1,cn,m,n,board);
        dfs(cm+1,cn,m,n,board);
        dfs(cm,cn-1,m,n,board);
        dfs(cm,cn+1,m,n,board);
    }

    void solve(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m=board.size();
        if(m==0) return;
        int n=board[0].size();
        if(n==0) return;
        for(int i=0; i<m; i++)
        {
            if(board[i][0]=='O')
            {
                dfs(i,0,m,n,board);
            }
        }
        for(int i=0; i<n; i++)
        {
            if(board[0][i]=='O')
            {
                dfs(0,i,m,n,board);
            }
        }
        for(int i=0; i<m; i++)
        {
            if(board[i][n-1]=='O')
            {
                dfs(i,n-1,m,n,board);
            }
        }
        for(int i=0; i<n; i++)
        {
            if(board[m-1][i]=='O')
            {
                dfs(m-1,i,m,n,board);
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j]=='O') board[i][j]='X';
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j]=='#') board[i][j]='O';
            }
        }
        return;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

