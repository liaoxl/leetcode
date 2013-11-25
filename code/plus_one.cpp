/*
 * plus_one.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
            int sz=digits.size();
			if(sz==0)
			{
				digits.push_back(1);
			}
			digits[sz-1] += 1;
			vector<int>::iterator it;
			while(sz>=1 && digits[sz-1]>=10)
			{
				if(sz==1)
				{
					it=digits.begin();
					int tmp=digits[sz-1]/10;
					digits[sz-1]=digits[sz-1]%10;
					digits.insert(it,tmp);
				}
				else
				{
					digits[sz-2] += digits[sz-1]/10;
					digits[sz-1] = digits[sz-1]%10;
					sz=sz-1;
				}
			}
			return digits;

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

