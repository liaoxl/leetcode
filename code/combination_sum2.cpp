/*
 * combination_sum2.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > res;
    vector<int> tmp;

    void dfs(int start, int n, int target, vector<int> d)
    {
        if(target==0)
        {
			res.push_back(tmp);
            return;
        }
		if(target<=0 || start>=n) return;
        tmp.push_back(d[start]);
        dfs(start+1, n, target-d[start], d);
		tmp.pop_back();
		if(d[start]<=target)
		{
		    dfs(start+1,n,target,d);
		}
    }

    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        res.clear();
        tmp.clear();
        int n=candidates.size();
        if(n==0)
        {
            return res;
        }
        sort(candidates.begin(), candidates.end());
        dfs(0,n,target,candidates);
        sort(res.begin(),res.end());
        vector<vector<int> >::iterator it;
        it=unique(res.begin(),res.end());
        res.resize(distance(res.begin(), it));

        return res;
    }
};


int main(int argc, char* argv[])
{
	
	return 0;
}

