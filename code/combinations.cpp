/*
 * combinations.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int> > res;
    vector<int> a;
public:
    void dfs(int depth, int maxd, int start, int n)
    {
        if(depth==maxd)
        {
            res.push_back(a);
            return;
        }
        if(start<=n)
        {
            a[depth]=start;
            dfs(depth+1, maxd, start+1, n);
            dfs(depth, maxd, start+1, n);
        }
    }
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        a.resize(k);
        res.clear();
        dfs(0,k,1,n);
        return res;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

