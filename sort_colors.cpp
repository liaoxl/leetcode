#include <iostream>

using namespace std;

class Solution{
	public:
		void sortColors(int A[], int n)
		{
			int rc=0,wc=0,bc=0;
			for(int i=0; i<n; i++)
			{
				if(A[i]==0)
				{
					rc++;
				}
				else if(A[i]==1)
				{
					wc++;
				}
				else if(A[i]==2)
				{
					bc++;
				}
			}
			int cnt=0;
			for(int i=0; i<rc; i++)
			{
				A[cnt]=0;
				cnt++;
			}
			for(int i=0; i<wc; i++)
			{
				A[cnt]=1;
				cnt++;
			}
			for(int i=0; i<bc; i++)
			{
				A[cnt]=2;
				cnt++;
			}
		}
};

int main()
{
	return 0;
}
