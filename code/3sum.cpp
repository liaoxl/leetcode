/*
 * 3sum.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131121/leetcode-3sum/
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n=num.size();
        vector<vector<int> > res;
        if(n<3) return res;
        vector<int> tmp;
        sort(num.begin(),num.end());
        int sum=0;
        int i,j,k;
        for(i=0; i<=n-3; i++)
        {
            if(i>0 && num[i]==num[i-1]) continue;
            j=i+1;
            k=n-1;
            while(j<k)
            {
                sum=num[i]+num[j]+num[k];
                if(sum==0)
                {
                    tmp.push_back(num[i]);
                    tmp.push_back(num[j]);
                    tmp.push_back(num[k]);
                    res.push_back(tmp);
                    tmp.clear();
                    do{j++;}while(j<k && num[j]==num[j-1]);
                    do{k--;}while(k>j && num[k]==num[k+1]);
                }
                else if(sum>0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

