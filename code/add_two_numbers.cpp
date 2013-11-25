/*
 * add_two_numbers.cpp
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* p;
		ListNode q(0);
		p=&q;
		int addon=0;
		while(l1 || l2)
		{
			int v1=(l1?l1->val:0);
			int v2=(l2?l2->val:0);

			int tmp=v1 + v2 + addon;
			addon=tmp/10;
			tmp=tmp%10;

			ListNode* pp=new ListNode(tmp);
			p->next=pp;
			p=pp;
			if(l1) l1=l1->next;
			if(l2) l2=l2->next;
		}
		if(addon > 0)
		{
			ListNode* pp=new ListNode(addon);
			p->next=pp;
		}
		return q.next;



    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

