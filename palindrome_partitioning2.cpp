#include <iostream>
#include <vector>
#include <string>

#define INT_MAX 100000

using namespace std;


class Solution {
public:
    bool isPalin(int start, int end, string s)
    {
        while(start<end)
        {
            if(s[start]!=s[end]) return false;
            start++,end--;
        }
        return true;
    }

    void dfs(int start, int n, string s, vector<string> &str, vector<vector<string> > &res)
    {
        if(start==n)
        {
            if(res.size()==0)
            {
                res.push_back(str);
                return;
            }
            else if(res[0].size()>str.size())
            {
                res.pop_back();
                res.push_back(str);
                return;
            }
            return;
        }
		int k=n-1;
		while(k>=start)
		{
			if(isPalin(start,k,s))
			{
				break;
			}
			k--;
		}
		str.push_back(s.substr(start,k-start+1));
		dfs(k+1,n,s,str,res);
    }
    int minCut(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<string> > res;
        vector<string> str;
        int n=s.length();
        dfs(0,n,s,str,res);
        int minc=INT_MAX;
        for(int i=0; i<res.size(); i++)
        {
            if(res[i].size()<minc) minc=res[i].size();
        }
        return minc;
    }
};

int main()
{
	return 0;
}
