#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
			int flag=0;

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
				if(flag%2!=0)
				{
				    reverse(level.begin(), level.end());
				}
				flag++;
				res.push_back(level);
			}

			return res;
		}
};

int main()
{
	TreeNode root(1);
	root.left=new TreeNode(2);
	root.right=new TreeNode(3);
	root.left->left=new TreeNode(4);
	root.right->right=new TreeNode(5);
	Solution s;
	s.levelOrder(&root);
	return 0;
}
