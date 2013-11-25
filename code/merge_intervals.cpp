/*
 * merge_intervals.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131124/leetcode-mi/
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for an interval.
 */
 struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

 bool isIntersected(Interval a, Interval b)
{
	if(a.start > b.end || b.start > a.end)
	{
		return false;
	}
	return true;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        	int len=intervals.size();
			vector<Interval>::iterator it;
			int flag=0;
			
			for(int i=0; i<len; i++)
			{
			    flag=0;
				for(int j=i+1; j<len;j++)
				{
					if(isIntersected(intervals[i], intervals[j]))
					{
						intervals[i].start=min(intervals[i].start, intervals[j].start);
						intervals[i].end=max(intervals[i].end, intervals[j].end);
						it=intervals.begin()+j;
						intervals.erase(it);
						len=len-1;
						j=j-1;
						flag=1;
					}
				}
				if(flag==1)
				{
				    i=i-1;
				}
			}
			return intervals;

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

