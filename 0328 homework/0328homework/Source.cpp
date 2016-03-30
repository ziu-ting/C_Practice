#include<stdio.h>
#include<stdlib.h>

int main(void) {
	printf("請輸入一個十六進位之四位正整數:");
	int num_1;//建置可輸入之未知數x
	scanf("%x", &num_1);//將輸入值設定為16進位 
	if (num_1<65536)//判定x是否為四位數 十六進位ffff的十進位值為65535
	{
		printf("x(十六進位\t十進位):\n\t %x\t%d\n", num_1, num_1);//將x印出為16進位數及10進位數
	}
	else
	{
		printf("請輸入有效十六進位之四位數。");
		return 0;//若x超過4位數則終止
	}

	printf("請輸入另一個十六進位之四位正整數:");
	int num_2;//建置可輸入之未知數y
	scanf("%x", &num_2);
	if (num_2<65536)//判定x是否為四位數 
	{
		printf("y(十六進位\t十進位):\n\t %x\t%d\n", num_2, num_2);//將y印出為16進位數及10進位數
	}
	else
	{
		printf("請輸入有效十六進位之四位數。");
		return 0;//若x超過4位數則終止
	}

	char op_1;//建置運算元輸入
	printf("請輸入運算元(+、-、*、/):");
	scanf(" %c", &op_1);//note:%c執行上有錯誤 待考證>>>>前置空格可執行
	if (op_1 =='+')
	{
		printf("%d + %d = %d",num_1,num_2,num_1 + num_2);
	}
	else if (op_1 == '-')
	{
		printf("%d - %d = %d",num_1,num_2,num_1 - num_2);
	}
	else if (op_1 == '*')
	{
		printf("%d * %d = %d",num_1,num_2,num_1 * num_2);
	}
	else if (op_1 == '/')
	{
		printf("%d / %d = %.3f\t(取值至小數點後第三位))",num_1,num_2,num_1 / (double)num_2);//轉換成可顯示小數
	}
	else
	{
		printf("請輸入有效運算元。");
	}

	system("pause");
	return 0;
}