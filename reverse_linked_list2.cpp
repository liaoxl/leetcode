#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
	public:
		ListNode *reverseBetween(ListNode *head, int m, int n)
		{
			if(m==n)
			{
				return head;
			}
			ListNode root(0);
			root.next=head;

			ListNode* prev=&root;
			ListNode* cur=head;
			int mc=1;

			while(mc<m)
			{
				prev->next=cur;
				cur=cur->next;
				prev=prev->next;
				mc++;
			}

			int nc=m;
			while(cur->next!=NULL && nc<n)
			{
				ListNode* nxt=cur->next;
				cur->next=nxt->next;
				nxt->next=prev->next;
				prev->next=nxt;
				nc++;
			}
			return root.next;
		}
};

int main()
{
	ListNode head(1);
	ListNode* p=&head;
	for(int i=2; i<6; i++)
	{
		p->next=new ListNode(i);
		p=p->next;
	}
	Solution s;
	p=s.reverseBetween(&head, 1, 4);
	while(p!=NULL)
	{
		cout << p->val << " ";
		p=p->next;
	}
	cout << endl;

	return 0;
}
