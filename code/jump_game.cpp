/*
 * jump_game.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131124/leetcode-jg/
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
     // Note: The Solution object is instantiated only once and is reused by each test case.
        int maxj=0;
        for(int i=0;i<n;++i)
        {
            if(i<=maxj)
            {
                maxj=max(maxj,i+A[i]);
            }
        }
        return maxj>=n-1;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

