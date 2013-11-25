/*
 * subsets.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int> > res;
    vector<int> a;
public:
    void dfs(int depth, int maxd, int start, int n, vector<int> s)
    {
        if(depth==maxd)
        {
            res.push_back(a);
            return;
        }
        if(start<=n)
        {
            a[depth]=s[start];
            dfs(depth+1, maxd, start+1, n, s);
            dfs(depth, maxd, start+1, n, s);
        }
        else
        {
            return;
        }
    }
    vector<vector<int> > subsets(vector<int> &S) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len=S.size();
        res.clear();
        a.clear();
        sort(S.begin(),S.end());
        res.push_back(a);
        for(int i=1; i<=len; i++)
        {
            a.resize(i);
            dfs(0,i,0,len-1,S);
        }
        
        a.clear();
        return res;
    }
};


int main(int argc, char* argv[])
{
	
	return 0;
}

