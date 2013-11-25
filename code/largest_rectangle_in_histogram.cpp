/*
 * largest_rectangle_in_histogram.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len=height.size();
        if(len<1) return 0;
        stack<int> mystack;
        int i=0;
        int maxa=0;
        while(i<len)
        {
            if(mystack.empty() || height[mystack.top()]<=height[i])
            {
                mystack.push(i++);
            }
            else
            {
                int tmpi=mystack.top();
                mystack.pop();
                int tmparea=height[tmpi]*(mystack.empty()?i:i-mystack.top()-1);
                if(tmparea > maxa) maxa=tmparea;
            }
        }
        while(!mystack.empty())
        {
            int tmpi=mystack.top();
            mystack.pop();
            int tmparea=height[tmpi]*(mystack.empty()?i:i-mystack.top()-1);
            if(tmparea > maxa) maxa=tmparea;
        }
        return maxa;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

