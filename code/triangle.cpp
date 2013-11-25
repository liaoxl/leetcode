/*
 * triangle.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m=triangle.size();
        if(m==0)
        {
            return 0;
        }
        vector<int> pre;
        vector<int> cur;
        pre.push_back(triangle[0][0]);
        cur=pre;
        for(int i=1; i<m; i++)
        {
            cur.resize(i+1);
            for(int j=0; j<i+1;j++)
            {
                if(j==0)
                {
                    cur[j]=pre[j]+triangle[i][j];
                }
                else if(j==i)
                {
                    cur[j]=pre[j-1]+triangle[i][j];
                }
                else
                {
                    cur[j]=min(pre[j-1]+triangle[i][j], pre[j]+triangle[i][j]);
                }
            }
            pre=cur;
        }
        int minp=10000;
        for(unsigned int i=0; i<cur.size(); i++)
        {
            if(cur[i]<minp)
            {
                minp=cur[i];
            }
        }
        return minp;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

