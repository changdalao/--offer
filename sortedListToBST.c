struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head==NULL)
            return NULL;
        TreeNode* root=new TreeNode(head->val);
        ListNode* cur=head->next;
        TreeNode* prev=root;//BST遍历节点
		TreeNode* parent=root;
		bool result=true;
        while(cur!=NULL){
			prev=root;
			parent=root;
            while(prev){
             if(cur->val>prev->val)
			 {
				 parent=prev;
				 prev=prev->right;
			 }
             else if(cur->val<prev->val)
			 {
				 result=false;
				 parent=prev;
				 prev=prev->left;
			 }
             else
                goto stop;
            }
			if(result==true)
				parent->right=new TreeNode(cur->val);
			else
				parent->left=new TreeNode(cur->val);
            stop:
            cur=cur->next;
        }
        return root;
    }
};

int main()
{
	ListNode* node1=new ListNode(1);
	ListNode* node2=new ListNode(6);
	ListNode* node3=new ListNode(9);
	ListNode* node4=new ListNode(3);
	ListNode* node5=new ListNode(5);
	ListNode* node6=new ListNode(2);
	ListNode* node7=new ListNode(7);
	node1->next=node2;
	node2->next=node3;
	node3->next=node4;
	node4->next=node5;
	node5->next=node6;
	node6->next=node7;
	Solution s;
	TreeNode* root=s.sortedListToBST(node1);
	system("pause");
	return 0;
}
