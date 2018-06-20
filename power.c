/*
  判断一个数是不是2的整数次方
  转为二进制，如果是，那么这个数的二进制中只有一位是1，其余都是0，因此可转为求二进制中1的个数问题。
*/
bool power(int num)
{
	int count = 0;
	while (num)
	{
		count++;
		num = num & (num - 1);
	}
	if (count == 1)
		return true;
	return false;
}
void Test()
{
	cout << power(8) << endl;
}
