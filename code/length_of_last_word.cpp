/*
 * length_of_last_word.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        	int len=0;
			int index=0;
			int tmp=0;
			while(s[index]!='\0')
			{
				if(s[index]!=' ')
				{
					tmp++;
					len=tmp;
				}
				else
				{
					tmp=0;
				}
				index++;
			}
			if(tmp>0)
			{
				return tmp;
			}
			return len;

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

