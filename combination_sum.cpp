#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<vector<int> > res;
    vector<int> tmp;

    void dfs(int start, int n, int target, vector<int> d)
    {
        if(target==0)
        {
			res.push_back(tmp);
            return;
        }
		if(target<=0 || start>=n) return;
        tmp.push_back(d[start]);
        dfs(start, n, target-d[start], d);
		tmp.pop_back();
		dfs(start+1,n,target,d);
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        res.clear();
        tmp.clear();
        int n=candidates.size();
        if(n==0)
        {
            return res;
        }
        sort(candidates.begin(), candidates.end());
        dfs(0,n,target,candidates);
        sort(res.begin(),res.end());
        vector<vector<int> >::iterator it;
        it=unique(res.begin(),res.end());
        res.resize(distance(res.begin(), it));

        return res;
    }
};

int main()
{
	int a[]={27,26,13,19,14,11,15,19,14,15,12,9,5,8,17,30,20,16,22,10,15,22,12,27,19,6,32,31,5,32,32,27,23,10,33,32,16,14,9,17,24,16,13,25,19,26,20,27,29,7,24,31,24,31,24,31,32,13,19,25,32,17,17,12,22,16,32,26,25};
	vector<int> data(a,a+sizeof(a)/4);
	Solution s;
	s.combinationSum(data, 21);
	return 0;
}
