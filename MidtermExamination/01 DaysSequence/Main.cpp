#include<stdio.h>
#include<stdlib.h>

#define Length 20 //�s��������̤j�Ȭ�20

int leapyears(int y);
int days_differ(int y, int m, int d);
int week_determine(int y, int m, int d);

void change(int &a, int &b);
void sequence(int arrange[], int x[], int y[], int z[], int number);

int main(void) {
	//�ϨϥΪ̨M�w���X�ӭn��J

	printf("�ШM�w�n��J���`����ơG");
	int dotimes;
	scanf("%d", &dotimes);

	printf("\n===����榡===\nyyyy/mm/dd\n===�~������===\n1~3000�~\n");

	//�إߤ@�}�C�H�s����J���
	int equeldays[Length] = { 0 };
	int y[Length] = { 0 };
	int m[Length] = { 0 };
	int d[Length] = { 0 };
	int week[Length] = { 0 };

	for (int i = 0;i < dotimes; i++)
	{
		printf("\n�п�J����G\n");
	
		scanf("%d/%d/%d", &y[i],&m[i],&d[i]);
		
		if (y[i] > 3000 || y[i] < 1 || m[i] < 1 || m[i]>12 || d[i] < 1 || d[i]>31)//����~���B����B�����J�d��A�Y�W�X�d��h��ܿ��~�A�èϨϥΪ̭��s��J
		{
			printf("�п�J���Ĥ���I");
			printf("\n�п�J����G\n");
			scanf("%d/%d/%d", &y[i], &m[i], &d[i]);
		}

		week[i] = week_determine(y[i], m[i], d[i]);

		sequence(week, y, m, d,i);

		while (i == dotimes - 1)
		{
			printf("\n====�̬P���ƦC�A�䵲�G��====\n");
			for (int j = 0; j <= i; j++)
			{
				printf("%d/%d/%d\t", y[j], m[j], d[j]);
				putchar('\n');

			}
			break;
		}
	}
	system("pause");
}






