/*
 * median_of_two_sorted_arrays.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

double findk(int A[], int m, int B[], int n, int k)
{
	if(m > n)
	{
		return findk(B,n,A,m,k);
	}
	if(m==0)
	{
		return B[k-1];
	}
	if(k==1)
	{
		return min(A[0],B[0]);
	}
	int pal=min(k/2, m);
	int res=k-pal;

	if(A[pal-1] == B[res-1])
	{
		return A[pal-1];
	}
	else if (A[pal-1] > B[res-1])
	{
		return findk(B+res, n-res, A, pal, k-res);
	}
	else
	{
		return findk(A+pal, m-pal, B, res, k-pal);
	}

}

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int k=m+n;
		if(k%2==1)
		{
		    return findk(A,m,B,n,k/2+1);
		}
		else
		{
			return (findk(A,m,B,n,k/2) + findk(A,m,B,n,k/2+1))/2;
		}
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

