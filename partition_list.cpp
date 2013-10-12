#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
	public:
		ListNode *partition(ListNode *head, int x)
		{
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
					ListNode tmp(0);
					tmp.next=p->next;
					p->next=prev->next;
					prev->next=forw->next;
					forw->next=tmp.next;
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

int main()
{
	ListNode head(3);
	ListNode *p=&head;
	p->next=new ListNode(1);
	p=p->next;
	p->next=new ListNode(2);
	Solution s;
	s.partition(&head, 3);
	return 0;
}
