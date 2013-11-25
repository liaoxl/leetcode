/*
 * multiply_strings.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131124/leetcode-ms/
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!num1.compare("0") || !num2.compare("0")) return "0";
        			string num;
			int len1=num1.length();
			int len2=num2.length();
			num.resize(len1+len2);
			int addon=0;
			for(int i=0; i<len1+len2; i++)
			{
				num[i]='0';
			}
			for(int i=len1-1; i>=0; i--)
			{
			    addon=0;
				for(int j=len2-1; j>=0; j--)
				{
					int tmp=num[i+j+1]-'0'+(num1[i]-'0')*(num2[j]-'0')+addon;
					addon=tmp/10;
					num[i+j+1]=tmp%10+'0';
				}
				num[i]+=addon;
			}
			if(num[0]=='0')
			{
				num.erase(num.begin());
			}
			return num;

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

