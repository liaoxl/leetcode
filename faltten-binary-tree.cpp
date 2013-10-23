#include <iostream>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
	public:
		void flatten(TreeNode *root)
		{
			if(root==NULL)
			{
				return;
			}
			TreeNode *left=root->left;
			TreeNode *right=root->right;

			if(left)
			{
				root->right=left;
				root->left=NULL;

				TreeNode* lRightmost=left;

				while(lRightmost->right)
				{
					lRightmost=lRightmost->right;
				}
				lRightmost->right=right;
			}
			flatten(root->right);
		}
};

int main()
{
	return 0;
}
