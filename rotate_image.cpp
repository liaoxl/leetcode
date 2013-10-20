#include <iostream>
#include <vector>

using namespace std;

class Solution{
	public:
		void rotate(vector<vector<int> > &matrix)
		{
			vector<vector<int> > tmp;
			int n=matrix.size();
			tmp.resize(n);
			for(int i=0; i<n; i++)
			{
				tmp[i].resize(n);
			}
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
				{
					tmp[i][j]=matrix[n-j-1][i];
				}
			}
			matrix=tmp;
		}
};

int main()
{
	return 0;
}
