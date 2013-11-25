/*
 * valid_parentheses.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        				int len=s.length();
			if(len==0)
			{
				return true;
			}
			if(len%2!=0)
			{
				return false;
			}
			stack<char> valid;
			len=0;
			valid.push(s[len]);
			len++;
			while(s[len]!='\0')
			{
				if(!valid.empty() && ((valid.top()=='('&&s[len]==')') || (valid.top()=='['&&s[len]==']') || (valid.top()=='{'&&s[len]=='}')))
				{
					valid.pop();
				}
				else
				{
					valid.push(s[len]);
				}
				len++;
			}
			if(!valid.empty())
			{
				return false;
			}
			return true;

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

