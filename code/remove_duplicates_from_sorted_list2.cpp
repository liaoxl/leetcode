/*
 * remove_duplicates_from_sorted_list2.cpp
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
			ListNode tmp(0);
			tmp.next=head;
			ListNode* root=head;
			ListNode* prev=&tmp;
			
			while(root)
			{
				int val=root->val;
				if(root->next!=NULL && root->next->val==val)
				{
					while(root && root->val==val)
					{
						prev->next=root->next;
						root=prev->next;
					}
					root=prev;
				}
				prev=root;
				root=root->next;
			}

			return tmp.next;

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

