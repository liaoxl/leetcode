/*
 * trapping_rain_water.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131124/leetcode-trw/
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        	if(n<=1) return 0;
			int left=0;
			int sum=0;
			int maxid=0;
			for(int i=1; i<n; i++)
			{
				if(A[i]>A[maxid]) maxid=i;
			}
			for(int i=1; i<maxid; i++)
			{
				if(A[i]<A[left])
				{
					sum+=A[left]-A[i];
				}
				else
				{
					left=i;
				}
			}
			int right=n-1;
			for(int i=n-2; i>maxid; i--)
			{
				if(A[i]<A[right]) sum+=A[right]-A[i];
				else right =i;
			}
			return sum;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

