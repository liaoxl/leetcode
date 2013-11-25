/*
 * remove_element.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131123/leetcode-re/
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        	for(int i=0; i<n; i++)
			{
				if(A[i]==elem)
				{
					A[i]=A[n-1];
					i--;
					n=n-1;
				}
			}
			return n;

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

