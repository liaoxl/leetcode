/*
 * 3sum_closest.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n=num.size();
        sort(num.begin(),num.end());
        int sum=0;
        int _minus=1000;
        int i,j,k;
        for(i=0; i<=n-3; i++)
        {
            if(i>0 && num[i]==num[i-1]) continue;
            j=i+1;
            k=n-1;
            while(j<k)
            {
                sum=num[i]+num[j]+num[k];
                if(sum-target==0) return sum;
                if(sum-target>0)
                {
                    _minus=abs(sum-target)<abs(_minus-target)?sum:_minus;
                    k--;
                }
                else
                {
                    _minus=abs(sum-target)<abs(_minus-target)?sum:_minus;
                    j++;
                }
            }
        }
        return _minus;
    }

};

int main(int argc, char* argv[])
{
	
	return 0;
}

