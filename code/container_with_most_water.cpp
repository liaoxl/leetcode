/*
 * container_with_most_water.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131115/leetcode-cwmw/
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
       int n=height.size();
       if(n==0 || n==1) return 0;
       int maxa=0;
       int i=0,j=n-1;
       maxa=(j-i)*min(height[i],height[j]);
       for(;i!=j;)
       {
           maxa=(j-i)*min(height[i],height[j])>maxa?(j-i)*min(height[i],height[j]):maxa;
           if(height[i]<height[j])
           {
               i++;
           }
           else
           {
               j--;
           }
       }
       return maxa;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

