/*
 * palindrome_number.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x==0)
		{
			return true;
		}
		if(x<0)
		{
			return false;
		}
		int tmp;
		int cnt=0;
		tmp=1;
		while(x/tmp >= 10)
		{
		    tmp*=10;
		}
		while(x>=10)
		{
			cnt=0;
			if(x%10 != x/tmp)
			{
				return false;
			}
			x=(x-(x/tmp)*tmp-x%10)/10;
			tmp/=100;
		}
		return true;

        
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

