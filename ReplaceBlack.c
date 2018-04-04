//时间复杂度O(n2)
void ReplaceBlack(char* arr,char* key,int len)
{
	if (NULL == arr || NULL == key)
		return;
	char* cur = arr;
	while (*cur != '\0')
	{
		char* prev = key;
		if (*cur == ' ')
		{
			//字符串向后移动key-1个字符单位
			int plen = strlen(cur);
			while (plen)
			{
				cur[plen + 2] = cur[plen];
				plen--;
			}
			while (*prev != '\0')
			{
				*cur = *prev;
				cur++, prev++;
			}
		}
		cur++;
	}
}
void Test()
{
	char arr[100] = " welcome to the university! ";
	printf("原字符串>%s\n",arr);
	char key[] = "%20";
	ReplaceBlack(arr, key, strlen(arr)-1);
	printf("变换后>%s\n", arr);
}
 
