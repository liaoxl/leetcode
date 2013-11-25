/*
 * merge_k_sorted_lists.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        	if(l1==NULL)
			{
				return l2;
			}
			if(l2==NULL)
			{
				return l1;
			}
			ListNode l(0);
			l.next=l1;
			ListNode* prev=&l;
			while(l2)
			{
				if(l1!=NULL && l1->val<=l2->val)
				{
					prev=l1;
					l1=l1->next;
					continue;
				}
				else if(l1==NULL)
				{
					prev->next=l2;
					break;
				}
				else if(l1!=NULL && l1->val>l2->val)
				{
					prev->next=l2;
					l2=l2->next;
					prev=prev->next;
					prev->next=l1;
				}
			}
			return l.next;
 }
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        	int len=lists.size();
			if(len==0)
			{
				return NULL;
			}
			else if(len==1)
			{
				return lists[0];
			}

			ListNode* first=lists[0];
			vector<ListNode *>::iterator it;
			while(len>1)
			{
				lists[0]=mergeTwoLists(lists[0], lists[1]);
				it=lists.begin()+1;
				lists.erase(it);
				len--;
			}
			return lists[0];

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

