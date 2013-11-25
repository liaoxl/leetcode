/*
 * first_missing_positive.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131124/leetcode-fmp/
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        	for(int i=0; i<n; i++)
			{
				if(A[i]<1 || A[i]>n)
				{
					A[i]=0;
				}
				else if(A[A[i]-1]!=A[i])
				{
					int tmp=A[A[i]-1];
					A[A[i]-1]=A[i];
					A[i]=tmp;
					i--;
				}
			}
			for(int i=0; i<n; i++)
			{
				if(A[i]!=i+1)
				{
					return i+1;
				}
			}
			return n+1;

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

