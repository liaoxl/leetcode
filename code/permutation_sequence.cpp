/*
 * permutation_sequence.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        int sum=1;
        string str="123456789";
        for(int i=1; i<=n; i++)
        {
            sum*=i;
        }
        k=(k-1)%sum;
        string res="";
        for(int i=n; i>=1; i--)
        {
            sum/=i;
            int pos=k/sum;
            res+=str[pos];
            str.erase(pos,1);
            k=k%sum;
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

