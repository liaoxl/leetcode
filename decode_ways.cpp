#include <iostream>
#include <string>

using namespace std;


class Solution{
	public:
		bool isValid(string s)
		{
			int len=s.length();
			if(len<1 || len>2) return false;
			int sum=0;
			for(int i=0; i<len; i++)
			{
				sum*=10;
				sum+=s[i]-'0';
			}
			if(sum>=1 && sum<=26) return true;
			return false;
		}

		int numDecodings(string s){
			int len=s.length();
			if(len==0 || len==1) return len;
			int* dp=new int[len+1];
			for(int i=0; i<=len; i++)
			{
				dp[i]=0;
			}
			dp[0]=1;
			dp[1]=1;
			for(int i=2; i<=len; i++)
			{
				if(isValid(s.substr(i-1,1)))
					dp[i]=dp[i-1];
				if(isValid(s.substr(i-2,2)))
					dp[i]+=dp[i-2];
			}
			return dp[len];
		}
};

int main()
{
	string s="12";
	Solution so;
	cout << so.numDecodings(s) << endl;
	return 0;
}
