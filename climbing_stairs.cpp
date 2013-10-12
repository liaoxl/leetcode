#include <iostream>

using namespace std;

class Solution{
	public:
		int climbStairs(int n){
			
			int res=0;
			for(int i=1; 2*i<n; i++)
			{
				res += cmn(i, n-i);
			}
			if(n%2==0) res+=2;
			else res+=1;
			return res;
		}
		int cmn(int m, int n)
		{
			double res=1;
			for(int i=1; i<=m; i++)
			{
				res *=(double)(n-m+i)/(double)i;
			}
			return res;
		}
};

int main()
{
	Solution s;
	cout << s.climbStairs(5) << endl;
	return 0;
}
