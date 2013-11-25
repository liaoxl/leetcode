/*
 * palindrome_partitioning.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalin(int start, int end, string s)
    {
        while(start<end)
        {
            if(s[start]!=s[end]) return false;
            start++,end--;
        }
        return true;
    }

    void dfs(int start, int n, string s, vector<string> &str, vector<vector<string> > &res)
    {
        if(start==n)
        {
            res.push_back(str);
            return;
        }
        for(int i=start; i<n; i++)
        {
            if(isPalin(start, i, s))
            {
                str.push_back(s.substr(start, i-start+1));
                dfs(i+1,n,s,str,res);
                str.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<string> > res;
        vector<string> str;
        int n=s.length();
        dfs(0,n,s,str,res);
        return res;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

