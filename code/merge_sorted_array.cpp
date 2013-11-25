/*
 * merge_sorted_array.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n==0)
        {
            return;
        }
        if(m==0)
        {
            for(int i=0; i<n; i++)
            {
                A[i]=B[i];
            }
            return;
        }
        int* t=new int[m];
        for(int i=0; i<m; i++)
        {
            t[i]=A[i];
        }
        int ind=0;
        int aid=0,bid=0;
        while(ind<m+n)
        {
            if(aid<m && t[aid]<=B[bid])
            {
                A[ind]=t[aid];
                ind++;
                aid++;
                continue;
            }
            else if(bid<n && t[aid]>B[bid])
            {
                A[ind]=B[bid];
                ind++;
                bid++;
                continue;
            }
            else if(aid==m)
            {
                A[ind]=B[bid];
                ind++;
                bid++;
                continue;
            }
            else if(bid=n)
            {
                A[ind]=t[aid];
                ind++;
                aid++;
                continue;
            }
        }
        delete [] t;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

