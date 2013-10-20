#include <iostream>
#include <vector>

using namespace std;

class Solution{
	public:
		vector<int> searchRange(int A[], int n, int target)
		{
			int pos=searchT(A,0,n-1,target);
			int left,right;
			if(pos==-1)
			{
				left=-1,right=-1;
			}
			else
			{
				int tmp=pos;
				while(tmp>=0 && A[tmp]==target)
				{
					left=tmp;
					tmp--;
				}
				tmp=pos;
				while(tmp<n && A[tmp]==target)
				{
					right=tmp;
					tmp++;
				}
			}
			vector<int> res;
			res.push_back(left);
			res.push_back(right);
			return res;
		}
		int searchT(int A[], int start, int end, int target)
		{
			if(start>end)
			{
				return -1;
			}
			int mid=(start+end)/2;
			if(A[mid]==target)
			{
				return mid;
			}
			else if(A[mid]>target)
			{
				return searchT(A, start, mid-1, target);
			}
			else
			{
				return searchT(A, mid+1, end, target);
			}
		}
};

int main()
{
	int A[]={1,4};
	Solution s;
	s.searchRange(A,2,4);
	return 0;
}
