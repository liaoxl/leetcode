/*
 * sum_root_to_leaf_numbers.cpp
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
    int sumNumbers(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
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

int main(int argc, char* argv[])
{
	
	return 0;
}

