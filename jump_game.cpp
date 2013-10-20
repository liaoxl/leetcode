#include <iostream>
#include <vector>

using namespace std;

class Solution{
	public:
		bool canJump(int A[], int n)
		{
			vector<bool> res(n, false);
			res[0]=res[1]=true;

			for(int i=0; i<n; i++)
			{
				int val=A[i];
				int tmp=0;
				while(tmp<=val && i+tmp<n && res[i])
				{
					res[i+tmp]=true;
					tmp++;
				}
			}
			return res[n-1];
		}
};

int main()
{
	return 0;
}
