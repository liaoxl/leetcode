/*
 * same_tree.cpp
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(p==NULL && q==NULL)
        {
            return true;
        }
        if((p!=NULL && q==NULL) || (p==NULL && q!=NULL))
        {
            return false;
        }
        if(p->val != q->val)
        {
            return false;
        }
        if((p->left!=NULL && q->left==NULL) || (p->left==NULL && q->left!=NULL))
        {
            return false;
        }
        if((p->right!=NULL && q->right==NULL) || (p->right==NULL && q->right!=NULL))
        {
            return false;
        }
        
        if(p->left!=NULL && q->left!=NULL)
        {
            if(!isSameTree(p->left, q->left))
            {
                return false;
            }
        }
        if(p->right!=NULL && q->right!=NULL)
        {
            if(!isSameTree(p->right, q->right))
            {
                return false;
            }
        }
        return true;
        
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

