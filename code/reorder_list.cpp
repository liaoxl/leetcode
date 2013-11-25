/*
 * reorder_list.cpp
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
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode root(0);
        root.next=head;
        ListNode *p=&root;
        int n=0;
        while(p->next!=NULL)
        {
            p=p->next;
            n++;
        }
        if(n==0 || n==1) return;
        int mid=n%2==0?n/2:n/2+1;

        p=&root;
        while(p->next!=NULL && mid-->0)
        {
            p=p->next;
        }
        ListNode *cur=p->next;
        ListNode *nxt=cur->next;
        p->next=NULL;

        cur->next=NULL;
        while(nxt!=NULL)
        {
            ListNode* tmp=cur;
            cur=nxt;
            nxt=nxt->next;
            cur->next=tmp;
        }
        p=head;
        while(cur!=NULL && p!=NULL)
        {
            nxt=cur->next;
            cur->next=p->next;
            p->next=cur;
            p=cur->next;
            cur=nxt;
        }
        return;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

