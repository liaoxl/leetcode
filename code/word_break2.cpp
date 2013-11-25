/*
 * word_break2.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isWord(string s, unordered_set<string> dict)
    {
        return dict.find(s)!=dict.end();
    }

    void dfs(int start, int n, string s,unordered_set<string> dict, string &str, vector<string> &res)
    {
        if(start<0) return;

        for(int i=start; i>=0; i--)
        {
            if(isWord(s.substr(i,start-i+1),dict))
            {
                int len=str.length();
                str.insert(0, " "+s.substr(i,start-i+1));
                dfs(i-1,n,s,dict,str,res);
                str=str.substr(str.length()-len);
            }
        }
        if(isWord(s.substr(0,start+1),dict))
        {
            str.insert(0,s.substr(0,start+1));
            res.push_back(str);
            return;
        }
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> res;
        string str;
        int n=s.length();
        dfs(n-1,n,s,dict,str,res);
        return res;
    }
};


int main(int argc, char* argv[])
{
	
	return 0;
}

