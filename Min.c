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
void Test7()
{
	Solution s;
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int arr1[] = {0,1,1,1,1,1,1,1 };
	vector<int> v(arr1,arr1+sizeof(arr1)/sizeof(arr1[0]));
	cout<<s.Min(v)<<endl;

}
