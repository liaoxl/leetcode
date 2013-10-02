#include <iostream>
#include <string>

using namespace std;

bool notRepeating(string s)
{
	int checker=0;
	for(int i=0; i<s.length(); i++)
	{
		int val=s[i]-'a';
		if((checker & (1<<val)) > 0)
		{
			return false;
		}
		checker |= (1<<val);
	}
	return true;
}
class Solution{
	public:
		int lengthOfLongestSubstring(string s)
		{
			int n=s.length();
			while(n)
			{
				for(int i=0; i+n<=s.length(); i++)
				{
					if(notRepeating(s.substr(i,n)))
					{
						return n;
					}
				}
				n--;
			}
		}
};


int main()
{
	string str;
	cin >> str;
	Solution s;
	cout << s.lengthOfLongestSubstring(str) << endl;
	
	return 0;
}
