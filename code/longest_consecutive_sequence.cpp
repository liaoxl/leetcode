/*
 * longest_consecutive_sequence.cpp
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
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=num.size();
        if(n==0||n==1)
        {
            return n;
        }
        unordered_set<int> data;
        for(int i=0; i<n; i++)
        {
            data.insert(num[i]);
        }
        int maxc=0;
        for(int i=0; i<n; i++)
        {
            int count=1;
            int tmp=num[i];
            if(!data.empty() && data.find(tmp)!=data.end())
            {
                data.erase(data.find(tmp));
            }

            while(!data.empty() && data.find(--tmp)!=data.end())
            {
                data.erase(data.find(tmp));
                count++;
            }
            tmp=num[i];
            while(!data.empty() && data.find(++tmp)!=data.end())
            {
                data.erase(data.find(tmp));
                count++;
            }

            if(count>maxc)
            {
                maxc=count;
            }
        }
        return maxc;

    }

};


int main(int argc, char* argv[])
{
	
	return 0;
}

