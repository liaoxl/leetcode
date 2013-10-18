#include <iostream>
#include <string>

using namespace std;

class Solution{
	public:
		int numDistinct(string S, string T)
		{
			int slen=S.length();
			int tlen=T.length();
			if(tlen==0)
			{
				return 1;
			}
			else if(slen==0)
			{
				return 0;
			}
			int **p=new int*[tlen+1];
			for(int i=0; i<=tlen; i++)
			{
				p[i]=new int[slen+1];
			}
			for(int i=0; i<=tlen; i++)
			{
				for(int j=0; j<=slen; j++)
				{
					p[i][j]=0;
				}
			}
			p[0][0]=1;
			for(int i=1; i<=tlen; i++)
			{
				p[i][0]=0;
			}
			for(int i=1; i<=slen; i++)
			{
				p[0][i]=1;
			}
			for(int i=1; i<=tlen; i++)
			{
				for(int j=1; j<=slen; j++)
				{
					p[i][j]=p[i][j-1];
					if(T[i-1]==S[j-1])
					{
						p[i][j]+=p[i-1][j-1];
					}
				}
			}
			int res=p[tlen][slen];
			for(int i=0; i<=tlen; i++)
			{
				delete [] p[i];
			}
			delete [] p;
			return res;
		}
};

int main()
{
	string S="ccc";
	string T="c";
	Solution s;
	cout << s.numDistinct(S,T) << endl;
	return 0;
}
