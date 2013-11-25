/*
 * binary_tree_zigzag_level_order_traversal.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <queue>
#include <algorithm>

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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        	vector<vector<int> > res;
			vector<int> level;

			if(root==NULL)
			{
				return res;
			}

			queue<TreeNode *> tval;
			tval.push(root);
			int flag=0;
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
				if(flag%2!=0)
				{
				    reverse(level.begin(), level.end());
				}
				flag++;
				res.push_back(level);
			}
			return res;

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

