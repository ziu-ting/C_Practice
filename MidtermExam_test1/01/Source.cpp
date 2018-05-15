#include<stdio.h>
#include<stdlib.h>

#define Length 20

//判斷是否為閏年
//2為閏年 3為非閏年
int leapyears(int y) {
	if (y % 4 == 0)
	{
		if (y % 400 == 0)
		{
			return 2;
		}
		else if (y % 100 == 0)
		{
			return 3;
		}
		else
		{
			return 2;
		}
	}
	else
	{
		return 3;
	}
}

//判斷相差日
int	 differ(int y, int m, int d) {
	//將年份轉日期
	int total = 0;
	int y_last = y - 1;
	for (int i = 1;i <= y_last;i++)
	{
		switch (leapyears(i))
		{
		case 2:
			total += 366;
			break;
		case 3:
			total += 365;
			break;
		default:
			break;
		}
	}

	//將月份轉日期
	int m_last = m - 1;
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	switch (leapyears(y))
	{
	case 2:
		month[1] = 29;
		break;
	case 3:
		month[1] = 28;
		break;
	default:
		break;
	}
	for (int i = 0;i < m_last;i++)
	{
		total += month[i];
	}
	
	//將日期加總
	total += d;

	return total;
}

//判斷星期
int whichweek(int y, int m, int d) {
	switch (differ(y,m,d)%7)
	{
	case 0:
	
		return 1;
		break;
	case 1:
		return 2;
		break;
	case 2:
		return 3;
		break;
	case 3:
		return 4;
		break;
	case 4:
		return 5;
		break;
	case 5:
		return 6;
		break;
	case 6:
		return 7;
		break;
	default:
		break;
	}
}

//交換
void change(int &a, int &b) {
	int	 temp = a;
	a = b;
	b = temp;
}

//大小排列
void sequence(int a[], int num) {
	
	for (int i = num - 1; i >= 0; i--)
	{
		while (a[num] < a[i]) {

			change(a[num], a[i]);
			

			num--;
		}
	}
}
/*,int y[],int m[],int d[]*/
/*change(y[num], y[i]);
change(m[num], m[i]);
change(d[num], a[i]);*/

int main(void) {

	/*int x = 2;
	int y = 3;
	change(x, y);
	printf("%d,%d", x, y);*/	

	int	a[5] = {0};
	a[0] = 5;
	a[1] = 3;
	a[2] = 4;
	a[3] = 1;
	a[4] = 7;
	sequence(a, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("%d", a[i]);
	}


	/*int y[Length] = { 0 }, m[Length] = { 0 }, d[Length] = { 0 };
	int week[Length] = { 0 };
	int dotimes;
	printf("請決定即將輸入之日期個數：");
	scanf("%d", &dotimes);
	for (int i = 0; i < dotimes; i++)
	{
		printf("請輸入第%d項日期(yyyy/mm/dd)：", i + 1);
		scanf("%d/%d/%d", &y[i], &m[i], &d[i]);
		while (y[i] < 0 || y[i]>3000 || m[i] < 0 || m[i]>12 || d[i] < 0 || d[i]>31)
		{
			printf("請輸入有效數字!\n");
			printf("請重新輸入第%d項日期(yyyy/mm/dd)：");
			scanf("%d/%d/%d", &y[i], &m[i], &d[i]);
		}
		week[i]= whichweek(y[i], m[i], d[i]);

		sequence(week, y, m, d, i);

		while (i == dotimes - 1)
		{
			printf("===即將印出結果===\n\n");

			for (int j = 0; j <=i; j++)
			{
				printf("%d/%d/%d\n", y[j], m[j], d[j]);
				
			}
			break;
		}
	}*/
		
}