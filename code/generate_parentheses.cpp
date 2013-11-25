/*
 * generate_parentheses.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131121/leetcode-gp/
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string str;
    vector<string> res;
    void dfs(int left, int right, int n)
    {
        if(left==n)
        {
            res.push_back(str.append(n-right,')'));
            str.pop_back();
            int tmp=n-right;
            while(--tmp>0)
            {
                str.pop_back();
            }
            return;
        }
        str.append("(");
        dfs(left+1,right,n);
        str.pop_back();
        if(right<left)
        {
            str.append(")");
            dfs(left,right+1,n);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        str.clear();
        res.clear();
        dfs(0,0,n);
        return res;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

