/*
 * recover_binary_search_tree.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

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

class Solution 
{
public:
	TreeNode *prev;
	TreeNode *itema, *itemb;

	void traverse(TreeNode *root)
	{
		if(!root) return;
		traverse(root->left);
		if(prev)
		{
			if(itema && root->val > itema->val)
				itemb = prev;
			if(!itema && prev->val > root->val)
				itema = prev;
			// pay attention!
			if (itema && itemb)
				return;
		}
		prev = root;
		traverse(root->right);
	}
     void recoverTree(TreeNode *root) 
	{
		prev = itema = itemb = NULL;
		traverse(root);
		if (itema && !itemb)
			itemb = prev;
		if (itema && itemb)
		{
			int temp = itema->val;
			itema->val = itemb->val;
			itemb->val = temp;
		}
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

