//二分法 一个数的平方根不会大于(n/2+1)
class Solution {
public:
	int sqrt(int x) {
		long long i = 0;
		long long j = x / 2 + 1;
		while (i <= j)
		{
			long long mid = (i + j) / 2;
			long long sq = mid * mid;
			if (sq == x) return mid;
			else if (sq < x) i = mid + 1;
			else j = mid - 1;
		}
		return j;
	}
};
int main()
{
	Solution s;
	cout<<s.sqrt(18)<<endl;
	system("pause");
	return 0;
}
