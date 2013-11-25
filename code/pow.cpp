/*
 * pow.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131124/leetcode-pow/
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

class Solution {
//31
// 2,4,8,16,   2,4,8,    2,4,  2,   1
    double pow2(double x, int n) {
 
        if (n == 1)
            return x;
 
        double remain = n%2;
        
        double ret = pow2(x, n/2);
        
        if (remain)
        {
            return ret*ret*pow2(x, remain);
        }
        
        return ret*ret;
    }

public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function      
        
        if (n == 0)
            return (double)1;
            
        if (n == 1)
            return x;
            
        if (x == 1)
            return (double)1;
        
        if(x == -1)
        {
            if(n%2 == 0)
            {
                return (double)1;
            }
            else
            {
                return (double)(-1);
            }
        }
            
            
        bool bNegative = n>0?false:true;
        
        if(bNegative)
        {
            n=0-n;
        }
        
        double ret = pow2(x, n);
        
        if (bNegative)
            return 1.0/ret;
        
        return ret;      
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

