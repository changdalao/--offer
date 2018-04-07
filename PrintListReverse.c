#include<iostream>
#include<assert.h>
using namespace std;

typedef int DateType;

typedef struct SeqList
{
	struct SeqList* _next;
	DateType _data;
}SeqList;
void InitSeqList(SeqList** pphead)//初始化
{
	*pphead = NULL;
}
SeqList* BuyHead(DateType data)//建立节点
{
	SeqList* node = (SeqList*)malloc(sizeof(SeqList));
	assert(node);
	node->_data = data;
	node->_next = NULL;
	return node;
}
void SeqListPush(SeqList** pphead,DateType data)//尾插
{
	if (*pphead == NULL)
		*pphead=BuyHead(data);
	else
	{
		SeqList* NewHead = *pphead;
		while (NewHead->_next)
		{
			NewHead = NewHead->_next;
		}
		NewHead->_next = BuyHead(data);
	}
}
void SeqPrint(SeqList* phead)//从头到尾打印
{
	if (phead == NULL)
		return;
	else
	{
		while (phead)
		{
			printf("%d ", phead->_data);
			phead = phead->_next;
		}
	}
	printf("\n");
}
//////////////////////////////////////////////////////////
//从尾到头打印
void PrintListReverse1(SeqList* phead)
{
	//递归
	if (phead->_next != NULL)
		PrintListReverse1(phead->_next);
	printf("%d ", phead->_data);
}
///////////////////////////////////////////////////////////
void PrintListReverse2(SeqList* phead)
{
	//非递归
	DateType arr[10] = { 0 };
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		arr[i] = phead->_data;
		phead = phead->_next;
		if (phead == NULL)
			break;
		count++;
	}
	for (; count >= 0; count--)
		printf("%d ", arr[count]);
}
void Test()
{
	SeqList* phead;
	InitSeqList(&phead);
	SeqListPush(&phead, 0);
	SeqListPush(&phead, 1);
	SeqListPush(&phead, 2);
	SeqListPush(&phead, 3);
	SeqListPush(&phead, 4);
	SeqListPush(&phead, 5);
	SeqPrint(phead);
  PrintListReverse1(phead);
	PrintListReverse2(phead);
}
