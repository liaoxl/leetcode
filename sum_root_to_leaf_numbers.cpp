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
		int sumNumbers(TreeNode *root)
		{
			if(root==NULL)
			{
				return 0;
			}
			if(root->left==NULL && root->right==NULL)
			{
				return root->val;
			}
			if(root->left==NULL)
			{
				root->right->val+=root->val*10;
				return sumNumbers(root->right);
			}
			if(root->right==NULL)
			{
				root->left->val+=root->val*10;
				return sumNumbers(root->left);
			}
			root->left->val+=root->val*10;
			root->right->val+=root->val*10;
			return sumNumbers(root->left)+sumNumbers(root->right);
		}
};

int main()
{
	return 0;
}
