#include<stdio.h>
#include<stdlib.h>

int main(void) {
	//�_���j��

	int a;//����
	int b;//�Q����
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


//�@�~�n�D���U�ƪ��ݧ���