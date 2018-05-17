//旋转数组的最小数字
int Min(int* arr,int length)
{
	int len = length - 1;
	if (arr[0] < arr[len])//如果数组有序，直接返回
		return arr[0];
	int begin =0;
	int end = len;
	int tmp = 0;
	while (begin < end)
	{
		tmp = (begin + end) >> 1;
		//中间数字大于begin，将begin位置改为tmp
		if (arr[begin] <= arr[tmp])
			begin = tmp;
		//中间数字小于end，将end位置改为tmp
		else if (arr[tmp] <= arr[end])
			end = tmp;
		if (end - begin == 1)
			return arr[end];
	}
}
void Test()
{
	int arr[] = {1,2,3,5,7,9,10 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	int Arr[] = {5,7,9,10,1,2,3};
	cout << Min(Arr, sizeof(Arr) / sizeof(Arr[0])) << endl;
	int Arr1[] = { 1,2,3,5,7,9,10 };
	cout << Min(Arr1, sizeof(Arr1) / sizeof(Arr1[0])) << endl;
}
