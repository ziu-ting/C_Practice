#include<stdio.h>
#include<stdlib.h>

int main(void) {
	printf("請輸入成績:\t");
	int grade;//成績範圍100~0
	scanf("%d", &grade);

	if (0<=grade && grade<=100)//判斷成績是否有效 有效範圍0~100
	{
		if (grade>=60)//100~60為及格
		{
			printf("此次成績為 %d，恭喜及格!\n", grade);
		}
		else if (grade>=50)//59~50需補考
		{
			printf("此次成績為 %d，未達及格，需要補考喔~\n", grade);
		}
		else//0~49需重修
		{
			printf("此次成績為 %d，未達及格，恭喜重修囉~\n", grade);
		}
	}
	else
	{
		printf("請輸入有效成績。(0~100)\n");
		return 0;
	}

	system("pause");
}