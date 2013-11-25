/*
 * construct_binary_tree_from_inorder_and_postorder_traversal.cpp
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
    TreeNode *buildmyTree(vector<int> &inorder, int lp, int rp, vector<int> &postorder, int li, int ri) {

        int len=inorder.size();
        if(len==0||lp>=rp||li>=ri || ri<1 || rp<1) return NULL;
        TreeNode *root= new TreeNode(postorder[ri-1]);
        int i=lp;
        for(; i<rp; i++)
        {
            if(inorder[i]==postorder[ri-1])
            {
                break;
            }
        }
        root->left=buildmyTree(inorder,lp, i, postorder, li, li+i-lp);
        root->right=buildmyTree(inorder,i+1, rp, postorder, li+i-lp, ri-1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    // Note: The Solution object is instantiated only once and is reused by each test case.
        return buildmyTree(inorder,0,inorder.size(), postorder, 0, postorder.size());
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

