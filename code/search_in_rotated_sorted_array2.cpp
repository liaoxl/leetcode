/*
 * search_in_rotated_sorted_array2.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool binarySearch(int a[], int n, int start, int end, int target)
    {
        if(start>end) return false;
        if(start==end && target!=a[start]) return false;

        int mid=(start+end)/2;
        if(a[mid]==target)
        {
            return true;
        }
        else if(a[mid]>target)
        {
            if(a[mid]==a[start])
            {
                return binarySearch(a,n,start+1,end,target);
            }
            else if(a[mid]>a[start])
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
            if(a[mid]==a[start])
            {
                return binarySearch(a,n,start+1,end,target);
            }
            else if(a[mid]>a[start])
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
        return false;
    }

    bool search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n==0) return false;
        if(n==1 && A[0]!=target) return false;
        return binarySearch(A,n,0,n-1,target);

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

