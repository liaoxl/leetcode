/*
 * search_in_rotated_sorted_array.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131123/leetcode-srsa/
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int binarySearch(int a[], int n, int start, int end, int target)
    {
        if(start>end) return -1;
        if(start==end && target!=a[start]) return -1;

        int mid=(start+end)/2;
        if(a[mid]==target)
        {
            return mid;
        }
        else if(a[mid]>target)
        {
            if(a[mid]>=a[start])
            {
                if(target>=a[start])
                {
                    return binarySearch(a,n,start,mid-1,target);
                }
                else
                {
                    return binarySearch(a,n,mid+1,end,target);
                }
            }
            else
            {
                return binarySearch(a,n,start,mid-1,target);
            }
        }
        else if(a[mid]<target)
        {
            if(a[mid]>=a[start])
            {
                return binarySearch(a,n,mid+1,end,target);
            }
            else
            {
                if(target<=a[end])
                {
                    return binarySearch(a,n,mid+1,end,target);
                }
                else
                {
                    return binarySearch(a,n,start,mid-1,target);
                }
            }
        }
        return -1;
    }

    int search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n==0) return -1;
        if(n==1 && A[0]!=target) return -1;
        return binarySearch(A,n,0,n-1,target);

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

