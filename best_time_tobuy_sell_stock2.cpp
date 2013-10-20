#include <iostream>
#include <vector>

using namespace std;

class Solution{
	public:
		int maxProfit(vector<int> &prices)
		{
			int sum=0;
			int minp, maxp;
			int len=prices.size();
			if(len==0 || len==1)
			{
				return 0;
			}
			minp=maxp=prices[0];
			for(int i=1; i<len; i++)
			{
				if(prices[i]<=maxp)
				{
					sum+=maxp-minp;
					minp=prices[i];
					maxp=prices[i];
				}
				else if(prices[i]>maxp)
				{
					maxp=prices[i];
				}
			}
			return sum;
		}
};

int main()
{
	return 0;
}
