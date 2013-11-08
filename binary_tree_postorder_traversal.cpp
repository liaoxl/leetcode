/*
 * binary_tree_preorder_traversal.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <stack>
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
		vector<int> preorderTraversal(TreeNode *root)
		{
			vector<int> res;
			if(root==NULL) return res;
			stack<TreeNode *> myqueue;
			stack<int> myres;

			myqueue.push(root);

			while(!myqueue.empty())
			{
				TreeNode *p=myqueue.top();
				myres.push(p->val);
				myqueue.pop();
				if(p->left!=NULL)
				{
					myqueue.push(p->left);
				}
				if(p->right!=NULL)
				{
					myqueue.push(p->right);
				}
			}

			while(!myres.empty())
			{
				res.push_back(myres.top());
				myres.pop();
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

