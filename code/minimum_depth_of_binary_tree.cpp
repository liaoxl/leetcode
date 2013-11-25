/*
 * minimum_depth_of_binary_tree.cpp
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

class Solution {
public:
    int minDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        	if(root==NULL)
			{
				return 0;
			}
			if(root->left==NULL && root->right==NULL)
			{
				return 1;
			}
			else if(root->left!=NULL && root->right==NULL)
			{
				return 1+minDepth(root->left);
			}
			else if(root->left==NULL && root->right!=NULL)
			{
				return 1+minDepth(root->right);
			}
			else
			{
				return 1+min(minDepth(root->left), minDepth(root->right));
			}
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

