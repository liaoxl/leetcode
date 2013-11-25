/*
 * maximum_subarray.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131124/leetcode-maximum-subarray/
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        	int maxs=-100000;
			int tmpsum=0;
			for(int i=0; i<n; i++)
			{
				tmpsum+=A[i];
				if(tmpsum > maxs)
				{
					maxs=tmpsum;
				}
				if(tmpsum<0)
				{
					tmpsum=0;
				}
			}
			return maxs;

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

