/*
 * permutations2.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        do
        {
            res.push_back(num);
        }while(next_permutation(num.begin(),num.end()));
        return res;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

