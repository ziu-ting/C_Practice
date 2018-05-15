#include<stdio.h>
#include<stdlib.h>

#define Length 7

int main(void) {
	printf("=====大樂透規則=====\n\n投注時需選擇六個號碼及一個特別號\n號碼範圍：１～４９\n\n-----中獎方式-----\n\n頭獎：六個號碼\n二獎：五個號碼及一個特別號\n三獎：五個號碼\n四獎：四個號碼及一個特別號\n五獎：四個號碼\n六獎：三個號碼及一個特別號\n七獎：兩個號碼及一個特別號\n普獎：三個號碼\n");
	printf("\n請輸入本期開獎結果：\n");
	int computernumber[Length] = { 0 };
	for ( int i = 0; i < Length; i++)//將開獎號碼以陣列存取
	{
		if (i==0)
		{
			printf("請輸入特別號：");
			scanf("%d", &computernumber[i]);
			if (computernumber[i] > 49 || computernumber[i] < 1)
			{
				printf("請輸入有效號碼！\n");
				printf("請輸入特別號：");
				scanf("%d", &computernumber[i]);
			}
		}
		else
		{
			printf("請輸入第%d個號碼：",i);
			scanf("%d", &computernumber[i]);
			if (computernumber[i] > 49 || computernumber[i] < 1)
			{
				printf("請輸入有效號碼！\n");
				printf("請重新輸入號碼：");
				scanf("%d", &computernumber[i]);
			}
			for (int j = i - 1; j >= 0; j--)
			{
				if (computernumber[i] == computernumber[j]) {
					printf("請輸入有效號碼！\n");
					printf("請重新輸入號碼：");
					scanf("%d", &computernumber[i]);
				}
			}
		}
	}

	printf("\n請輸入本期投注結果：\n");
	int choocenumber[Length] = { 0 };
	for (int i = 0; i < Length; i++)//將使用者選擇號碼以陣列存取		
	{
		if (i == 0)
		{				
			printf("請輸入特別號：");
			scanf("%d", &choocenumber[i]);
			if (choocenumber[i] > 49 || choocenumber[i] < 1)				
			{
				printf("請輸入有效號碼！\n");
				printf("請輸入特別號：");
				scanf("%d", &choocenumber[i]);
			}
			for (int j = i - 1; j >= 0; j--)
			{
				if (choocenumber[i] == choocenumber[j]) {
					printf("請輸入有效號碼！\n");
					printf("請重新輸入號碼：");
					scanf("%d", &computernumber[i]);
				}
			}
		}
		else
		{
			printf("請輸入第%d個號碼：", i);
			scanf("%d", &choocenumber[i]);
			if (choocenumber[i] > 49 || choocenumber[i] < 1)
			{
				printf("請輸入有效號碼！\n");
				printf("請重新輸入號碼：");
				scanf("%d", &choocenumber[i]);
			}
		}
	}

	int specialnumber = 0,nomalnumber = 0;

	if (computernumber[0] == choocenumber[0])
	{
		specialnumber += 1;
	}

	for (int i = 1; i < Length; i++)
	{
		for (int j = 1;j < Length;j++) {
			if (computernumber[i] == choocenumber[j])
			{
				nomalnumber++;
			}
		}
	}

	printf("\n=====中獎結果=====\n\n一般號碼：%d\n特別號：%d\n", nomalnumber, specialnumber);

	if (nomalnumber == 6)
	{
		printf("恭喜中了頭獎！！");
	}
	else if (nomalnumber == 5 && specialnumber == 1)
	{
		printf("恭喜中了二獎！！");
	}
	else if (nomalnumber == 5)
	{
		printf("恭喜中了三獎！！");
	}
	else if (nomalnumber == 4 && specialnumber == 1)
	{
		printf("恭喜中了四獎！！");
	}
	else if (nomalnumber == 4)
	{
		printf("恭喜中了五獎！！");
	}
	else if (nomalnumber == 3 && specialnumber == 1)
	{
		printf("恭喜中了六獎！！");
	}
	else if (nomalnumber == 2 && specialnumber == 1)
	{
		printf("恭喜中了七獎！！");
	}
	else if (nomalnumber == 3)
	{
		printf("恭喜中了普獎！！");
	}
	else
	{
		printf("很遺憾沒中獎~");
	}
	system("pause");
}