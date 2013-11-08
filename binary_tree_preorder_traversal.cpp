/*
 * binary_tree_preorder_traversal.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
	public:
		vector<int> preorderTraversal(TreeNode *root)
		{
			vector<int> res;
			if(root==NULL) return res;
			stack<TreeNode *> mystack;

			mystack.push(root);

			while(!mystack.empty())
			{
				TreeNode *p=mystack.top();
				mystack.pop();
				res.push_back(p->val);
				if(p->right!=NULL)
				{
					mystack.push(p->right);
				}
				if(p->left!=NULL)
				{
					mystack.push(p->left);
				}
			}

			return res;
		}
};

int main(int argc, char* argv[])
{
	TreeNode root(2);
	root.left=new TreeNode(1);
	root.right=new TreeNode(4);

	Solution s;
	s.preorderTraversal(&root);
	return 0;
}

