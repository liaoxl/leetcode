#include <iostream>

using namespace std;

class Solution{
	public:
		int atoi(const char *str){
			int i=0;
			int flag=0;
        	int j=0;
			while(str[i]!='\0')
			{
				if(str[i]>'0' && str[i]<='9')
				{
					break;
				}
				i++;
			}
			while(str[j]!='\0')
			{
			    if((str[j]<'0' || str[j]>'9') && !(str[j]=='-'||str[j]=='+'||str[j]==' '))
			    {
			        return 0;
			    }
				if(str[j]>='0' && str[j]<='9' || str[j]=='-' || str[j]=='+')
				{
					break;
				}
				j++;
			}
			if(str[j]=='-' || (j>=1&&str[j]=='-'))
			{
			    flag=1;
			}
			for(int k=j;k<=i;k++)
			{
			    if((str[k]<'0' || str[k]>'9') && !(str[k]=='-'||str[k]=='+'))
			    {
			        return 0;
			    }
			    if(k>j && (str[k]=='-'||str[k]=='+'))
			    {
			        return 0;
			    }
			}
			long long int res=0;
			long long int mres=0;
			while(str[i]!='\0' && str[i]>='0' && str[i]<='9')
			{
				res=res*10+str[i]-'0';
				if(flag)
				{
				    mres=-res;
				}
				else
				{
				    mres=res;
				}
				if(mres>INT_MAX)
				{
					return INT_MAX;
				}
				else if(mres<INT_MIN)
				{
					return INT_MIN;
				}
				i++;
			}
			return mres;
	
		}
};

int main()
{
	char s[]="-0012a42";
	Solution ss;
	cout << ss.atoi(s) << endl;
	return 0;
}
