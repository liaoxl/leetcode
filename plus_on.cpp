#include <iostream>
#include <vector>

using namespace std;

class Solution{
	public:
		vector<int> plusOne(vector<int> &digits){
			int sz=digits.size();
			if(sz==0)
			{
				digits.push_back(1);
			}
			digits[sz-1] += 1;
			vector<int>::iterator it;
			while(sz>=1 && digits[sz-1]>=10)
			{
				if(sz==1)
				{
					it=digits.begin();
					int tmp=digits[sz-1]/10;
					digits[sz-1]=digits[sz-1]%10;
					digits.insert(it,tmp);
				}
				else
				{
					digits[sz-2] += digits[sz-1]/10;
					digits[sz-1] = digits[sz-1]%10;
					sz=sz-1;
				}
			}
			return digits;
		}
};

int main()
{
	vector<int> a;
	cout << a.size() << endl;
	for(int i=0; i<10; i++)
	{
		a.push_back(9);
	}
	vector<int>::iterator it;
	it=a.begin();
	cout << a.size() << endl;
	Solution s;
	a=s.plusOne(a);
	for(int i=0; i<a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
