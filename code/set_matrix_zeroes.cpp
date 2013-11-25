/*
 * set_matrix_zeroes.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        			int m=matrix.size();
			if(m==0)
			{
				return;
			}
			int n=matrix[0].size();
			if(n==0)
			{
				return;
			}
			bool isfirstrow_zero=false;
			bool isfirstcol_zero=false;

			for(int i=0; i<n; i++)
			{
				if(matrix[0][i]==0)
				{
					isfirstrow_zero=true;
					break;
				}
			}

			for(int i=0; i<m; i++)
			{
				if(matrix[i][0]==0)
				{
					isfirstcol_zero=true;
					break;
				}
			}

			for(int i=1; i<m; i++)
			{
				for(int j=1; j<n; j++)
				{
					if(matrix[i][j]==0)
					{
						matrix[0][j]=0;
						matrix[i][0]=0;
					}
				}
			}

			for(int i=1; i<m; i++)
			{
				for(int j=1; j<n; j++)
				{
					if(matrix[0][j]==0 || matrix[i][0]==0)
					{
						matrix[i][j]=0;
					}
				}
			}

			if(isfirstrow_zero)
			{
				for(int i=0; i<n; i++)
				{
					matrix[0][i]=0;
				}
			}
			if(isfirstcol_zero)
			{
				for(int i=0; i<m; i++)
				{
					matrix[i][0]=0;
				}
			}
			return;

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

