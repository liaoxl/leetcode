/*
 * binary_tree_level_order_traversal.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        			vector<vector<int> > res;
			vector<int> level;

			if(root==NULL)
			{
				return res;
			}

			queue<TreeNode *> tval;
			tval.push(root);
			while(!tval.empty())
			{
				int len=tval.size();
				level.clear();
				while(len-->0)
				{
					level.push_back(tval.front()->val);
					if(tval.front()->left!=NULL)
					{
						tval.push(tval.front()->left);
					}
					if(tval.front()->right!=NULL)
					{
						tval.push(tval.front()->right);
					}
					tval.pop();
				}
				res.push_back(level);
			}
			return res;

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

