//二维数组的查找
//二维数组规律：行-从左到右递增   列-从上到下递增
#define ROW 3
#define COL 3
bool Find(int (*arr)[ROW], int key,int rows,int cols)
{
	assert(arr);
	int row = 0;
	int col = cols-1;
	while (row < rows&&col >= 0)
	{
		if (arr[row][col] == key)
			return true;
		else if (arr[row][col] > key)
			col--;
		else
			row++;
	}
	return false;
}
void Test()
{
	int arr[][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9},
	};
	int key = 0;
	printf("please enter the num>");
	scanf("%d", &key);
	printf("the result>%d\n", Find(arr, key,ROW,COL));
}
