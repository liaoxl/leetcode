/*
 * valid_palindrome.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len=s.length();
        if(len==0 || len==1)
        {
            return true;
        }
        int i=0;
        while(s[i]!='\0')
        {
            if((s[i]>='a' && s[i] <='z')||(s[i]>='0' && s[i] <='9'))
            {
                i++;
            }
            else if(s[i]>='A' && s[i] <='Z')
            {
                s[i]=s[i]-'A'+'a';
                i++;
            }
            else
            {
                s.erase(s.begin()+i);
            }
        }
        len=s.length();
        if(len==0 || len==1)
        {
            return true;
        }
        int l=0,r=len-1;
        while(l<=r)
        {
            if(s[l]!=s[r])
            {
                return false;
            }
            l++,r--;
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

