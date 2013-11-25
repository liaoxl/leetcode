/*
 * flatten_binary_tree_to_linked_list.cpp
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
    void flatten(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        	if(root==NULL)
			{
				return;
			}
			TreeNode *left=root->left;
			TreeNode *right=root->right;

			if(left)
			{
				root->right=left;
				root->left=NULL;

				TreeNode* lRightmost=left;

				while(lRightmost->right)
				{
					lRightmost=lRightmost->right;
				}
				lRightmost->right=right;
			}
			flatten(root->right);

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

