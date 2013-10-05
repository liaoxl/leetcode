#include <iostream>
#include <vector>

using namespace std;

class Solution{
	public:
		int maxArea(vector<int> &height){
			int len=height.size();
			int maxarea=0;
			int tmparea=0;
			for(int i=0; i<len; i++)
			{
				for(int j=i+1; j<len; j++)
				{
					int hgt=height[i]<=height[j]?height[i]:height[j];
					tmparea=(j-i)*hgt;
					if(tmparea>maxarea)
					{
						maxarea=tmparea;
					}
				}
			}
			return maxarea;
		}
};


int main()
{
	return 0;
}
