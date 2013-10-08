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
		bool isValidBST(TreeNode *root)
		{
			if(root==NULL)
			{
				return true;
			}
			if(root->left==NULL && root->right==NULL)
			{

				return true;
			}
			if(root->left!=NULL && root->left->val >= root->val)
			{
				return false;
			}
			if(root->right!=NULL && root->right->val <= root->val)
			{
				return false;
			}
			if(root->left!=NULL)
			{
				return isValidBST(root->left);
			}
			if(root->right!=NULL)
			{
				return isValidBST(root->right);
			}
		}
};

int main()
{
	return 0;
}
