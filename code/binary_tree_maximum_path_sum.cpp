/*
 * binary_tree_maximum_path_sum.cpp
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
    int res=0;
    int DFS(TreeNode *root){
        if(root==NULL)  return 0;
        int l=DFS(root->left);
        int r=DFS(root->right);
        int v=root->val;
        if(l>0) v+=l;
        if(r>0) v+=r;
        if(v>res) res=v;
        return max(root->val+max(l,r),root->val);
    }
    int maxPathSum(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(root==NULL)  return 0;
        res=root->val;
        DFS(root);
        return res;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

