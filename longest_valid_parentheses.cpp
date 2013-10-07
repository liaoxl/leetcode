#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution{
	public:
		int longestValidParentheses(string s){
			int len=s.length();
			stack<char> valids;
			if(len==0)
			{
				return 0;
			}
			valids.push(s[0]);
			int index=1;
			while(index<len)
			{
				if(!valids.empty() && (valids.top()=='(' && s[index]==')'))
				{
					valids.pop();
				}
				else
				{
					valids.push(s[index]);
				}
				index++;
			}
			return len-valids.size();
		}
};

int main()
{
	string s="((()))";
	return 0;
}
