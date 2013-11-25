/*
 * spiral_matrix2.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int num;
    void dfs(int cm, int cn, int m, int n, vector<vector<int> > &d)
    {
        if(m<=0 || n<=0) return;
        if(m==1)
        {
            for(int i=0; i<n; i++)
            {
                d[cm][cn+i]=num++;
            }
            return;
        }
        if(n==1)
        {
            for(int i=0; i<m; i++)
            {
                d[cm+i][cn]=num++;
            }
            return;
        }
        // left->right
        for(int i=0; i<n-1; i++)
        {
            d[cm][cn+i]=num++;
        }
        //up->down
        for(int i=0; i<m-1; i++)
        {
            d[cm+i][cn+n-1]=num++;
        }
        //right->left
        for(int i=n-1; i>0; i--)
        {
            d[cm+m-1][cn+i]=num++;
        }
        //down->up
        for(int i=m-1; i>0; i--)
        {
            d[cm+i][cn]=num++;
        }
        dfs(cm+1,cn+1, m-2,n-2, d);
    }

    vector<vector<int> > generateMatrix(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> tmp(n,0);
        vector<vector<int> > res(n,tmp);
        num=1;
        dfs(0,0,n,n,res);
        return res;
    }
};


int main(int argc, char* argv[])
{
	
	return 0;
}

