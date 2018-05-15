//»¼°j¶O¦¡¨ç¼Æ
int Fibonacci_1(int num) {
	if (num == 0)
	{
		return 1;
	}
	else if (num == 1)
	{
		return 2;
	}
	else if (num == 2)
	{
		return 2;
	}
	else
	{
		return Fibonacci_1(num - 1) * 2 + Fibonacci_1(num - 2) - Fibonacci_1(num - 3);
	}
}