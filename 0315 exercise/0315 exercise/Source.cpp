#include<stdio.h>
#include<stdlib.h>

int main(void) {
	printf("�п�J���Z:\t");
	int grade;//���Z�d��100~0
	scanf("%d", &grade);

	if (0<=grade && grade<=100)//�P�_���Z�O�_���� ���Ľd��0~100
	{
		if (grade>=60)//100~60���ή�
		{
			printf("�������Z�� %d�A���ߤή�!\n", grade);
		}
		else if (grade>=50)//59~50�ݸɦ�
		{
			printf("�������Z�� %d�A���F�ή�A�ݭn�ɦҳ�~\n", grade);
		}
		else//0~49�ݭ���
		{
			printf("�������Z�� %d�A���F�ή�A���߭����o~\n", grade);
		}
	}
	else
	{
		printf("�п�J���Ħ��Z�C(0~100)\n");
		return 0;
	}

	system("pause");
}