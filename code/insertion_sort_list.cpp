/*
 * insertion_sort_list.cpp
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
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head==NULL) return NULL;
        ListNode root(0);
        root.next=head;
        
        ListNode* cur=head->next;
        head->next=NULL;
        while(cur)
        {
            ListNode* p=&root;
            while(p->next && cur->val>p->next->val)
            {
                p=p->next;
            }
            ListNode* nxt=cur->next;
            cur->next=p->next;
            p->next=cur;
            cur=nxt;
        }
        return root.next;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

