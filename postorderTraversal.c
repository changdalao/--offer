struct TreeNode {
	     int val;
	     TreeNode *left;
	     TreeNode *right;
	     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
	
class Solution {
public:
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> arr;
		if(root==NULL){
			return arr;
		}
		stack<TreeNode*> s;
		TreeNode* cur=root;
		TreeNode* prev=root;
		while(!s.empty() || cur!=NULL){
			while(cur){
				s.push(cur);
				cur=cur->left;
			}
			TreeNode* top=s.top();
			if(top->right==NULL || top->right==prev){
				arr.push_back(top->val);
				prev=top;
				s.pop();
			}else{
				cur=top->right;
			}
		}
		return arr;
	}
};
