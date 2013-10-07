#include <iostream>


using namespace std;

class Solution{
	public:
		int maxSubArray(int A[], int n)
		{
			int maxs=-100000;
			int tmpsum=0;
			for(int i=0; i<n; i++)
			{
				tmpsum+=A[i];
				if(tmpsum > maxs)
				{
					maxs=tmpsum;
				}
				if(tmpsum<0)
				{
					tmpsum=0;
				}
			}
			return maxs;
		}
};

int main()
{
	return 0;
}
