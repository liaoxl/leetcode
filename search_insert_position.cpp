#include <iostream>

using namespace std;

class Solution{
	public:
		int searchInsert(int A[], int n, int target){
			if(n==0)
			{
				return 0;
			}
			if(n==1)
			{
				if(A[0]<target)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}

			int mid=n/2;
			if(A[mid]==target)
			{
				return mid;
			}
			else if(A[mid]>target)
			{
				return searchInsert(A, mid, target);
			}
			else
			{
				return mid+searchInsert(A+mid,n-mid,target);
			}
		}
};

int main()
{
	int a[]={1,3};
	Solution s;
	cout << s.searchInsert(a,2,2) << endl;
	return 0;
}
