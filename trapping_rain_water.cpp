#include <iostream>

using namespace std;


class Solution{
	public:
		int trap(int A[], int n)
		{
			if(n<=1) return 0;
			int left=0;
			int sum=0;
			int maxid=0;
			for(int i=1; i<n; i++)
			{
				if(A[i]>A[maxid]) maxid=i;
			}
			for(int i=1; i<maxid; i++)
			{
				if(A[i]<A[left])
				{
					sum+=A[left]-A[i];
				}
				else
				{
					left=i;
				}
			}
			int right=n-1;
			for(int i=n-2; i>maxid; i--)
			{
				if(A[i]<A[right]) sum+=A[right]-A[i];
				else right =i;
			}
			return sum;
		}
};

int main()
{
	int a[]={0,1,0,2,1,0,1,3,2,1,2,1};
	Solution s;
	cout << s.trap(a,12) << endl;
	return 0;
}
