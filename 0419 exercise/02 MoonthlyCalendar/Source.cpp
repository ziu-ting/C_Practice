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
	for ( y_last; y_last >0; y_last--)//判斷是否為閏年
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
	for ( m_last ; m_last >0;--m_last)
	{
		d_total += month[m_last];
	}

	//加總日期
	d_total += d;

	return d_total;
}

int main(void) {
	int y, m, d;
	printf("請輸入年月日\n格式：\tyyyy/mm/dd\n");
	scanf("%d/%d/%d", &y, &m, &d);
	while (y<=0||m<=0||d<=0)
	{
		printf("所輸入之日期無效");
		return 0;
	}
	printf("自西元元年一月一日，至%d年%d月%d日止，共經過了%d天\n", y, m, d, day(y, m, d));

	switch (day(y,m,d)%7)
	{
	case 1:
		printf("這一天為星期二\n");
		break;
	case 2:
		printf("這一天為星期三\n");
		break;
	case 3:
		printf("這一天為星期四\n");
		break;
	case 4:
		printf("這一天為星期五\n");
		break;
	case 5:
		printf("這一天為星期六\n");
		break;
	case 6:
		printf("這一天為星期日\n");
		break;
	case 0:
		printf("這一天為星期一\n");
		break;
	default:
		break;
	}
	system("pause");
}