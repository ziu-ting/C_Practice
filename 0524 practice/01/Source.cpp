#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void change(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void randomchange(int a[], int n,int times) {
	srand(time(NULL));
	
	for (int i = 0; i < times; i++)
	{
		int place1 = rand() % n;
		int place2 = rand() % n;
		if (place1!=place2)
		{
			change(a[place1], a[place2]);
		}
	}
}

void translate(int num) {
	if (num>=0&&num<=12)
	{
		printf("%s\t%d\n", "黑桃", (num + 1));
	}
	else if(num>=13&&num<=25)
	{
		printf("%s\t%d\n", "紅心", (num -12));
	}
	else if(num>=26&&num<=38)
	{
		printf("%s\t%d\n", "方塊", (num -25));
	}
	else if(num>=39&&num<=51)
	{
		printf("%s\t%d\n", "梅花", (num -38));
	}
}


//檢測是否升冪排序
void sequence(int a[], int n) {//陣列為a,當時最高項為n

	for (int i = n - 1; i >= 0; i--)
	{
		while (a[n] < a[i])
		{
			change(a[n], a[i]);
			n--;//使檢查項數向前移至小於後項   重要!!!
		}
	}

}

int main(void) {
	int number[52] = { '\0' };

	for (int i = 0; i < 52; i++)
	{
		number[i] = i + 1;
	}
	
	randomchange(number, 52, 1000);

	printf("玩家\t001的手牌\n\n");
	for (int j = 0; j < 52; j++)
	{
		if ((j == 0) || (j % 4 == 0))
		{
			sequence(number, j);
			translate(number[j]);
		}
	}

	printf("\n\n玩家\t002的手牌\n\n");
	for (int j = 0; j < 52; j++)
	{
		if (j % 4 == 1)
		{
			sequence(number, j);
			translate(number[j]);
		}
	}

	printf("\n\n玩家\t003的手牌\n\n");
	for (int j = 0; j < 52; j++)
	{
		if (j % 4 == 2)
		{
			sequence(number, j);
			translate(number[j]);
		}
	}

	printf("\n\n玩家\t004的手牌\n\n");
	for (int j = 0; j < 52; j++)
	{
		if (j % 4 == 3)
		{
			sequence(number, j);
			translate(number[j]);
		}
	}

	system("pause");
	return 0;
}