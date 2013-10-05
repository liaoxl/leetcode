#include <iostream>
#include <vector>

using namespace std;

struct Interval{
	int start;
	int end;
	Interval():start(0), end(0) {}
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
		vector<Interval> insert(vector<Interval> &intervals, Interval newInterval){
			int len=intervals.size();
			
			vector<Interval>::iterator it;
			if(len==0)
			{
				intervals.push_back(newInterval);
				return intervals;
			}

			int i,j;
			for(i=0; i<len; i++)
			{
				if(isIntersected(intervals[i], newInterval))
				{
					intervals[i].start=min(intervals[i].start, newInterval.start);
					intervals[i].end=max(intervals[i].end, newInterval.end);
					break;
				}
			}
			if(i==len)
			{
				if(newInterval.start>intervals[i-1].end)
			    {
				    intervals.push_back(newInterval);
			    }
			    else if(newInterval.end<intervals[0].start)
			    {
			        it=intervals.begin();
			        intervals.insert(it, newInterval);
			    }
			    else
			    {
			        for(int k=0; k<len; k++)
			        {
			            if(newInterval.start>intervals[k].end && newInterval.end<intervals[k+1].start)
			            {
			                it=intervals.begin()+k+1;
			                intervals.insert(it, newInterval);
			                break;
			            }
			        }
			    }
			}
			else
			{
				for(j=i+1; j<len; j++)
				{
					if(isIntersected(intervals[i],intervals[j]))
					{
						intervals[i].start=min(intervals[i].start, intervals[j].start);
						intervals[i].end=max(intervals[i].end, intervals[j].end);
						it=intervals.begin()+j;
						intervals.erase(it);
						len=len-1;
						j=j-1;
					}
				}
			}
			return intervals;

		}
};

int main()
{
	return 0;
}
