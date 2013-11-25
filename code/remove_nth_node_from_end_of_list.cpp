/*
 * remove_nth_node_from_end_of_list.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131121/leetcode-rnnfel/
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        	int len=0;
			ListNode root(0);
			root.next=head;
			ListNode* p=&root;

			while(p->next!=NULL)
			{
				p=p->next;
				len++;
			}
			int m=len-n+1;
			len=0;
			p=&root;
			while(p->next!=NULL)
			{
				len++;
				if(len==m)
				{
					p->next=p->next->next;
					break;
				}
				p=p->next;
			}
			return root.next;

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

