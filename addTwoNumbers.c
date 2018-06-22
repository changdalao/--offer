struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
	
class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		int sum=0;
		int carry=0;//进位
		ListNode* cur=l2;
		while(l1!=NULL && cur!=NULL)
		{
			sum=l1->val+cur->val;
			if(sum<10)
				cur->val=sum;
			else
			{
				carry=sum/10;
				cur->val=sum%10;
				if(cur->next==NULL)
					cur->next=new ListNode(carry);
				else
					cur->next->val+=carry;
			}
			l1=l1->next;
			cur=cur->next;
		}
		return l2;
	}
};
int main()
{
	Solution s;
	ListNode* node1=new ListNode(2);
	ListNode* node2=new ListNode(4);
	ListNode* node3=new ListNode(3);
	node1->next=node2;
	node2->next=node3;
	ListNode* node4=new ListNode(5);
	ListNode* node5=new ListNode(6);
	ListNode* node6=new ListNode(6);
	node4->next=node5;
	node5->next=node6;
	ListNode* result=s.addTwoNumbers(node1,node4);
	system("pause");
	return 0;
}
