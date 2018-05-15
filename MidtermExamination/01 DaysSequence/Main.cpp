#include<stdio.h>
#include<stdlib.h>

#define Length 20 //存取日期之最大值為20

int leapyears(int y);
int days_differ(int y, int m, int d);
int week_determine(int y, int m, int d);

void change(int &a, int &b);
void sequence(int arrange[], int x[], int y[], int z[], int number);

int main(void) {
	//使使用者決定有幾個要輸入

	printf("請決定要輸入之總日期數：");
	int dotimes;
	scanf("%d", &dotimes);

	printf("\n===日期格式===\nyyyy/mm/dd\n===年份限制===\n1~3000年\n");

	//建立一陣列以存取輸入日期
	int equeldays[Length] = { 0 };
	int y[Length] = { 0 };
	int m[Length] = { 0 };
	int d[Length] = { 0 };
	int week[Length] = { 0 };

	for (int i = 0;i < dotimes; i++)
	{
		printf("\n請輸入日期：\n");
	
		scanf("%d/%d/%d", &y[i],&m[i],&d[i]);
		
		if (y[i] > 3000 || y[i] < 1 || m[i] < 1 || m[i]>12 || d[i] < 1 || d[i]>31)//限制年分、月份、日期輸入範圍，若超出範圍則顯示錯誤，並使使用者重新輸入
		{
			printf("請輸入有效日期！");
			printf("\n請輸入日期：\n");
			scanf("%d/%d/%d", &y[i], &m[i], &d[i]);
		}

		week[i] = week_determine(y[i], m[i], d[i]);

		sequence(week, y, m, d,i);

		while (i == dotimes - 1)
		{
			printf("\n====依星期排列，其結果為====\n");
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






