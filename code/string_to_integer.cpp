/*
 * string_to_integer.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131114/leetcode-atoi/
 * Distributed under terms of the MIT license.
 */

#include <iostream>

#define INT_MIN -1000000
#define INT_MAX 1000000

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
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

int main(int argc, char* argv[])
{
	
	return 0;
}

