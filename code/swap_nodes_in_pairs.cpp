/*
 * swap_nodes_in_pairs.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131123/leetcode-snp/
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

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        	if(head==NULL || head->next==NULL)
			{
				return head;
			}
			ListNode* cur=head;
			ListNode root(0);
			root.next=head;
			ListNode* prev=&root;

			while(cur!=NULL && cur->next!=NULL)
			{
				ListNode* nxt=cur->next;
				cur->next=nxt->next;
				prev->next=nxt;
				nxt->next=cur;
				prev=cur;
				cur=cur->next;
			}
			return root.next;

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

