/*
 * clone_graph.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

/**
 * Definition for undirected graph.
 */
 struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
 };

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(node==NULL) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> myhashmap;
        queue<UndirectedGraphNode*> myqueue;
        myqueue.push(node);
        UndirectedGraphNode* copynode=new UndirectedGraphNode(node->label);
        myhashmap[node]=copynode;

        while(!myqueue.empty())
        {
            UndirectedGraphNode* tmp=myqueue.front();
            myqueue.pop();
            int n=tmp->neighbors.size();
            for(int i=0; i<n; i++)
            {
                UndirectedGraphNode* neighbor=tmp->neighbors[i];
                if(myhashmap.find(neighbor)==myhashmap.end())
                {
                    UndirectedGraphNode* p=new UndirectedGraphNode(neighbor->label);
                    myhashmap[tmp]->neighbors.push_back(p);
                    myhashmap[neighbor]=p;
                    myqueue.push(neighbor);
                }
                else
                {
                    myhashmap[tmp]->neighbors.push_back(myhashmap[neighbor]);
                }
            }
        }
        return copynode;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

