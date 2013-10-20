#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
	public:
		vector<vector<int> > levelOrder(TreeNode *root)
		{
			vector<vector<int> > res;
			vector<int> level;

			if(root==NULL)
			{
				return res;
			}

			queue<TreeNode *> tval;
			tval.push(root);
			while(!tval.empty())
			{
				int len=tval.size();
				level.clear();
				while(len-->0)
				{
					level.push_back(tval.front()->val);
					if(tval.front()->left!=NULL)
					{
						tval.push(tval.front()->left);
					}
					if(tval.front()->right!=NULL)
					{
						tval.push(tval.front()->right);
					}
					tval.pop();
				}
				res.push_back(level);
			}
			reverse(res.begin(), res.end());
			return res;
		}
};

int main()
{
	return 0;
}
