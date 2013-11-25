/*
 * search_for_a_range.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131123/leetcode-sfar/
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
      		int pos=searchT(A,0,n-1,target);
			int left,right;
			if(pos==-1)
			{
				left=-1,right=-1;
			}
			else
			{
				int tmp=pos;
				while(tmp>=0 && A[tmp]==target)
				{
					left=tmp;
					tmp--;
				}
				tmp=pos;
				while(tmp<n && A[tmp]==target)
				{
					right=tmp;
					tmp++;
				}
			}
			vector<int> res;
			res.push_back(left);
			res.push_back(right);
			return res;
		}
	int searchT(int A[], int start, int end, int target)
	{
			if(start>end)
			{
				return -1;
			}
			int mid=(start+end)/2;
			if(A[mid]==target)
			{
				return mid;
			}
			else if(A[mid]>target)
			{
				return searchT(A, start, mid-1, target);
			}
			else
			{
				return searchT(A, mid+1, end, target);
			}
  
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

