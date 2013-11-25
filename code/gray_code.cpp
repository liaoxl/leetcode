/*
 * gray_code.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> ret;
        int size = 1 << n;
        for(int i = 0; i < size; ++i)
            ret.push_back((i >> 1)^i);
        return ret;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

