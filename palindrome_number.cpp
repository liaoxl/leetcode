#include <iostream>

using namespace std;

class Solution{
public:
	bool isPalindrome(int x){
		if(x==0)
		{
			return true;
		}
		if(x<0)
		{
			return false;
		}
		int tmp;
		int cnt=0;
		tmp=1;
		while(x/tmp >= 10)
		{
			tmp*=10;
		}
		while(x>=10)
		{
			cnt=0;
			if(x%10 != x/tmp)
			{
				return false;
			}
			x=(x-(x/tmp)*tmp-x%10)/10;
			tmp/=100;
		}
		return true;
	}
};

int main()
{
	Solution s;
	int n;
	cin >> n;

	if(s.isPalindrome(n))
	{
		cout << " YES" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}
