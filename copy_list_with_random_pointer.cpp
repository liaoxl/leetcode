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
			RandomListNode *p;
			RandomListNode *phead=head;
			p=&root;

			while(phead!=NULL)
			{
				p->next=new RandomListNode(phead->label);
				p=p->next;
				phead=phead->next;
			}
			p=&root, phead=head;
			while(phead!=NULL)
			{
				if(phead->random==NULL)
				{
					phead=phead->next;
					p=p->next;
				}
			}

		}
};

int main()
{
	return 0;
}
