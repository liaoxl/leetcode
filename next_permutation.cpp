#include <iostream>
#include <vector>

using namespace std;

class Solution{
	public:
		void nextPermutation(vector<int> &num)
		{
			int len=num.size();
			int left=-1,right=-1;
			int leftval=0;
			for(int i=0; i<len; i++)
			{
				leftval=num[i];
				int tmpi=i;
				while(tmpi<len && num[tmpi]<=leftval)
				{
					tmpi++;
				}
				if(tmpi==len)
				{
					continue;
				}
				else
				{
					left=i;
					right=tmpi;
				}
			}
			if(right!=-1)
			{
				int tmpval=num[left];
				num[left]=num[right];
				num[right]=tmpval;
			}
			else{
				for(int i=0; i<len/2; i++)
				{
					int tmpval=num[i];
					num[i]=num[len-1-i];
					num[len-1-i]=tmpval;
				}
			}
		}
};

int main()
{
	vector<int> data;
	data.push_back(1);
	data.push_back(2);
	data.push_back(3);
	Solution s;
	s.nextPermutation(data);
	return 0;
}
