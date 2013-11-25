/*
 * rotate_list.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
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

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        	ListNode root(0);
			root.next=head;
			int len=0;
			ListNode* p=&root;

			while(p->next!=NULL)
			{
				len++;
				p=p->next;
			}
			if(len==0 || len==1)
			{
				return root.next;
			}
			k=k%len;
			int m=len-k;
			p=&root;
			while(p->next!=NULL && m-->0)
			{
				p=p->next;
			}
			ListNode* q=p;
			while(q->next!=NULL)
			{
				q=q->next;
			}
			q->next=root.next;
			root.next=p->next;
			p->next=NULL;
			return root.next;

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

