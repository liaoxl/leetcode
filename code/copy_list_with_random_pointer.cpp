/*
 * copy_list_with_random_pointer.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 */
 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        				RandomListNode root(0);
			root.next=head;
			RandomListNode *p=head;

			if(p==NULL)
			{
				return p;
			}

			while(p!=NULL)
			{
				RandomListNode *cpy=new RandomListNode(p->label);
				cpy->next=p->next;
				p->next=cpy;
				p=cpy->next;
			}
			RandomListNode *oricur=head;
			RandomListNode *cpycur=head->next;
			while(oricur!=NULL)
			{
				if(oricur->random!=NULL)
				{
					cpycur->random=oricur->random->next;
				}
				oricur=cpycur->next;
				if(oricur!=NULL)
				{
					cpycur=oricur->next;
				}
			}
			oricur=head;
			cpycur=head->next;
			root.next=cpycur;
			while(cpycur->next!=NULL)
			{
				oricur->next=cpycur->next;
				cpycur->next=oricur->next->next;

				oricur=oricur->next;
				cpycur=cpycur->next;
			}
			oricur->next=NULL;
			return root.next;

    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

