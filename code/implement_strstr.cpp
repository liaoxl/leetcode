/*
 * implement_strstr.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

void FindNext(char pt[], int pfix[])
{
    // parameter @plen is the length of patter string pt
    int plen = 0;
    while(pt[plen++] != '\0');

    // pn is the index of the prefix
    // pn also is the step value of prefix array
    int pn = 0;

    // the first char is set zero
    pfix[1] = 0;

    // i is the index of the suffix
    // start from index "1"
    for(int i = 2; i <= plen; i++)
    {

        // when unmatched, set the step as previous possible value
        // until one possible value matched or pn goes to zero
        while(pn > 0 && pt[pn] != pt[i-1])
        {
            pn = pfix[pn];
        }
        // prefix is matched to suffix: increase the index and step
        if(pt[pn] == pt[i-1])
        {
            pn++;
        }
        // save the step at suffix index i
        pfix[i] = pn;
    }
}


class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int plen = 0, tlen = 0;

        // Getting the length of pt and tg
        while(needle[plen] != '\0') plen++;
        while(haystack[tlen] != '\0') tlen++;
        
        if(plen==0)
        {
            return haystack;
        }
        if(tlen==0)
        {
            return NULL;
        }

        // the prefix array of pt, and get it by function FindNext
        int* pfix=new int[plen+10];
        pfix[0] = 0;
        FindNext(needle, pfix);

        // denote the current matching number
        int cmatch = 0;
		int pos=-1;
        for(int i = 0; i < tlen; i++)
        {
            // if matched is more than zero and get unmatched
            // then should set the cmatch to the previous one.
            while(cmatch > 0 && needle[cmatch] != haystack[i])
            {
                cmatch = pfix[cmatch];
            }

            // if get matched, then increase the index
            if(needle[cmatch] == haystack[i])
            {
                cmatch++;
            }
            // when cmatch == plen, that indicates one matching period
            // if you want to do something after first matching, then you should terminate the program here
            // if you want to search all cases, then using cmatch = pfix[plen]
            if(cmatch == plen)
            {
                pos=i+1-cmatch;
                break;
                //cmatch = pfix[plen];
            }

        }
        delete [] pfix;
        if(pos==-1)
		{
			return NULL;
		}
		else
			return haystack+pos;
    }
};


int main(int argc, char* argv[])
{
	
	return 0;
}

