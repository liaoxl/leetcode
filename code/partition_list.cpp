/*
 * partition_list.cpp
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

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        			ListNode root(0);
			root.next=head;
			ListNode *p=&root;
			if(p->next==NULL || p->next->next==NULL)
			{
				return root.next;
			}
			while(p->next!=NULL && p->next->val<x)
			{
				p=p->next;
			}
			if(p->next==NULL)
			{
				return root.next;
			}
			ListNode *forw=p->next;
			ListNode *prev=p;
			while(forw!=NULL)
			{
				if(forw->val<x)
				{
					ListNode *tmp;
					tmp=p->next;
					p->next=prev->next;
					prev->next=forw->next;
					forw->next=tmp;
					p=p->next;

					forw=prev->next;
					continue;
				}
				forw=forw->next;
				prev=prev->next;

			}
			return root.next;

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

