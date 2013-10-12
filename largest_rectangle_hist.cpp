#include <iostream>
#include <vector>

using namespace std;

class Solution{
	public:
		int largestRectangleArea(vector<int> &height)
		{
			int len=height.size();
			int maxa=0;
			int minh=0;
			for(int i=0; i<len; i++)
			{
				minh=height[i];
				for(int j=i+1; j<len; j++)
				{
					if(height[j]<minh)
					{
						minh=height[j];
					}
					int tmp=minh*(j-i);
					if(tmp>maxa)
					{
						maxa=tmp;
					}
				}
			}
			return maxa;
		}
};

int main()
{
	return 0;
}
