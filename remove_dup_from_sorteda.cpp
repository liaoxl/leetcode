#include <iostream>

using namespace std;

class Solution{
	public:
		int removeDuplicates(int A[], int n)
		{
			int count=0;
			for(int i=0; i<n; i++)
			{
				if(i+1<n && A[i]==A[i+1])
				{
					count++;

					if(count==2)
					{
						int val=A[i];
						while(i+1<n && A[i+1]==val)
						{
							for(int j=i+1; j<n-1; j++)
							{
								A[j]=A[j+1];
							}
							n=n-1;
						}
						count=0;
					}
				}
				else
				{
					count=0;
				}
			}
			return n;
		}
};

int main()
{
	int A[]={1,1,2,2};
	Solution s;
	cout << s.removeDuplicates(A,4) << endl;
	return 0;
}
