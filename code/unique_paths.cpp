/*
 * unique_paths.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return cmn(m-1, m+n-2);
    }
    int cmn(int m, int n)
		{
			double res=1;
			for(int i=1; i<=m; i++)
			{
				res *=(double)(n-m+i)/(double)i;
			}
			return res;
		}
};

int main(int argc, char* argv[])
{
	
	return 0;
}

