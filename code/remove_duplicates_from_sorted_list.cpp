/*
 * remove_duplicates_from_sorted_list.cpp
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
    ListNode *deleteDuplicates(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        	if(head==NULL)
			{
				return head;
			}
			ListNode* root=head;
			while(head->next!=NULL)
			{
				ListNode* p=head->next;
				if(head->val == p->val)
				{
					head->next=p->next;
				}
				else
				{
					head=head->next;
				}
			}
			return root;

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

