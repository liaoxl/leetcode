#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution{
	public:
		ListNode* deleteDuplicates(ListNode* head)
		{
			if(head==NULL)
			{
				return head;
			}
			ListNode* root=head;
			while(head->next!=NULL)
			{
				ListNode* p=head->next;
				if(head->val == p->val)
				{
					head->next=p->next;
				}
				else
				{
					head=head->next;
				}
			}
			return root;
		}
};

int main()
{
	ListNode head(1);
	ListNode* root=&head;
	for(int i=2; i< 5; i++)
	{
		ListNode* p=new ListNode(3);
		root->next=p;
		root=p;
	}
	ListNode* q=&head;
	while(q!=NULL)
	{
		cout << q->val << " ";
		q=q->next;
	}
	cout << endl;
	Solution s;
	q=s.deleteDuplicates(&head);
	while(q!=NULL)
	{
		cout << q->val << " ";
		q=q->next;
	}
	cout << endl;
	return 0;
}
