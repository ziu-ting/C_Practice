#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int x;//�]�m���P�_�O�_�������Ƥ������
	printf("�п�J�����:");
	scanf("%d", &x);

	int factor = 1;//factor++ �˴��i�ध�]��
	int sum = 0;//�]�ƥ[�`
	while (factor<x)
	{
		if (x%factor == 0) {
			sum = sum + factor;//�]�ƥ[�`
		}
		factor++;//�q1�}�l�M��]��
	}

	printf("���Ƥ��]�ƥ[�`��:\t%d\n", sum);

	if (sum==x)
	{
		printf("���ƬO������\n");
	}
	else
	{
		printf("�o���O������\n");
	}

	system("pause");
}