/*
 * spiral_matrix.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> res;
    void dfs(int cm, int cn, int m, int n, vector<vector<int> > d)
    {
        if(m<=0 || n<=0) return;
        if(m==1)
        {
            for(int i=0; i<n; i++)
            {
                res.push_back(d[cm][cn+i]);
            }
            return;
        }
        if(n==1)
        {
            for(int i=0; i<m; i++)
            {
                res.push_back(d[cm+i][cn]);
            }
            return;
        }
        // left->right
        for(int i=0; i<n-1; i++)
        {
            res.push_back(d[cm][cn+i]);
        }
        //up->down
        for(int i=0; i<m-1; i++)
        {
            res.push_back(d[cm+i][cn+n-1]);
        }
        //right->left
        for(int i=n-1; i>0; i--)
        {
            res.push_back(d[cm+m-1][cn+i]);
        }
        //down->up
        for(int i=m-1; i>0; i--)
        {
            res.push_back(d[cm+i][cn]);
        }
        dfs(cm+1,cn+1, m-2,n-2, d);
    }

    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        res.clear();
        int m=matrix.size();
        if(!m) return res;
        int n=matrix[0].size();
        dfs(0,0,m,n,matrix);
        return res;
    }
};


int main(int argc, char* argv[])
{
	
	return 0;
}

