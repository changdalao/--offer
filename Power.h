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
void Test()
{
	cout << Power(2, 32) << endl;
	cout << Power(2, -3) << endl;
	cout << Power(2, 0) << endl;
}
