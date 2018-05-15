#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Header.h"//標頭檔載入兩費式函數

int main(void) {
	int number;//輸入為第n項
	printf("請輸入正整數:");
	scanf("%d", &number);

	printf("Fibonacci(%d) = %d\n", number, Fibonacci_1(number));


	clock_t start_1, finish_1;
	start_1 = clock();//計算遞迴費式函數執行時間

	for (int i = 1; i <= 1000000; i++)//重複執行100W次
	{
		Fibonacci_1(number);
		finish_1 = clock();
	}
	finish_1 = clock();

	clock_t start_2, finish_2;
	start_2 = clock();//計算非遞迴費式函數執行時間

	for (int i = 1; i <= 1000000; i++)
	{
		Fibonacci_2(number);
		finish_2 = clock();
	}
	finish_2 = clock();

	double time_1, time_2;
	time_1 = (double)(finish_1 - start_1) / CLOCKS_PER_SEC;
	time_2 = (double)(finish_2 - start_2) / CLOCKS_PER_SEC;

	printf("遞迴費式函數運算時間為 %.3f 秒\n", time_1);
	printf("非遞迴費式函數運算時間為 %.3f 秒\n", time_2);

	system("pause");
}
