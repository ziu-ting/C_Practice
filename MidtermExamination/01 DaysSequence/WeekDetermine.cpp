//建立一可判斷星期之函數 //all done
//建立一判斷閏年之函數
//是閏年回傳結果2;非閏年回傳結果3
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

//建立一可判斷星期之函數
//建立一可判斷該日與西元元年一月一日相差日數之函數
int days_differ(int y, int m, int d) {
	int days_total = 0;//建立總日期

				   //將年份轉換成日期
	int y_last = y - 1;
	for (y_last; y_last > 0;y_last--)
	{
		switch (leapyears(y_last))//判斷是否為閏年
		{
		case 2:
			days_total += 366;
			break;
		case 3:
			days_total += 365;
			break;
		default:
			break;
		}
	}

	//將月份轉為日期
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	switch (leapyears(y))//判斷是否為閏年
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
	int m_last = m - 1;
	for (m_last; m_last > 0; m_last--)
	{
		days_total += month[m_last];
	}

	//將日期加總

	days_total = days_total + d;

	return days_total;
}

//建立一可判斷星期之函數
//設定days為總人數
int week_determine(int y, int m, int d) {
	int days = days_differ(y, m, d) % 7;//設定days為總人數

	switch (days)
	{
	case 0:
		return 2;
		break;
	case 1:
		return 3;
		break;
	case 2:
		return 4;
		break;
	case 3:
		return 5;
		break;
	case 4:
		return 6;
		break;
	case 5:
		return 7;
		break;
	case 6:
		return 1;
		break;

	default:
		break;
	}
}
