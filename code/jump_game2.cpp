/*
 * jump_game2.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131124/leetcode-jg2/
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int maxp=0;
        int step=0;
        int tmp=0;
        for(int i=0; i<n; )
        {
            if(tmp>=n-1) break;
            while(i<=tmp)
            {
                maxp=max(maxp, i+A[i]);
                i++;
            }
            step++;
            tmp=maxp;
        }
        return step;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

