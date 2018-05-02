void SQueuePush(Stack* s1,DataType data)
{
	StackPush(s1, data);
}
void SQueuePop(Stack* s1,Stack* s2)
{
	if (StackEmpty(s2)==0)
	{
		while (StackEmpty(s1) != 0)
		{
			StackPush(s2, StackTop(s1));
			StackPop(s1);
		}
	}
	if (StackEmpty(s1) == 0 && StackEmpty(s2) == 0)
	{
		printf("Queue is empty\n");
		return;
	}
	StackPop(s2);
}

void Test6()
{
	Stack s1;
	Stack s2;
	StackInit(&s1);
	StackInit(&s2);
	SQueuePush(&s1, 0);
	SQueuePush(&s1, 1);
	SQueuePush(&s1, 2);
	SQueuePush(&s1, 3);
	SQueuePush(&s1, 4);
	SQueuePop(&s1, &s2);
	SQueuePop(&s1, &s2);
	SQueuePop(&s1, &s2);
	SQueuePop(&s1, &s2);
}
