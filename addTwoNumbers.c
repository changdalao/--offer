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
