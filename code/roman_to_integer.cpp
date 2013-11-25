/*
 * roman_to_integer.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131117/leetcode-rtoi/
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int toNum(char c)  
    {  
        switch(c)  
        {  
            case 'I':  
                return 1;  
            case 'V':  
                return 5;  
            case 'X':  
                return 10;  
            case 'L':  
                return 50;  
            case 'C':  
                return 100;  
            case 'D':  
                return 500;  
            case 'M':  
                return 1000;  
            default:  
                return 0;  
        }  
    } 
    
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = 0;
    	for(int i = 0; i < s.size(); i++)
		{
			if(i + 1 < s.size())
			{
				if(toNum(s[i]) < toNum(s[i+1]))     // high num < low num, then minus
				{
					ret -= toNum(s[i]);
				}
				else
				{
					ret += toNum(s[i]);
				}
			}
			else
			{
				ret += toNum(s[i]);
			}
		}
		return ret;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

