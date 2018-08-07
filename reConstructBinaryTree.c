/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
       int inlength=vin.size();
        if(inlength == 0)
            return NULL;
        TreeNode* node=new TreeNode(pre[0]);//节点肯定是前序遍历第一个值
        vector<int> left_pre,right_pre,left_in,right_in;//存储前序中序左子树右子树
        int tmp=0;//在中序遍历中寻找根节点
        for(int i=0;i<inlength;i++){
            if(pre[0] == vin[i]){
                tmp=i;
                break;
            }
        }
        //得到了根节点在中序遍历数组中的位置，则这个位置左半区间就是其左子树，右半区间就是右子树
        //划分子问题，在左半区间、右半区间求解上述问题
        for(int i=0;i<tmp;i++){
            left_pre.push_back(pre[i+1]);
            left_in.push_back(vin[i]);
        }
        for(int i=tmp+1;i<inlength;i++){
            right_pre.push_back(pre[i]);
            right_in.push_back(vin[i]);
        }
        node->left=reConstructBinaryTree(left_pre,left_in);
        node->right=reConstructBinaryTree(right_pre,right_in);
        return node;
    }
};
