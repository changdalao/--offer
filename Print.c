class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> >ret;
            if(NULL == pRoot)
                return ret;
            queue<TreeNode*> queue;
            queue.push(pRoot);
            TreeNode* cur=pRoot;
            while(!queue.empty()){
                int len=0;
                int end=queue.size();
                vector<int> c;
                for(;len<end;len++){
                    TreeNode* top=queue.front();
                    queue.pop();
                    c.push_back(top->val);
                    if(top->left!=NULL)
                        queue.push(top->left);
                    if(top->right != NULL)
                        queue.push(top->right);
                }
               ret.push_back(c);
            }
            return ret;
        }
};
