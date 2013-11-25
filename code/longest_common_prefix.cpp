/*
 * longest_common_prefix.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131115/leetcode-lcp/
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    string twoCommonPrefix(string str1, string str2)
    {
        int i=0;
        int len1=str1.length();
        int len2=str2.length();
        while(i<len1 && i<len2)
        {
            if(str1[i]!=str2[i])
            {
                break;
            }
            i++;
        }
        return str1.substr(0,i);
    }

public:
    string longestCommonPrefix(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string tmp;
        int len=strs.size();
        if(len==0)
        {
            return tmp;
        }
        tmp=strs[0];
        for(int i=1; i<len; i++)
        {
            tmp=twoCommonPrefix(tmp,strs[i]);
        }
        return tmp;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

