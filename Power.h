//数值的整数次方
double Power(double base, int exponent)
{
	if (exponent == 0 || base == 1)
		return 1;
	double result = 1.0;
	int newexponent= exponent;
	if (exponent < 0)
		newexponent = -exponent;
	for (int i = 1; i <= newexponent; i++)
	{
		result *= base;
	}
	if (exponent < 0)
		return 1 / result;
	else
		return result;
}
//////////////////////////////////////////
double Power1(double base, int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	int flag = 0;
	if (exponent < 0)
	{
		exponent = -exponent;
		flag = 1;
	}
	//类似于菲波那切数列算法，求16次方先求8次方，求八次方先求四次方...
	double result = Power(base, exponent >> 1);
	result *= result;
	if (exponent & 0x1 == 1)
		result *= base;
	if (flag == 0)
		return result;
	else
		return 1 / result;
}

void Test()
{
	cout << Power1(2, 32) << endl;
	cout << Power1(2, -3) << endl;
	cout << Power1(2, 0) << endl;

	cout << Power(2, 32) << endl;
	cout << Power(2, -3) << endl;
	cout << Power(2, 0) << endl;
}
