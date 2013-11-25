/*
 * populating_next_right_pointers_in_each_node2.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <queue>

using namespace std;

/**
 * Definition for binary tree with next pointer.
 */
 struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        			if(root==NULL)
			{
				return;
			}
			queue<TreeLinkNode *> tln;
			tln.push(root);

			while(!tln.empty())
			{
				int len=tln.size();
				TreeLinkNode *curnext=NULL;
				while(len-->0)
				{
					tln.front()->next=curnext;
					curnext=tln.front();
					if(tln.front()->right!=NULL)
					{
						tln.push(tln.front()->right);
					}
					if(tln.front()->left!=NULL)
					{
						tln.push(tln.front()->left);
					}
					tln.pop();
				}
			}

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

