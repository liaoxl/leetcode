/*
 * symmetric_tree.cpp
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
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(root==NULL)
        {
            return true;
        }
        return isSymSubTree(root, root);
    }
    bool isSymSubTree(TreeNode* tleft, TreeNode* tright)
    {
        if(tleft==NULL && tright==NULL)
        {
            return true;
        }
        else if(tleft==NULL || tright==NULL)
        {
            return false;
        }
        return tleft->val==tright->val && isSymSubTree(tleft->left, tright->right) && isSymSubTree(tleft->right, tright->left);
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

