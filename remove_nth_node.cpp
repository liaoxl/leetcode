#include <iostream>

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
	public:
		ListNode* removeNthFromEnd(ListNode *head, int n)
		{
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


int main()
{
	return 0;
}
