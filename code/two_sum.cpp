/*
 * two_sum.cpp
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
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len=numbers.size();
        unordered_set<int> myhash(numbers.begin(),numbers.end());
        int i,j;
        vector<int> res;
        for(i=0; i<len; i++)
        {
            if(myhash.find(target-numbers[i])!=myhash.end())
            {
                res.push_back(i+1);
                break;
            }
        }
        for(j=i+1; j<len; j++)
        {
            if(numbers[j]==target-numbers[i])
            {
                res.push_back(j+1);
                return res;
            }
        }
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

