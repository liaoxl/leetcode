/*
 * scramble_string.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(s1.length()!=s2.length()) return false;
        if(s1==s2) return true;

        string str1=s1,str2=s2;
        sort(str1.begin(),str1.end());
        sort(str2.begin(),str2.end());
        if(str1!=str2) return false;
        string s11,s12,s21,s22;

        for(int i=1; i<s1.length(); i++)
        {
            s11=s1.substr(0,i);
            s12=s1.substr(i);

            s21=s2.substr(0,i);
            s22=s2.substr(i);
            if(isScramble(s11,s21) && isScramble(s12,s22)) return true;

            s21=s2.substr(s2.size()-i);
            s22=s2.substr(0,s2.size()-i);
            if(isScramble(s11,s21) && isScramble(s12,s22)) return true;
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

