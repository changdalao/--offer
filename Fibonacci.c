//方法1
long Fibonacci1(unsigned int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci1(n - 1) + Fibonacci1(n - 2);
}
//方法2
long long Fibonacci2(unsigned int n)
{
	int result[2] = { 0,1 };
	if (n < 2)
		return result[n];
	long long FibOne = 1;
	long long FibTwo = 0;
	long long FibN = 0;
	for (unsigned int i = 2; i <= n; i++)
	{
		FibN = FibOne + FibTwo;
		FibTwo = FibOne;
		FibOne = FibN;
	}
	return FibN;
}
void Test()
{
	int n = 45;
	printf("第%d个斐波那契数是：%d\n", n,Fibonacc2(n));
}
