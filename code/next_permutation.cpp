/*
 * next_permutation.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131123/leetcode-np/
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        next_permutation(num.begin(), num.end());
        return;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

