#include<stdio.h>
#include<stdlib.h>

//�إߤ@�P�_�|�~�����
int leapyears(int y) {
	if (y % 4 == 0) {
		if (y % 4000 == 0) {
			return 2;
		}
		else if (y % 400 == 0) {
			return 3;
		}
		else if (y % 100 == 0) {
			return 2;
		}
		else {
			return 3;
		}
	}
	else
	{
		return 2;
	}
}

//�إߤ@�P�_�P���X�����
int day(int y, int m, int d) {
	
	int d_total = 0;//����`�M
	
	//����~�������
	int y_last = y - 1;//�H�e�@�~���ȶi��B��ܫe�@�~�`�g�L���
	for ( y_last; y_last >0; y_last--)//�P�_�O�_���|�~
	{
		switch (leapyears(y_last))
		{
		case 2:
			d_total += 365;
			break;
		case 3:
			d_total += 366;
			break;
		default:
			break;
		}
	}
	
	//�����������
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	//�P�_�O�_���|�~�A�w�M�w2��Ѽ�
	switch (leapyears(y))
	{
	case 2:
		month[1] = 28;
		break;
	case 3:
		month[1] = 29;
		break;
	default:
		break;
	}
	
	//�H�e�@�뤧�ȶi��B��ܫe�@���`�g�L���
	int m_last = m - 1;
	for ( m_last ; m_last >0;--m_last)
	{
		d_total += month[m_last];
	}

	//�[�`���
	d_total += d;

	return d_total;
}

int main(void) {
	int y, m, d;
	printf("�п�J�~���\n�榡�G\tyyyy/mm/dd\n");
	scanf("%d/%d/%d", &y, &m, &d);
	while (y<=0||m<=0||d<=0)
	{
		printf("�ҿ�J������L��");
		return 0;
	}
	printf("�ۦ褸���~�@��@��A��%d�~%d��%d���A�@�g�L�F%d��\n", y, m, d, day(y, m, d));

	switch (day(y,m,d)%7)
	{
	case 1:
		printf("�o�@�Ѭ��P���G\n");
		break;
	case 2:
		printf("�o�@�Ѭ��P���T\n");
		break;
	case 3:
		printf("�o�@�Ѭ��P���|\n");
		break;
	case 4:
		printf("�o�@�Ѭ��P����\n");
		break;
	case 5:
		printf("�o�@�Ѭ��P����\n");
		break;
	case 6:
		printf("�o�@�Ѭ��P����\n");
		break;
	case 0:
		printf("�o�@�Ѭ��P���@\n");
		break;
	default:
		break;
	}
	system("pause");
}