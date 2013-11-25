/*
 * unique_binary_search_trees2.cpp
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
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return generate(1, n);
    }
    
    vector<TreeNode *> generate(int l_bound, int h_bound) {
        vector<TreeNode *> result;
        if (l_bound>h_bound) {
            result.push_back(NULL);
            return result;
        }
        for (int i=l_bound; i<=h_bound; i++) {
    
            vector<TreeNode *> leftTrees = generate(l_bound, i-1);
            vector<TreeNode *> rightTrees = generate(i+1, h_bound);
            for(int left = 0; left < leftTrees.size(); left++) {
                for(int right = 0; right < rightTrees.size(); right++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftTrees[left];
                    root->right = rightTrees[right];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

