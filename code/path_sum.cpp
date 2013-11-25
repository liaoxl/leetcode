/*
 * path_sum.cpp
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
    bool hasPathSum(TreeNode *root, int sum) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
       		if(root==NULL)
			{
				return false;
			}
			if(root->val==sum && root->left==NULL && root->right==NULL)
			{
				return true;
			}
			if(root->left==NULL)
			{
				return hasPathSum(root->right, sum-root->val);
			}
			else if(root->right==NULL)
			{
				return hasPathSum(root->left, sum-root->val);
			}
			else
			{
				return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
			}
 
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

