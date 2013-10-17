#include <iostream>
#include <string>

using namespace std;

class Solution{
	public:
		bool isInterleave(string s1, string s2, string s3)
		{
			int len1=s1.length();
			int len2=s2.length();
			int len3=s3.length();

			if(len1+len2 != len3)
			{
				return false;
			}
			if(len3==0)
			{
				return true;
			}

			int i1=0, i2=0, i3=0;

			while(i3<len3)
			{
				if(s1[i1]==s3[i3])
				{
					i1++,i3++;
				}
				else if(s2[i2]==s3[i3])
				{
					i2++,i3++;
				}
				else
				{
					return false;
				}
			}
			return true;
		}
};

int main()
{
	return 0;
}
