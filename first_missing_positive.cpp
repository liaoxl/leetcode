#include <iostream>

using namespace std;

class Solution{
	public:
		int firstMissingPositive(int A[], int n){
			
			for(int i=0; i<n; i++)
			{
				if(A[i]<1 || A[i]>n)
				{
					A[i]=0;
				}
				else if(A[A[i]-1]!=A[i])
				{
					int tmp=A[A[i]-1];
					A[A[i]-1]=A[i];
					A[i]=tmp;
					i--;
				}
			}
			for(int i=0; i<n; i++)
			{
				if(A[i]!=i+1)
				{
					return i+1;
				}
			}
			return n+1;
		}
};

int main()
{
	int a[]={3,4,-1,1};
	Solution s;
	cout << s.firstMissingPositive(a, 4) << endl;
	return 0;
}
