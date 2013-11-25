/*
 * interleaving_string.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        int n1(s1.size()),n2(s2.size()),n3(s3.size());
        if(n3!=n1+n2) return false;
        bool d[n1+1][n2+1];
        bzero(d,(n1+1)*(n2+1)*sizeof(bool));
        d[0][0]=true;

        for(int i=0;i<n1;++i)
            if(s1[i]==s3[i]) d[i+1][0]=true;
            else break;

        for(int i=0;i<n2;++i)
            if(s2[i]==s3[i]) d[0][i+1]=true;
            else break;

        for(int i=1;i<=n1;++i)
            for(int j=1;j<=n2;++j)
                d[i][j]=(d[i][j-1]&&s3[i+j-1]==s2[j-1])||(d[i-1][j]&&s3[i+j-1]==s1[i-1]);

        return d[n1][n2];
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

