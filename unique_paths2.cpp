#include <iostream>
#include <vector>

using namespace std;

class Solution{
	public:
		int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
		{
			int m=obstacleGrid.size();
			if(m==0)
			{
				return 0;
			}
			int n=obstacleGrid[0].size();
			if(n==0 || obstacleGrid[m-1][n-1]==1)
			{
				return 0;
			}
			int sum=cmn(m-1, m+n-2);
			for(int i=0; i<m; i++)
			{
				for(int j=0; j<n; j++)
				{
					if(obstacleGrid[i][j]==1)
					{
						sum-=(cmn(i,i+j)+cmn(m-i-1, m+n-i-j-2));
					}
				}
			}
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
	vector<int> a1(0);
	vector<vector<int> > a;
	a.push_back(a1);
	Solution s;
	s.uniquePathsWithObstacles(a);
	return 0;
}

