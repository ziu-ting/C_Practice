#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int indentify(int user) {//�P�_�ϥΪ̥X��
	if (user == 0)
	{
		printf("�Φv�X�������G���Y\n");
		return 0;
	}
	else if (user == 1)
	{
		printf("�Φv�X�������G��\n");
		return 1;
	}
	else if (user == 2)
	{
		printf("�Φv�X�������G�ŤM\n");
		return 2;
	}
	else
	{
		printf("�Φv����F? �Э��s�X���� ����\n");
		int re_user;//�A�w�q�@�ܼƨϨϥΪ̭��s��J
		printf("�Φv�X����~\t");
		scanf("%d", &re_user);
		return indentify(re_user);
	}
}


int main(void) {

	printf("\t=====�C���W�h=====\n�X���Y�п�J0\t�X���п�J1\t�X�ŤM�п�J2\n�q��Ĺ3����i�����C��\n");
	printf("\t=====�C���}�l=====\n");

	int win = 0, lose = 0, draw = 0;

	for (int i=1; win < 3;i++)//��ӧQ���Ʋ֭p��3�ɦ۰ʸ��X
	{
		printf("�Φv�ХX��:\t");
		int user;
		scanf("%d", &user);
		indentify(user);

		int computer = 0;
		srand(time(NULL));
		computer = rand() % 2;//�Ϲq���X���d��0��2

		switch (computer)
		{
		case 0://�q�����Y
			printf("�q���X�������G���Y\n");
			if (user==0)//�ڤ�X���Y
			{
				printf("�u�r~�~�M����S\n");
				draw++;
			}
			else if (user==2)//�ڤ�X�ŤM
			{
				printf("���K~�Φv��F����\n");
				lose++;
			}
			else//�ڤ�X��
			{
				printf("�Φv�ӧQ�S�C\n");
				++win;
			}
			break;
		case 1:
			printf("�q���X�������G��\n");
			if (user == 1)
			{
				printf("�u�r~�~�M����S\n");
				draw++;
			}
			else if (user == 0)
			{
				printf("���K~�Φv��F����\n");
				lose++;
			}
			else
			{
				printf("�Φv�ӧQ�S�C\n");
				++win;
			}
			break;
		case 2:
			printf("�q���X�������G�ŤM\n");
			if (user == 2)
			{
				printf("�u�r~�~�M����S\n");
				draw++;
			}
			else if (user == 1)
			{
				printf("���K~�Φv��F����\n");
				lose++;
			}
			else
			{
				printf("�Φv�ӧQ�S�C\n");
				
				++win;
			}
			break;
		default:
			break;
		}
		printf("====�Φv���Z�׳�====\n");
		printf("�ֿn�ܤ���%d���A�`�@�ӧQ�F%d���A����F%d���A��F%d��QQ\n\n",i,win,draw,lose);
	}
	printf("���ߪΦv���\��X~\n");
	system("pause");
}