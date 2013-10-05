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
			ListNode tmp(0);
			tmp.next=head;
			ListNode* root=head;
			ListNode* prev=&tmp;
			
			while(root)
			{
				int val=root->val;
				if(root->next!=NULL && root->next->val==val)
				{
					while(root && root->val==val)
					{
						prev->next=root->next;
						root=prev->next;
					}
					root=prev;
				}
				prev=root;
				root=root->next;
			}

			return tmp.next;
		}
};

int main()
{
	ListNode head(1);
	ListNode* root=&head;
	int a[6]={1, 1, 2, 3, 3, 4};
	for(int i=0; i< 6; i++)
	{
		ListNode* p=new ListNode(a[i]);
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
