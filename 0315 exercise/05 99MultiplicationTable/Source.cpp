#include<stdio.h>
#include<stdlib.h>

int main(void) {
	//巢式迴圈

	int a;//乘數
	int b;//被乘數
	for (a = 1; a <= 9; a++)
	{
		printf("\n===%d===\n", a);
		for ( b = 1; b <= 9; b++)
		{
			printf("%d * %d = %d\t", a, b, a*b);
		}
		
	}
	system("pause");
	return 0;
}


//作業要求之各排版待完成