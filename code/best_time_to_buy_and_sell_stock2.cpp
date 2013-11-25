/*
 * best_time_to_buy_and_sell_stock2.cpp
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
        // Note: The Solution object is instantiated only once and is reused by each test case.
        			int sum=0;
			int minp, maxp;
			int len=prices.size();
			if(len==0 || len==1)
			{
				return 0;
			}
			minp=maxp=prices[0];
			for(int i=1; i<len; i++)
			{
				if(prices[i]<=maxp)
				{
					sum+=maxp-minp;
					minp=prices[i];
					maxp=prices[i];
				}
				else if(prices[i]>maxp)
				{
					maxp=prices[i];
				}
			}
			sum+=maxp-minp;
			return sum;

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

