//�o�O������ �Ԩ�Fibonacci�M��

#include<stdio.h>
#include<stdlib.h>

//�����Ѧ�:http://mh-resource.blogspot.tw/2012/02/cfibonacci-sequence.html

int Fibonacci(int num) {//��num��
	int fib;//�̲ר�ƶǦ^��
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
	else//num>=3 �}�l���j
	{
		for (int i = 3; i <= num; i++)//i����e�ۥ[�ܲ�i��,�̰�����n��
		{
			fib = 2 * num_2 + num_1 - num_0;
			num_0 = num_1;//num+1 �ɡA�U���ȦV�e���ǻ�
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
	printf("�п�J�����:");
	scanf("%d", &number);

	printf("Fibonacci(%d) = %d\n", number, Fibonacci(number));
}
