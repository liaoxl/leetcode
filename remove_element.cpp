#include <iostream>

using namespace std;

class Solution{
	public:
		int removeElement(int A[], int n, int elem)
		{
			for(int i=0; i<n; i++)
			{
				if(A[i]==elem)
				{
					A[i]=A[n-1];
					i--;
					n=n-1;
				}
			}
			return n;
		}
};

int main()
{
	return 0;
}
