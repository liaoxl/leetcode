/*
 * anagrams.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131124/leetcode-anagrams/
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        if(!strs.size()) return res;
        multimap<string,int> mp;
        int n=strs.size();

        for(int i=0; i<n; i++)
        {
            string s=strs[i];
            sort(s.begin(),s.end());
            mp.insert(make_pair(s,i));
        }
        multimap<string,int>::iterator it;
        int count=0;
        for(int i=0; i<n; i++)
        {
            string s=strs[i];
            sort(s.begin(),s.end());
            count=mp.count(s);
            if(count>1)
            {
                while((it=mp.find(s))!=mp.end())
                {
                    res.push_back(strs[it->second]);
                    mp.erase(it);
                }
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

