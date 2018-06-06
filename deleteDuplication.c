struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
		if(pHead==NULL)
			return NULL;
		ListNode* cur=pHead;
		ListNode* parent=pHead;
		ListNode* prev=pHead->next;
		ListNode* del=pHead;
		while(cur&&prev)
		{
			if(cur->val==prev->val)
			{
				while(cur->val==prev->val && prev->next!=NULL)
					prev=prev->next;
				while(cur->val != prev->val)
				{
					ListNode* del=cur;
					cur=cur->next;
					parent->next=cur;
					delete del;
					del=NULL;
				}
				parent=cur;
				if(prev->next!=NULL)
					prev=prev->next;
			}
			prev=prev->next;
			cur=cur->next;
		}
		return pHead;
    }
};
