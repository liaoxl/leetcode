/*
 * reverse_integer.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131114/leetcode-reverse-integer/
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long int tx=abs((long long)x);
        long long int res=0;
        
        while(tx>=10)
        {
            res=res*10+tx%10;
            tx/=10;
        }
        res=res*10+tx;
        
        if(x<0) return -res;
        return res;
        
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

