/*
 * minimum_path_sum.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        	int m=grid.size();
			if(m==0)
			{
				return 0;
			}
			int n=grid[0].size();
			if(n==0)
			{
				return 0;
			}
			int **p=new int*[m];
			for(int i=0; i<m; i++)
			{
				p[i]=new int[n];
			}
			for(int i=0; i<m; i++)
			{
			    for(int j=0; j<n; j++)
			    {
			        p[i][j]=0;
			    }
			}
			p[0][0]=grid[0][0];
			for(int i=1; i<n; i++)
			{
				p[0][i]+=p[0][i-1]+grid[0][i];
			}
			for(int i=1; i<m; i++)
			{
				p[i][0]+=p[i-1][0]+grid[i][0];
			}

			for(int i=1; i<m; i++)
			{
				for(int j=1; j<n; j++)
				{
					p[i][j]=min(p[i-1][j], p[i][j-1])+grid[i][j];
				}
			}
			int res=p[m-1][n-1];
			for(int i=0; i<m; i++)
			{
				delete [] p[i];
			}
			delete [] p;
			return res;

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

