#include <iostream>
#include <vector>

using namespace std;

struct Interval{
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

class Solution{
	public:
		vector<Interval> merge(vector<Interval> &intervals){
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

int main()
{
	return 0;
}
