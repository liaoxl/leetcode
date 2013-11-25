/*
 * permutations.cpp
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
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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

