#include <iostream>
#include <vector>

using namespace std;

class Solution{
	public:
		int maxProfit(vector<int> &prices) {
			// Note: The Solution object is instantiated only once and is reused by each test case.
			int maxp=0;
			int len=prices.size();
			if(len==0)
			{
				return maxp;
			}
			int mini=prices[0];
			for(int i=1; i<len; i++)
			{
				if(prices[i]-mini>maxp)
				{
					maxp=prices[i]-mini;
				}
				if(prices[i]<mini)
				{
					mini=prices[i];
				}
			}
			return maxp;
    }
};

int main()
{
	return 0;
}
