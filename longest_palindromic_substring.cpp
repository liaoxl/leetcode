#include <iostream>
#include <string>

using namespace std;

int findmaxd(string s, int ind, int mind)
{
	int i=mind;
	int len=s.length();
	while(ind-i>=0 && ind+i<len && s[ind-i]==s[ind+i])
	{
		i++;
	}
	return i;
}

class Solution{
	public:
		string longestPalindrome(string s){
			int len=s.length();
			int i=0;
			for(i=0; i<= len; i++)
			{
				s.insert(2*i, "#");
			}
			int tlen=s.length();
			int p=1;
			int max=0;
			int index=0;
			for(i=1; i<tlen; i++)
			{
				p=findmaxd(s,i,1);
				if(p>max)
				{
					max=p;
					index=i;
				}
			}
			s=s.substr(index-max+1,2*(max-1));
			string::iterator it;
			for(it=s.begin();it!=s.end();)
			{
				if(*it=='#')
				{
					s.erase(it);
					continue;
				}
				++it;
			}
			return s;
		}

		string longestPsubstring(string s)
		{
			int len=s.length();
			int i=0;
			for(i=0; i<= len; i++)
			{
				s.insert(2*i, "#");
			}
			int tlen=s.length();

			int* p=new int[tlen];

			return s;
		}

};


int main()
{
	string str;
	cin >> str;
	Solution s;
	cout << s.longestPsubstring(str) << endl;
	return 0;
}
