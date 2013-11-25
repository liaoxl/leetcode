/*
 * sort_colors.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int rc=0,wc=0,bc=0;
			for(int i=0; i<n; i++)
			{
				if(A[i]==0)
				{
					rc++;
				}
				else if(A[i]==1)
				{
					wc++;
				}
				else if(A[i]==2)
				{
					bc++;
				}
			}
			int cnt=0;
			for(int i=0; i<rc; i++)
			{
				A[cnt]=0;
				cnt++;
			}
			for(int i=0; i<wc; i++)
			{
				A[cnt]=1;
				cnt++;
			}
			for(int i=0; i<bc; i++)
			{
				A[cnt]=2;
				cnt++;
			}

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

