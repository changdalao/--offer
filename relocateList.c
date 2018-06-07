	/**给定一个单链表的头部节点head，链表长度为N。 
   *如果N为偶数，那么前N/2个节点算作左半区，后N/2个节点算作右半区； 
   *如果N为奇数，那么前N/2个节点算作左半区，后N/2+1个节点算作右半区；
   *左半区从左到右依次记为L1->L2->…，右半区从左到右依次记为R1->R2->…。请将单链表调整成L1->R1->L2->R2->…的样子。 
   *例如： 1->2->3->4 调整后：1->3->2->4
   *       1->2->3->4->5 调整后：1->3->2->4->5 
   *要求：如果链表长度为N，时间复杂度请达到O(N)，额外空间复杂度请达到O(1)
	 */
struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
			val(x),
			next(NULL) 
			{}
	};
class Solution {
public:
	void relocateList(struct ListNode* head) {
		if(head==NULL)
			return;
		ListNode* cur=head;//左半区的移动指针
		int len=0;
		int begin=0;//中间划分
		while(cur)
		{
			++len;
			cur=cur->next;
		}
		begin=len/2;
		cur=head;
		ListNode* prev=head;//右半区的移动指针
		for(;begin>0;--begin)
			prev=prev->next;
		ListNode* right=prev;//右半区的头指针
		while(cur!=right && prev!=NULL)
		{
			ListNode* leftnext=cur->next;
			ListNode* rightnext=prev->next;
			cur->next=prev;
			cur=leftnext;
			if(rightnext!=NULL && leftnext!=right)//如果右半区到尾或者左半区到尾，结束
				prev->next=leftnext;
			else
				break;
			prev=rightnext;
		}
  }
};

int main()
{
	ListNode* node1=new ListNode(1);
	ListNode* node2=new ListNode(2);
	ListNode* node3=new ListNode(3);
	ListNode* node4=new ListNode(4);
	//ListNode* node5=new ListNode(5);

	node1->next=node2;
	node2->next=node3;
	node3->next=node4;
	//node4->next=node5;
	Solution s;
	s.relocateList(node1);
	while(node1)
	{
		cout<<node1->val<<" ";
		node1=node1->next;
	}
	cout<<endl;
	system("pause");
	return 0;
}
