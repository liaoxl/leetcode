/*
 * candy.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
       	    			vector<int> a;

			int sum=0;

			int n=ratings.size();
			if(n==0) return sum;
			a.resize(n);
			for(int i=0; i<n; i++)
			{
				a[i]=0;
			}
			int cur=1;
			for(int i=0, cur=1; i<n; i++)
			{
				if(i-1>=0 && ratings[i]>ratings[i-1])
				{
					a[i]=max(cur++, a[i]);
				}
				else
				{
					cur=1;
				}
			}
			for(int i=n-1, cur=1; i>=0; i--)
			{
				if(i+1<n && ratings[i]>ratings[i+1])
				{
					a[i]=max(cur++, a[i]);
				}
				else
				{
					cur=1;
				}
			}
			for(int i=0; i<n; i++)
			{
				sum+=a[i]+1;
			}

			return sum;
 
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

