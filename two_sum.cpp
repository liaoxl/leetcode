#include <iostream>
#include <vector>

using namespace std;

class Solution{
	public:
		vector<int> twoSum(vector<int> &numbers, int target){
			//Start typing your C/C++ solution below
			int len=numbers.size();
			int i,j;
			vector<int> res;
			for(i=0; i<len; i++)
			{
				for(j=i+1; j<len; j++)
				{
					if(numbers[i]+numbers[j] == target)
					{
						res.push_back(i+1);
						res.push_back(j+1);
					}
				}
			}
			return res;
		}
};

int main(void)
{
	cout << "hello world" << endl;
	vector<int> num;
	int n;
	while(cin >> n)
	{
		if(n==0)
			break;
		num.push_back(n);
	}
	int tar;
	cin >> tar;
	Solution s;
	vector<int> r;
	r=s.twoSum(num, tar);
	int i=0;
	for(i=0; i < r.size(); i++)
	{
		cout << r[i] << " ";
	}
	cout << endl;
	return 0;
}
