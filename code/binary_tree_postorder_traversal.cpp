/*
 * binary_tree_postorder_traversal.cpp
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
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        	vector<int> res;
			if(root==NULL) return res;
			stack<TreeNode *> mystack;
			stack<int> myres;

			mystack.push(root);

			while(!mystack.empty())
			{
				TreeNode *p=mystack.top();
				myres.push(p->val);
				mystack.pop();
				if(p->left!=NULL)
				{
					mystack.push(p->left);
				}
				if(p->right!=NULL)
				{
					mystack.push(p->right);
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
	
	return 0;
}

