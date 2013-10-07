#include <iostream>

using namespace std;

class Solution{
	public:
		int lengthOfLastWord(const char *s){
			int len=0;
			int index=0;
			int tmp=0;
			while(s[index]!='\0')
			{
				if(s[index]!=' ')
				{
					tmp++;
					len=tmp;
				}
				else
				{
					tmp=0;
				}
				index++;
			}
			if(tmp>0)
			{
				return tmp;
			}
			return len;
		}
};

int main()
{
	char s[]="hello world ";
	Solution ss;
	cout << ss.lengthOfLastWord(s) << endl;
	return 0;
}
