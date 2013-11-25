/*
 * substring_with_concatenation_of_all_words.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int slen = S.length();
        vector<int> ret;
        if(slen < 1)
            return ret;
        int llen = L.size();
        int wlen = L[0].length();
        map<string, int> needToFind;
        map<string, int> hasFound;
        int i, j, k, count = 0;
               // visit L, fill the map
        for(i = 0 ; i < llen ; i ++)
        {
            if(needToFind.count(L[i]) == 0)
                needToFind[L[i]] = 1;
            else
                needToFind[L[i]] ++;
        }
        for(k = 0 ; k < wlen ; k ++)
        {
            hasFound.clear();
            count = 0;
            for(i = k, j = k ; j < slen - wlen + 1 ; j += wlen)
            {
                string str = S.substr(j, wlen);
                if(needToFind.count(str) == 0)     // Meet some intervening character, skip and clear
                {
                    i = j + wlen;
                    count = 0;
                    hasFound.clear();
                    continue;
                }
    
                if(hasFound.count(str) == 0)       // Add to hasFound
                    hasFound[str] = 1;
                else
                    hasFound[str] ++;
                if(hasFound[str] <= needToFind[str])
                    count ++;
                else
                {
                    string tmp = S.substr(i, wlen);  // there's more words than need, subtract the first one, move i
                    while(tmp != str)
                    {
                        i += wlen;
                        tmp = S.substr(i, wlen);
                    }
                    i += wlen;
                    hasFound[str]--;
                }
                if(count == llen)       // one substring satisfies, push back and move the window
                {
                    ret.push_back(i);
                    hasFound[S.substr(i, wlen)]--;
                    count --;
                    i += wlen;                    
                }
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

