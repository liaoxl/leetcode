/*
 * best_time_to_buy_and_sell_stock3.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxp=0;
        int len=prices.size();
        if(len==0)
        {
            return maxp;
        }
        vector<int> left(len,0);
        vector<int> right(len,0);
        int leftp=prices[0];
        for(int i=1; i<len; i++)
        {
            leftp=leftp>prices[i]?prices[i]:leftp;
            left[i]=prices[i]-leftp<left[i-1]?left[i-1]:prices[i]-leftp;
        }
        int rightp=prices[len-1];
        for(int i=len-2; i>=0; i--)
        {
            rightp=rightp>prices[i]?rightp:prices[i];
            right[i]=rightp-prices[i]<right[i+1]?right[i+1]:rightp-prices[i];
        }
        for(int i=0; i<len; i++)
        {
            if(left[i]+right[i]>maxp) maxp=left[i]+right[i];
        }
        return maxp;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

