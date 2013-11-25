/*
 * minimum_window_substring.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

bool findMinWindow(string s, string t, int &mbegin, int &mend)
{
	int slen=s.length();
	int tlen=t.length();
	
	int needtofind[256]={0};
	for(int i=0; i<tlen; i++)
	{
		needtofind[t[i]]++;
	}

	int hasfind[256]={0};

	int begin=0, end=0;
	int count=0;
	mbegin=0;
	mend=slen-1;
	int minwindow=slen;

	for(begin=0, end=0; end<slen; end++)
	{
		if(needtofind[s[end]]==0)
		{
			continue;
		}
		hasfind[s[end]]++;
		if(needtofind[s[end]]>0 && hasfind[s[end]]<=needtofind[s[end]])
		{
			count++;
		}

		if(count==tlen)
		{
			while(needtofind[s[begin]]==0 || hasfind[s[begin]] > needtofind[s[begin]])
			{
				if(hasfind[s[begin]]>0)
				{
					hasfind[s[begin]]--;
				}
				begin++;
			}
			int tmp=end-begin+1;
			if(tmp<minwindow)
			{
				minwindow=tmp;
				mbegin=begin;
				mend=end;
			}
		}
	}
	if(count==tlen)
		return true;
	else
		return false;
}


class Solution {
public:
    string minWindow(string S, string T) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        	int mb=0,md=0;
			if(findMinWindow(S,T,mb,md))
			{
				return S.substr(mb, md-mb+1);
			}
			else
				return "";

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

