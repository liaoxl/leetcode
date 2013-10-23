#include <iostream>
#include <vector>
#include <queue>

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
				if(!flag)
				{
					while(len-->0)
					{
						level.push_back(tval.front()->val);
						if(tval.front()->right!=NULL)
						{
							tval.push(tval.front()->right);
						}
						if(tval.front()->left!=NULL)
						{
							tval.push(tval.front()->left);
						}
						tval.pop();
					}
					flag=1;
				}
				else
				{
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
					flag=0;
				}
				res.push_back(level);
			}
			return res;
		}
};

int main()
{
	return 0;
}
