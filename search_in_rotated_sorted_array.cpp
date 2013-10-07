#include <iostream>

using namespace std;

int searcht(int a[], int n, int target)
{

}

class Solution{
	public:
		int search(int A[], int n, int target)
		{
			int rn=-1;
			int i;
			for(i=0; i<n-1; i++)
			{
				if(A[i] > A[i+1])
				{
					rn=i;
					break;
				}
			}
			if(i==n-1)
			{
				return searcht(A,n,target);
			}

		}
};

int main()
{
	return 0;
}
