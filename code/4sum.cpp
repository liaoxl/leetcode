/*
 * 4sum.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    void threeSum(vector<int> &num, int start, int target, vector<vector<int> > &res) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int n=num.size();
            if(n-start<4) return;
            vector<int> tmp;
            tmp.push_back(num[start]);
            int sum=0;
            int i,j,k;
            for(i=start+1; i<=n-3; i++)
            {
                if(i>start+1 && num[i]==num[i-1]) continue;
                j=i+1;
                k=n-1;
                while(j<k)
                {
                    sum=num[i]+num[j]+num[k];
                    if(sum==target)
                    {
                        tmp.push_back(num[i]);
                        tmp.push_back(num[j]);
                        tmp.push_back(num[k]);
                        res.push_back(tmp);
                        tmp.resize(1);
                        do{j++;}while(j<k && num[j]==num[j-1]);
                        do{k--;}while(k>j && num[k]==num[k+1]);
                    }
                    else if(sum>target)
                    {
                        k--;
                    }
                    else
                    {
                        j++;
                    }
                }
            }
        }

public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n=num.size();
        vector<vector<int> > res;
        if(n<4) return res;
        sort(num.begin(),num.end());
        for(int i=0; i<n; i++)
        {
            threeSum(num,i,target-num[i], res);
        }
        sort(res.begin(),res.end());
        vector<vector<int> >::iterator it;
        it=unique(res.begin(),res.end());
        res.resize(distance(res.begin(),it));
        return res;
    }
};


int main(int argc, char* argv[])
{
	
	return 0;
}

