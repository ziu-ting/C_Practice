#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int year;//�ϥΪ̿�J�ݧP�_���~��
	printf("�п�J�~��:");
	scanf("%d", &year);

	if (year%4==0)
	{
		int quarter_year = year / 4;//�N�Ʀr��4�᪺�өw�q���s���ܼ�
		if (quarter_year%1000==0)//���Ƭ�4000�����ơA���O�|�~
		{
			printf("���~���O�|�~\n");
		}
		else if (quarter_year%100==0)//���Ƭ�400�����ơA�O�|�~
		{
			printf("���~�O�|�~\n");
		}
		else if (quarter_year%25==0)//���Ƭ�100�����ơA���O�|�~
		{
			printf("���~���O�|�~\n");
		}
		else//���Ƭ�4�����ơA�O�|�~
		{
			printf("���~�O�|�~\n");
		}
	}
	
	else//���Ƥ���4�����ơA���O�|�~
	{
		printf("���~���O�|�~\n");
	}
}