#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution{
	public:
		int largestRectangleArea(vector<int> &height) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len=height.size();
        if(len<1) return 0;
        stack<int> mystack;
        int i=0;
        int maxa=0;
        while(i<len)
        {
            if(mystack.empty() || height[mystack.top()]<=height[i])
            {
                mystack.push(i++);
            }
            else
            {
                int tmpi=mystack.top();
                mystack.pop();
                int tmparea=height[tmpi]*(mystack.empty()?i:i-mystack.top()-1);
                if(tmparea > maxa) maxa=tmparea;
            }
        }
        while(!mystack.empty())
        {
            int tmpi=mystack.top();
            mystack.pop();
            int tmparea=height[tmpi]*(mystack.empty()?i:i-mystack.top()-1);
            if(tmparea > maxa) maxa=tmparea;
        }
        return maxa;
    }
		int maximalRectangle(vector<vector<char> > &matrix)
		{
			int m=matrix.size();
			if(m==0) return 0;
			int n=matrix[0].size();
			if(n==0) return 0;

			vector<vector<int> > hist(m, vector<int>(n,0));
			for(int i=0; i<n; i++)
			{
				hist[0][i]=matrix[0][i]=='1'?1:0;
			}
			for(int i=1; i<m; i++)
			{
				for(int j=0; j<n; j++)
				{
					if(matrix[i][j]=='1')
					{
						hist[i][j]+=hist[i-1][j]+1;
					}
				}
			}
			int maxr=0;
			for(int i=0; i<m; i++)
			{
				int tmp=largestRectangleArea(hist[i]);
				if(tmp>maxr) maxr=tmp;
			}
			return maxr;

		}
};

int main()
{
	char c[]="01";
	vector<char> tmp(c,c+2);
	vector<vector<char> > data(2,tmp);
	Solution s;
	cout << s.maximalRectangle(data) << endl;
	return 0;
}
