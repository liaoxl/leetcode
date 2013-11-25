/*
 * unique_binary_search_trees.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

class Solution {
public:

    int numTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n==0 || n==1)
        {
            return 1;
        }
        int val=0;
        for(int i=0; i<=n-1; i++)
        {
            val+=numTrees(i)*numTrees(n-1-i);
        }
        return val;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

