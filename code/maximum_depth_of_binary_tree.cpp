/*
 * maximum_depth_of_binary_tree.cpp
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
    int maxDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        	if(root==NULL)
			{
				return 0;
			}
			int len=1+max(maxDepth(root->left), maxDepth(root->right));
			return len;

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

