/*
 * longest_valid_parentheses.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131123/leetcode-lvp/
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n=s.length();
        if(!n) return n;
        stack<int> mystack;
        int i=0;
        int ml=0;
        while(i<n)
        {
            if(mystack.empty() || s[i]=='(')
            {
                mystack.push(i++);
                continue;
            }
            if(s[i]==')')
            {
                if(!mystack.empty() && s[mystack.top()]=='(')
                {
                    //int tmpi=mystack.top();
                    mystack.pop();
                    int tml=mystack.empty()?i+1:i-mystack.top();
                    if(tml>ml) ml=tml;
                    i++;
                }
                else
                {
                    mystack.push(i++);
                }
            }
        }
        return ml;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

