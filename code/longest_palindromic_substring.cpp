/*
 * longest_palindromic_substring.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

int findmaxd(string s, int ind, int mind)
{
	int i=mind;
	int len=s.length();
	while(ind-i>=0 && ind+i<len && s[ind-i]==s[ind+i])
	{
		i++;
	}
	return i;
}


class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        	int len=s.length();
			int i=0;
			for(i=0; i<= len; i++)
			{
				s.insert(2*i, "#");
			}
			int tlen=s.length();
			int p=1;
			int max=0;
			int index=0;
			for(i=1; i<tlen; i++)
			{
				p=findmaxd(s,i,1);
				if(p>max)
				{
					max=p;
					index=i;
				}
			}
			s=s.substr(index-max+1,2*(max-1));
			string::iterator it;
			for(it=s.begin();it!=s.end();)
			{
				if(*it=='#')
				{
					s.erase(it);
					continue;
				}
				++it;
			}
			return s;

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

