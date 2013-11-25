/*
 * path_sum2.cpp
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
    vector<vector<int> > res;
    vector<int> tmp;

    bool isLeaf(TreeNode *node)
    {
        return node!=NULL && node->left==NULL && node->right==NULL;
    }

    void dfs(int sum, TreeNode *cur)
    {
        if(cur==NULL)
        {
            return;
        }
        tmp.push_back(cur->val);
        if(sum==cur->val && isLeaf(cur))
        {
            res.push_back(tmp);
            tmp.pop_back();
            return;
        }
        if(cur->left!=NULL)
        {
            dfs(sum-cur->val, cur->left);
        }
        if(cur->right!=NULL)
        {
            dfs(sum-cur->val, cur->right);
        }
        tmp.pop_back();
    }

public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        res.clear();
        tmp.clear();
        dfs(sum,root);
        return res;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

