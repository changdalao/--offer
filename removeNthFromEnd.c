struct ListNode {
	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head==NULL)
			return NULL;
		//1 2 3 4 5
		ListNode* cur=head;
		ListNode* parent=head;
		int count=0;
		while(cur)
		{
			count++;
			cur=cur->next;
		}
		if(n>count)
			return NULL;
		n=count-n;
		cur=head;
		while(n--)
		{
			parent=cur;
			cur=cur->next;
		}
		if(parent==head)
		{
			head=parent->next;
			free(parent);
			parent=NULL;
		}
		else
		{
			parent->next=cur->next;
			free(cur);
			cur=NULL;
		}
		return head;
    }
};

int main()
{
	Solution s;
	ListNode* node1=new ListNode(1);
	ListNode* node2=new ListNode(2);
	ListNode* node3=new ListNode(3);
	ListNode* node4=new ListNode(4);
	ListNode* node5=new ListNode(5);
	node1->next=node2;
	node2->next=node3;
	node3->next=node4;
	node4->next=node5;
	ListNode* result=s.removeNthFromEnd(node1,0);
	system("pause");
	return 0;
}
