#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x), next(NULL){}
};

class Solution{
	public:
		ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
		{
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
};


int main()
{
	ListNode l1(1);
	ListNode l2(2);
	ListNode* p;
	p=&l1;
	for(int i=2; i<4; i++)
	{
		p->next=new ListNode(i);
		p=p->next;
	}
	p=&l2;
	for(int i=3; i<7; i++)
	{
		p->next=new ListNode(i);
		p=p->next;
	}
	Solution s;
	p=s.mergeTwoLists(&l1, &l2);

	while(p!=NULL)
	{
		cout << p->val << " ";
		p=p->next;
	}
	cout << endl;
	return 0;
}
