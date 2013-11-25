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

/**
 * Definition for binary tree
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
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
	
	return 0;
}

