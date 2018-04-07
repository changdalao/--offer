void DeleteNode(SeqList** pphead, SeqList* pos)
{
	assert(*pphead && pos);
	SeqList* cur = *pphead;
	SeqList* prev = *pphead;
	if (cur->_data == pos->_data)//处理:当所删节点恰好是头结点时
	{
		*pphead = cur->_next;
		free(cur);
		cur = NULL;
	}
	else//处理：所删节点不是头结点
	{
		while (cur)
		{
			if (cur == pos)
			{
				prev->_next = cur->_next;
				free(cur);
				cur = NULL;
				return;
			}
			prev = cur;
			cur = cur->_next;
		}
	}
}
