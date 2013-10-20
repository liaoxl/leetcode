#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>


using namespace std;

class Solution{
	public:
		bool wordBreak(string s, unordered_set<string> &dict){
			int len=s.length();
			vector<bool> word(len+1, false);
			word[0]=true;
			for(int i=1; i<=len; i++)
			{
				for(int j=i-1; j>=0; j--)
				{
					if(word[j] && dict.find(s.substr(j,i-j))!=dict.end())
					{
						word[i]=true;
						break;
					}
				}
			}
			return word[len];
		}
};

int main()
{
	return 0;
}
