#include <iostream>

using namespace std;


struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x), next(NULL) {}
};

class Solution{
	public:
		ListNode *swapPairs(ListNode* head){
			if(head==NULL || head->next==NULL)
			{
				return head;
			}
			ListNode* cur=head;
			ListNode root(0);
			root.next=head;
			ListNode* prev=&root;

			while(cur!=NULL && cur->next!=NULL)
			{
				ListNode* nxt=cur->next;
				cur->next=nxt->next;
				prev->next=nxt;
				nxt->next=cur;
				prev=cur;
				cur=cur->next;
			}
			return root.next;
		}
};

int main()
{
	ListNode head(1);
	ListNode* p=&head;
	for(int i=2; i<=4; i++)
	{
		p->next=new ListNode(i);
		p=p->next;
	}
	Solution s;
	p=s.swapPairs(&head);
	while(p!=NULL)
	{
		cout << p->val << " ";
		p=p->next;
	}
	cout << endl;
	return 0;
}
