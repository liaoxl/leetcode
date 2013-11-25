/*
 * validate_binary_search_tree.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

#define INT_MAX 100000
#define INT_MIN -100000

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
    bool isValidBST(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int minr=INT_MIN;
        int maxr=INT_MAX;
        return checkValid(root, minr, maxr);
    }
    bool checkValid(TreeNode *root, int minr, int maxr)
    {
        if(!root) return true;
        if(root->val>minr&&root->val<maxr && checkValid(root->left, minr, root->val) && checkValid(root->right, root->val, maxr))
        {
            return true;
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

