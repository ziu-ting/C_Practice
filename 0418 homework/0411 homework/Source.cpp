//這是測試檔 詳見Fibonacci專案

#include<stdio.h>
#include<stdlib.h>

int Fibonacci(int num) {
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
		return Fibonacci(num - 1) * 2 + Fibonacci(num - 2) - Fibonacci(num - 3);
	}
}

int main(void) {
	int number;
	printf("請輸入正整數:");
	scanf("%d", &number);
	
	printf("Fibonacci(%d) = %d\n", number, Fibonacci(number));
}

