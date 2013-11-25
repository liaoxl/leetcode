/*
 * reverse_nodes_in_k_group.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 ListNode *reverseBetween(ListNode *head, int m, int n) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	if(m==n)
	{
		return head;
	}
	ListNode root(0);
	root.next=head;

	ListNode* prev=&root;
	ListNode* cur=head;
	int mc=1;

	while(mc<m)
	{
		prev->next=cur;
		cur=cur->next;
		prev=prev->next;
		mc++;
	}

	int nc=m;
	while(cur->next!=NULL && nc<n)
	{
		ListNode* nxt=cur->next;
		cur->next=nxt->next;
		nxt->next=prev->next;
		prev->next=nxt;
		nc++;
	}
	return root.next;
}

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        	int len=0;
			ListNode root(0);
			root.next=head;
			ListNode* p=&root;

			while(p->next!=NULL)
			{
				len++;
				p=p->next;
			}
			int start=0;
			while(start+k<=len)
			{
				root.next=reverseBetween(root.next, start+1, start+k);
				start=start+k;
			}
			return root.next;

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

