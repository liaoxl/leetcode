#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution{
	public:
		vector<vector<int> > threeSum(vector<int> &num)
		{
			vector<vector<int> > res;
			set<vector<int> > tmpset;
			vector<int> tmp;
			int len=num.size();
			for(int i=0; i<len; i++ )
			{
				for(int j=i+1; j<len; j++)
				{
					for(int k=j+1; k<len; k++)
					{
						if(num[i]+num[j]+num[k]==0)
						{
							int tmpmin=min(num[i], min(num[j], num[k]));
							tmp.push_back(tmpmin);
							if(tmpmin==num[i])
							{
								tmp.push_back(min(num[j], num[k]));
								tmp.push_back(max(num[j], num[k]));
							}
							else if(tmpmin==num[j])
							{
								tmp.push_back(min(num[i], num[k]));
								tmp.push_back(max(num[i], num[k]));
							}
							else if(tmpmin==num[k])
							{
								tmp.push_back(min(num[i], num[j]));
								tmp.push_back(max(num[i], num[j]));
							}
							if(tmpset.count(tmp)==0)
							{
								res.push_back(tmp);
							}
							tmpset.insert(tmp);
							tmp.clear();
						}
					}
				}
			}
			return res;
		}
};

int main()
{
	vector<int> data;
	data.push_back(-1);
	data.push_back(0);
	data.push_back(1);
	data.push_back(2);
	data.push_back(-1);
	data.push_back(-4);
	Solution s;
	s.threeSum(data);
	return 0;
}
