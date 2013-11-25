/*
 * binary_tree_inorder_traversal.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

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
    vector<int> inorderTraversal(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> res;
        if(root==NULL)
        {
            return res;
        }
        if(root->left==NULL && root->right==NULL)
        {
            res.push_back(root->val);
            return res;
        }
        res=inorderTraversal(root->left);
        res.insert(res.end(), root->val);
        vector<int> tmp=inorderTraversal(root->right);
        res.insert(res.end(),tmp.begin(),tmp.end());
        return res;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

