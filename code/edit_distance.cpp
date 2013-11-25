/*
 * edit_distance.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len1=word1.length();
        int len2=word2.length();
        int** a=new int*[len1+1];
        for(int i=0; i<len1+1; i++)
        {
            a[i]=new int[len2+1];
        }
        //memset(a, 0, (len1+1)*(len2+1));
        a[0][0]=0;
        for(int i=1; i<=len1; i++)
        {
            a[i][0]=i;
        }
        for(int i=1; i<=len2; i++)
        {
            a[0][i]=i;
        }
        for(int i=1; i<=len1; i++)
        {
            for(int j=1; j<=len2; j++)
            {
                a[i][j]=min(a[i-1][j]+1, a[i][j-1]+1);
                if(word1[i-1]==word2[j-1])
                {
                    a[i][j]=min(a[i-1][j-1], a[i][j]);
                }
                else
                {
                    a[i][j]=min(a[i][j],a[i-1][j-1]+1);
                }
            }
        }
        int m=a[len1][len2];
        for(int i=0; i<=len1; i++)
        {
            delete [] a[i];
        }

        return m;

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

