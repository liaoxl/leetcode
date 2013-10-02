#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int isflag=1;
        long long int div=0;
        long long int tend=abs((double)dividend);
        long long int tsord=abs((double)divisor);
        if(dividend>0 && divisor<0)
        {
            isflag=0;
        }
        else if(dividend<0 && divisor>0)
        {
            isflag=0;
        }
        else if(tend==0 || tsord==0)
        {
            return 0;
        }
        if(tsord==1)
        {
            div=tend;
        }
        else
        {
            div=0;
            long long int cur=1;
            long long int tsor=tsord;
            while(tend-tsord>=0)
            {
                cur=1;
                while(tend>=(tsor<<1))
                {
                    tsor=tsor<<1;
                    cur=cur<<1;
                }
                div+=cur;
                tend-=tsor;
                tsor=tsord;
            }
        }
        if(!isflag)
        {
            div=0-div;
        }
        return div;
    }
};
int main()
{

	int m,n;
	cin >> m >> n;
	Solution s;
	cout << s.divide(m,n) << endl;
	return 0;
}
