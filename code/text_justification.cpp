/*
 * text_justification.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void justify(vector<string> &words,int idx,
    vector<string> &r, int L) {
        if(idx>=words.size()) return;
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len=words[idx].length();
        int next_idx=idx+1;
        while(next_idx<words.size() && len+1+words[next_idx].length()<=L)
        {
            len=len+1+words[next_idx].length();
            next_idx++;
        }
        int count=next_idx-idx-1;
        int left=L-len;
        int interval_space=(count==0)?0:left/count;
        int left_space=left-interval_space*count;
        
        if(next_idx!=words.size())
        {
            string s;
            if(count==0) s=words[idx]+string(left_space,' ');
            else
            {
                s=words[idx];
                int i=idx+1;
                for(;i<idx+1+left_space;i++)
                {
                    s+=string(interval_space+2,' ')+words[i];
                }
                //s=string(left_space,' ')+words[idx];
                for(;i<next_idx;i++)
                {
                    s+=string(interval_space+1,' ')+words[i];
                }
            }
            r.push_back(s);
            justify(words,next_idx,r,L);
        }
        else
        {
            string s=words[idx];
            for(int i=idx+1;i<next_idx;i++)
            {
                s+=string(1,' ')+words[i];
            }
            s+=string(L-len,' ');
            r.push_back(s);
        }
        
    }
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> r;
        justify(words,0,r,L);
        return r;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

