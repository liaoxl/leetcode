#include <iostream>
#include <vector>
#include <queue>

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
			queue<pair<int,int> > myque;
			int im=0, in=0;
			int res=0;
			myque.push(make_pair(im,in));
			while(!myque.empty())
			{
				int len=myque.size();
				while(len-->0)
				{
					pair<int,int> cur=myque.front();
					if(cur.first==m-1 && cur.second==n-1 && obstacleGrid[cur.first][cur.second]!=1)
					{
						res++;
						myque.pop();
						continue;
					}
					if(cur.first<m-1 && obstacleGrid[cur.first+1][cur.second]!=1)
					{
						myque.push(make_pair(cur.first+1,cur.second));
					}
					if(cur.second<n-1 && obstacleGrid[cur.first][cur.second+1]!=1)
					{
						myque.push(make_pair(cur.first, cur.second+1));
					}
					myque.pop();
				}
			}
			return res;
		}
};

int main()
{
	vector<int> a1(3, 0);
	vector<vector<int> > a(3,a1);
	a[1][1]=1;
	Solution s;
	cout << s.uniquePathsWithObstacles(a);
	return 0;
}

