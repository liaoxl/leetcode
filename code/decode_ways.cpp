/*
 * decode_ways.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

class Solution {
public:
		bool isValid(string s)
		{
			int len=s.length();
			if(len<1 || len>2) return false;
			int sum=0;
			for(int i=0; i<len; i++)
			{
				sum*=10;
				sum+=s[i]-'0';
			}
			if(len==2 && sum <10) return false;
			if(sum>=1 && sum<=26) return true;
			return false;
		}
    int numDecodings(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        	int len=s.length();
			if(len==0 || s[0]=='0') return 0;
			int* dp=new int[len+1];
			for(int i=0; i<=len; i++)
			{
				dp[i]=0;
			}
			dp[0]=1;
			if(isValid(s.substr(0,1))) dp[1]=1;
			else dp[1]=0;
			for(int i=2; i<=len; i++)
			{
				if(isValid(s.substr(i-1,1)))
					dp[i]=dp[i-1];
				if(isValid(s.substr(i-2,2)))
					dp[i]+=dp[i-2];
			}
			return dp[len];
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

