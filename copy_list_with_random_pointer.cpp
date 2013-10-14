#include <iostream>

using namespace std;

struct RandomListNode{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution{
	public:
		RandomListNode *copyRandomList(RandomListNode *head)
		{
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

int main()
{
	RandomListNode head(-1);
	Solution s;
	s.copyRandomList(&head);
	return 0;
}
