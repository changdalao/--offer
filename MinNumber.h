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
//修复bug（采用依次遍历比较）
class Solution {
public:
	int Min(vector<int> arr)
	{
		int left = 0;
		int right = arr.size()-1;
		int mid =0;
		while (arr[left] >= arr[right]) {
			if (right - left == 1) {
				mid = right;
				break;
			}
			mid = (left + right) / 2;
			if (arr[mid] == arr[left] && arr[left] == arr[right])//顺序处理
			{
				int result = arr[mid];
				for (int i = 0; i < right; i++) {
					if (result > arr[i])
						result = arr[i];
				}
				return result;
			}
			if (arr[mid] <= arr[right])
				right = mid;
			else if (arr[mid] >= arr[left])
				left = mid;
		}
		return arr[mid];
	}
};
void Test1()
{
	Solution s;
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int arr1[] = {0,1,1,1,1,1,1,1 };
	vector<int> v(arr1,arr1+sizeof(arr1)/sizeof(arr1[0]));
	cout<<s.Min(v)<<endl;

}
