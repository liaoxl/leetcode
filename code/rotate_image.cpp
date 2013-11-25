/*
 * rotate_image.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
       			vector<vector<int> > tmp;
			int n=matrix.size();
			tmp.resize(n);
			for(int i=0; i<n; i++)
			{
				tmp[i].resize(n);
			}
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
				{
					tmp[i][j]=matrix[n-j-1][i];
				}
			}
			matrix=tmp;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

