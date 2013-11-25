/*
 * construct_binary_tree_from_preorder_and_inorder_travesal.cpp
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
    TreeNode *buildmyTree(vector<int> &preorder, int lp, int rp, vector<int> &inorder, int li, int ri) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int len=preorder.size();
            if(len==0||lp>=rp||li>=ri) return NULL;
            TreeNode *root= new TreeNode(preorder[lp]);
            int i=li;
            for(; i<ri; i++)
            {
                if(inorder[i]==preorder[lp])
                {
                    break;
                }
            }
            root->left=buildmyTree(preorder,lp+1, lp+i-li+1, inorder, li, i);
            root->right=buildmyTree(preorder,lp+i-li+1, rp, inorder, i+1, ri);
            return root;
        }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return buildmyTree(preorder,0,preorder.size(), inorder, 0, inorder.size());
    }
    
};

int main(int argc, char* argv[])
{
	
	return 0;
}

