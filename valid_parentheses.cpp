#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution{
	public:
		bool isValid(string s){
			int len=s.length();
			if(len==0)
			{
				return true;
			}
			if(len%2!=0)
			{
				return false;
			}
			stack<char> valid;
			len=0;
			valid.push(s[len]);
			len++;
			while(s[len]!='\0')
			{
				if(!valid.empty() && ((valid.top()=='('&&s[len]==')') || (valid.top()=='['&&s[len]==']') || (valid.top()=='{'&&s[len]=='}')))
				{
					valid.pop();
				}
				else
				{
					valid.push(s[len]);
				}
				len++;
			}
			if(!valid.empty())
			{
				return false;
			}
			return true;
		}
};

int main()
{
	string s="[](){}";
	Solution ss;
	if(ss.isValid(s))
	{
		cout << "YES" << endl;
		return 0;
	}
	return 0;
}
