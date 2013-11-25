/*
 * word_break.cpp
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
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        			int len=s.length();
			vector<bool> word(len+1, false);
			word[0]=true;
			for(int i=1; i<=len; i++)
			{
				for(int j=i-1; j>=0; j--)
				{
					if(word[j] && dict.find(s.substr(j,i-j))!=dict.end())
					{
						word[i]=true;
						break;
					}
				}
			}
			return word[len];

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

