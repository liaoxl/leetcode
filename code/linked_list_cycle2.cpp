/*
 * linked_list_cycle2.cpp
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
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *onestep=head;
        ListNode *twostep=head;

        while(onestep && twostep)
        {
            if(onestep->next==NULL || twostep->next==NULL || twostep->next->next==NULL)
            {
                return NULL;
            }
            onestep=onestep->next;
            twostep=twostep->next->next;
            if(onestep==twostep)
            {
                twostep=head;
                while(twostep!=onestep)
                {
                    twostep=twostep->next;
                    onestep=onestep->next;
                }
                return onestep;
            }
        }
        return NULL;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

