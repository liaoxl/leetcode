#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeLinkNode{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution{
	public:
		void connect(TreeLinkNode *root)
		{
			if(root==NULL)
			{
				return;
			}
			queue<TreeLinkNode *> tln;
			tln.push(root);

			while(!tln.empty())
			{
				int len=tln.size();
				TreeLinkNode *curnext=NULL;
				while(len-->0)
				{
					tln.front()->next=curnext;
					curnext=tln.front();
					if(tln.front()->right!=NULL)
					{
						tln.push(tln.front()->right);
					}
					if(tln.front()->left!=NULL)
					{
						tln.push(tln.front()->left);
					}
					tln.pop();
				}
			}
		}
};

int main()
{
	return 0;
}
