#include <iostream>
#include <string>

using namespace std;


class Solution{
	public:
		string addBinary(string a, string b){
			int alen=a.length();
			int blen=b.length();
			if(alen==0)
			{
				return b;
			}
			if(blen==0)
			{
				return a;
			}
			int addon=1;

			if(alen>=blen)
			{
				addon=0;
				while(blen>0)
				{
					int val=a[alen-1]-'0'+b[blen-1]-'0'+addon;
					addon=val/2;
					a[alen-1]='0'+val%2;
					alen--,blen--;
				}
				while(alen>0)
				{
					int val=a[alen-1]-'0'+addon;
					addon=val/2;
					a[alen-1]='0'+val%2;
					alen--;
				}
				if(alen==0 && addon==1)
				{
					a.insert(a.begin(),'1');
				}
				return a;
			}
			else
			{
				addon=0;
				while(alen>0)
				{
					int val=a[alen-1]-'0'+b[blen-1]-'0'+addon;
					addon=val/2;
					b[blen-1]='0'+val%2;
					alen--,blen--;
				}
				while(blen>0)
				{
					int val=b[blen-1]-'0'+addon;
					addon=val/2;
					b[blen-1]='0'+val%2;
					blen--;
				}
				if(blen==0 && addon==1)
				{
					b.insert(b.begin(),'1');
				}
				return b;
			}
		}
};


int main()
{
	string a="11";
	string b="11";
	Solution s;
	cout << s.addBinary(a,b) << endl;
	return 0;
}
