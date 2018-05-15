#include<stdio.h>
#include<stdlib.h>

//建立一判斷閏年之函數
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

//建立一判斷星期幾之函數
int day(int y, int m, int d) {

	int d_total = 0;//日期總和

					//換算年份為日期
	int y_last = y - 1;//以前一年之值進行運算至前一年總經過日期
	for (y_last; y_last >0; y_last--)//判斷是否為閏年
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

	//換算月份為日期
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	//判斷是否為閏年，已決定2月天數
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

	//以前一月之值進行運算至前一月總經過日期
	int m_last = m - 1;
	for (m_last; m_last >0;--m_last)
	{
		d_total += month[m_last];
	}

	//加總日期
	d_total += d;

	return d_total;
}

int main(void) {

	printf("日\t一\t二\t三\t四\t五\t六\n");

	int calender[7] = {};//定義一長度7之陣列以存取數值
	


	for (int i = 1; i <= 30; i++)//四月起始天數為1，終止為30
	{
		int d_april = day(2016, 04, 01) + i ;//計算四月中1~30日各自西元元年一月一日多少天
		int week = d_april % 7;
		calender[week] = i;

		printf("%d", calender[week]);
		putchar('\t');
		while (week==6)
		{
			putchar('\n');
			break;
		}
		
	}
	
	system("pause");
}