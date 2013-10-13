#include <iostream>
#include <vector>

using namespace std;

class Solution{
	public:
		bool searchMatrix(vector<vector<int> > &matrix, int target)
		{
			int m=matrix.size();
			if(m==0)
			{
				return false;
			}
			int n=matrix[0].size();
			if(n==0)
			{
				return false;
			}
			for(int i=0; i<m; i++)
			{
				if(searchrow(matrix, i, n, target))
				{
					if(searchincol(matrix[i], 0, n-1, target))
					{
						return true;
					}
				}
			}
			return false;

		}
		bool searchrow(vector<vector<int> > &matrix, int m, int n, int target)
		{
			if(target>=matrix[m][0] && target<=matrix[m][n-1])
			{
				return true;
			}
			return false;
		}
		bool searchincol(vector<int> &row, int left, int right, int target)
		{
			if(left>right)
			{
				return false;
			}
			int mid=(left+right)/2;
			if(row[mid]==target)
			{
				return true;
			}
			else if(target<row[mid])
			{
				return searchincol(row, left, mid-1, target);
			}
			else
			{
				return searchincol(row,mid+1,right,target);
			}
		}
};

int main()
{
	vector<int> a1(1);
	vector<vector<int> > a;
	a.push_back(a1);
	Solution s;
	s.searchMatrix(a, 1);
	return 0;
}
