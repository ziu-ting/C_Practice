//這是測試檔 詳見Fibonacci專案

#include<stdio.h>
#include<stdlib.h>

//概念參考:http://mh-resource.blogspot.tw/2012/02/cfibonacci-sequence.html

int Fibonacci(int num) {//第num項
	int fib;//最終函數傳回值
	int	num_2=2, num_1=2, num_0=1;//fib = 2*num_2 + num_1 - num_0
	if (num==0)
	{
		return num_0;
	}
	else if (num==1)
	{
		return num_1;
	}
	else if (num==2)
	{
		return num_2;
	}
	else//num>=3 開始遞迴
	{
		for (int i = 3; i <= num; i++)//i為當前相加至第i項,最高為第n項
		{
			fib = 2 * num_2 + num_1 - num_0;
			num_0 = num_1;//num+1 時，各項值向前項傳遞
			num_1 = num_2;
			num_2 = fib;
		}
		num_2 = 2;
		num_1 = 2;
		num_0 = 1;
		return fib;
	}
}

int main(void) {
	int number;
	printf("請輸入正整數:");
	scanf("%d", &number);

	printf("Fibonacci(%d) = %d\n", number, Fibonacci(number));
}
