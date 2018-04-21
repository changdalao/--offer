//问题描述：
//一个二叉树，找出其中序遍历中一个节点的下一个节点，已知二叉树中每个节点都有其左节点、右节点、父节点
BTNode* GetNext(BTNode* root,BTNode* pNode)
{
	if (NULL == root)
		return NULL;
	BTNode* pnext = NULL;
	if (pNode->_right != NULL)//情景1：所查节点有右子树，那么下一个节点就是右子树的最左节点
	{
		BTNode* pNodeLeft = pNode->_right;
		while (pNodeLeft != NULL)
			pNodeLeft = pNodeLeft->_left;
		pnext = pNodeLeft;
	}
	else if (pNode->_left != NULL)//情景2：没有右子树，且父节点不为空
						//向上查找，直到它的树枝上一个父子节点是一个节点的左子树位置，返回该节点
	{
		BTNode* cur = pNode;
		BTNode* Parent = cur->_parent;
		while (Parent != NULL && Parent->_left!= cur)
		{
			cur = Parent;
			Parent = cur->_parent;
		}
		pnext = Parent;
	}
	return pnext;
}
