#include<stdio.h>
#include<stdlib.h>

#define Length 7

int main(void) {
	printf("=====�j�ֳz�W�h=====\n\n��`�ɻݿ�ܤ��Ӹ��X�Τ@�ӯS�O��\n���X�d��G���㢳��\n\n-----�����覡-----\n\n�Y���G���Ӹ��X\n�G���G���Ӹ��X�Τ@�ӯS�O��\n�T���G���Ӹ��X\n�|���G�|�Ӹ��X�Τ@�ӯS�O��\n�����G�|�Ӹ��X\n�����G�T�Ӹ��X�Τ@�ӯS�O��\n�C���G��Ӹ��X�Τ@�ӯS�O��\n�����G�T�Ӹ��X\n");
	printf("\n�п�J�����}�����G�G\n");
	int computernumber[Length] = { 0 };
	for ( int i = 0; i < Length; i++)//�N�}�����X�H�}�C�s��
	{
		if (i==0)
		{
			printf("�п�J�S�O���G");
			scanf("%d", &computernumber[i]);
			if (computernumber[i] > 49 || computernumber[i] < 1)
			{
				printf("�п�J���ĸ��X�I\n");
				printf("�п�J�S�O���G");
				scanf("%d", &computernumber[i]);
			}
		}
		else
		{
			printf("�п�J��%d�Ӹ��X�G",i);
			scanf("%d", &computernumber[i]);
			if (computernumber[i] > 49 || computernumber[i] < 1)
			{
				printf("�п�J���ĸ��X�I\n");
				printf("�Э��s��J���X�G");
				scanf("%d", &computernumber[i]);
			}
			for (int j = i - 1; j >= 0; j--)
			{
				if (computernumber[i] == computernumber[j]) {
					printf("�п�J���ĸ��X�I\n");
					printf("�Э��s��J���X�G");
					scanf("%d", &computernumber[i]);
				}
			}
		}
	}

	printf("\n�п�J������`���G�G\n");
	int choocenumber[Length] = { 0 };
	for (int i = 0; i < Length; i++)//�N�ϥΪ̿�ܸ��X�H�}�C�s��		
	{
		if (i == 0)
		{				
			printf("�п�J�S�O���G");
			scanf("%d", &choocenumber[i]);
			if (choocenumber[i] > 49 || choocenumber[i] < 1)				
			{
				printf("�п�J���ĸ��X�I\n");
				printf("�п�J�S�O���G");
				scanf("%d", &choocenumber[i]);
			}
			for (int j = i - 1; j >= 0; j--)
			{
				if (choocenumber[i] == choocenumber[j]) {
					printf("�п�J���ĸ��X�I\n");
					printf("�Э��s��J���X�G");
					scanf("%d", &computernumber[i]);
				}
			}
		}
		else
		{
			printf("�п�J��%d�Ӹ��X�G", i);
			scanf("%d", &choocenumber[i]);
			if (choocenumber[i] > 49 || choocenumber[i] < 1)
			{
				printf("�п�J���ĸ��X�I\n");
				printf("�Э��s��J���X�G");
				scanf("%d", &choocenumber[i]);
			}
		}
	}

	int specialnumber = 0,nomalnumber = 0;

	if (computernumber[0] == choocenumber[0])
	{
		specialnumber += 1;
	}

	for (int i = 1; i < Length; i++)
	{
		for (int j = 1;j < Length;j++) {
			if (computernumber[i] == choocenumber[j])
			{
				nomalnumber++;
			}
		}
	}

	printf("\n=====�������G=====\n\n�@�븹�X�G%d\n�S�O���G%d\n", nomalnumber, specialnumber);

	if (nomalnumber == 6)
	{
		printf("���ߤ��F�Y���I�I");
	}
	else if (nomalnumber == 5 && specialnumber == 1)
	{
		printf("���ߤ��F�G���I�I");
	}
	else if (nomalnumber == 5)
	{
		printf("���ߤ��F�T���I�I");
	}
	else if (nomalnumber == 4 && specialnumber == 1)
	{
		printf("���ߤ��F�|���I�I");
	}
	else if (nomalnumber == 4)
	{
		printf("���ߤ��F�����I�I");
	}
	else if (nomalnumber == 3 && specialnumber == 1)
	{
		printf("���ߤ��F�����I�I");
	}
	else if (nomalnumber == 2 && specialnumber == 1)
	{
		printf("���ߤ��F�C���I�I");
	}
	else if (nomalnumber == 3)
	{
		printf("���ߤ��F�����I�I");
	}
	else
	{
		printf("�ܿ�ѨS����~");
	}
	system("pause");
}