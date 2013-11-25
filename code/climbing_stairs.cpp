/*
 * climbing_stairs.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        	int res=0;
			for(int i=1; 2*i<n; i++)
			{
				res += cmn(i, n-i);
			}
			if(n%2==0) res+=2;
			else res+=1;
			return res;
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

