/*
 * restore_ip_addresses.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        int n=s.length();
        if(n>=4) return false;
        if(n>1 && s[0]=='0') return false;
        int num=0;
        for(int i=0; i<n; i++)
        {
            num*=10;
            num+=s[i]-'0';
        }
        return num>=0 && num<=255;
    }

    void dfs(int start, int n, int step, string s, string &tmp, vector<string> &res)
    {
        if(step>3 || start>=n) return;
        if(step==3 && isValid(s.substr(start, n-start+1)))
        {
            tmp.append(s.substr(start, n-start+1));
            res.push_back(tmp);
            return;
        }
        for(int i=start; i<n; i++)
        {
            if(isValid(s.substr(start, i-start+1)))
            {
                int len=tmp.size();
                tmp.append(s.substr(start, i-start+1)+".");
                dfs(i+1,n,step+1,s,tmp,res);
                tmp.resize(len);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=s.length();
        vector<string> res;
        string tmp;
        dfs(0,n,0,s,tmp,res);
        return res;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

