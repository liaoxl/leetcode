/*
 * wildcard_matching.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131124/leetcode-wm/
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        	if(s==NULL || p==NULL ) return false;
			if(*p=='\0') return *s=='\0';
            const char *star_p=NULL,*star_s=NULL;

            while(*s)
            {
                if(*p == '?' || *p == *s)
                {
                    ++p,++s;
                }else if(*p == '*')
                {
                    //skip all continuous '*'
                    while(*p == '*') ++p;
        
                    if(!*p) return true; //if end with '*', its match.
        
                    star_p = p; //store '*' pos for string and pattern
                    star_s = s;
                }else if((!*p || *p != *s)  && star_p)
                {
                    s = ++star_s; //skip non-match char of string, regard it matched in '*'
                    p = star_p; //pattern backtrace to later char of '*'
                }else
                    return false;
            }
        
            //check if later part of p are all '*'
            while(*p)
                if(*p++ != '*')
                    return false;
        
            return true;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

