//方法1：
//时间复杂度O(n2)
void ReplaceBlack1(char* arr,char* key,int len)
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
 //方法2：
void ReplaceBlack2(char* arr, char* key, int len)
{
	char* cur = arr;
	int count = 0;
	while (*cur)//统计空格个数
	{
		if (*cur == ' ')
			count++;
		cur++;
	}
	int newlength = len + count * (strlen(key) - 1);//新空间
	int indexlen = len;
	int indexnewlen = newlength;
	while (indexlen >= 0 && indexnewlen > indexlen)
	{
		if (arr[indexlen] == ' ')
		{
			arr[indexnewlen--] = '0';
			arr[indexnewlen--] = '2';
			arr[indexnewlen--] = '%';
		}
		else
			arr[indexnewlen--] = arr[indexlen];
		--indexlen;
	}
}

void Test()
{
	char arr[100] = " welcome to the university! ";
	printf("原字符串>%s\n",arr);
	char key[] = "%20";
	ReplaceBlack1(arr, key, strlen(arr)-1);
	printf("变换后>%s\n", arr);
}
