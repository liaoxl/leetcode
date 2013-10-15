#include <iostream>
#include <vector>

using namespace std;

class Solution{
	public:
		int minPathSum(vector<vector<int> > &grid)
		{
			int m=grid.size();
			if(m==0)
			{
				return 0;
			}
			int n=grid[0].size();
			if(n==0)
			{
				return 0;
			}
			int** p=new int*[m];
			for(int i=0; i<m; i++)
			{
				p[i]=new int[n];
			}
			p[0][0]=grid[0][0];
			for(int i=1; i<n; i++)
			{
				p[0][i]+=p[0][i-1]+grid[0][i];
			}
			for(int i=1; i<m; i++)
			{
				p[i][0]+=p[i-1][0]+grid[i][0];
			}

			for(int i=1; i<m; i++)
			{
				for(int j=1; j<n; j++)
				{
					p[i][j]=min(p[i-1][j], p[i][j-1])+grid[i][j];
				}
			}
			int res=p[m-1][n-1];
			for(int i=0; i<m; i++)
			{
				delete [] p[i];
			}
			delete [] p;
			return res;
		}
};

int main()
{
	vector<int> a1;
	vector<vector<int> > a;
	a1.push_back(1);
	a1.push_back(2);
	a.push_back(a1);
	a1.clear();
	a1.push_back(2);
	a1.push_back(3);
	a.push_back(a1);
	Solution s;
	cout << s.minPathSum(a) << endl;
	return 0;
}
