#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
	public:
		ListNode* rotateRight(ListNode *head, int k)
		{
			ListNode root(0);
			root.next=head;
			int len=0;
			ListNode* p=&root;

			while(p->next!=NULL)
			{
				len++;
				p=p->next;
			}
			if(len==0 || len==1)
			{
				return root.next;
			}
			k=k%len;
			int m=len-k;
			p=&root;
			while(p->next!=NULL && m-->0)
			{
				p=p->next;
			}
			ListNode* q=p;
			while(q->next!=NULL)
			{
				q=q->next;
			}
			q->next=root.next;
			root.next=p->next;
			p->next=NULL;
			return root.next;
		}
};

int main()
{
	ListNode head(1);
	ListNode* p=&head;
	for(int i=2; i<=5; i++)
	{
		p->next=new ListNode(i);
		p=p->next;
	}
	Solution s;
	p=s.rotateRight(&head, 2);
	while(p!=NULL)
	{
		cout << p->val << " ";
		p=p->next;
	}
	cout << endl;
	return 0;
}
