#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Header.h"//���Y�ɸ��J��O�����

int main(void) {
	int number;//��J����n��
	printf("�п�J�����:");
	scanf("%d", &number);

	printf("Fibonacci(%d) = %d\n", number, Fibonacci_1(number));


	clock_t start_1, finish_1;
	start_1 = clock();//�p�⻼�j�O����ư���ɶ�

	for (int i = 1; i <= 1000000; i++)//���ư���100W��
	{
		Fibonacci_1(number);
		finish_1 = clock();
	}
	finish_1 = clock();

	clock_t start_2, finish_2;
	start_2 = clock();//�p��D���j�O����ư���ɶ�

	for (int i = 1; i <= 1000000; i++)
	{
		Fibonacci_2(number);
		finish_2 = clock();
	}
	finish_2 = clock();

	double time_1, time_2;
	time_1 = (double)(finish_1 - start_1) / CLOCKS_PER_SEC;
	time_2 = (double)(finish_2 - start_2) / CLOCKS_PER_SEC;

	printf("���j�O����ƹB��ɶ��� %.3f ��\n", time_1);
	printf("�D���j�O����ƹB��ɶ��� %.3f ��\n", time_2);

	system("pause");
}
