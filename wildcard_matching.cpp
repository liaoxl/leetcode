#include <iostream>

using namespace std;

class Solution{
	public:
		bool isMatch(const char *s, const char *p)
		{
			if(s==NULL || p==NULL ) return false;
			if(*p=='\0') return *s=='\0';

			if(*p!='*')
			{
				return ((*p==*s)||(*p=='?'&&*s!='\0')) && isMatch(s+1, p+1);
			}

			while(*s!='\0')
			{
				if(isMatch(s,p+1)) return true;
				s++;
			}
			return isMatch(s,p+1);
		}
};

int main()
{
	return 0;
}
