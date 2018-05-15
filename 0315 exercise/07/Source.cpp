#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {
	int number = 0;
	srand(time(NULL));
	number = rand() % 99 + 1;//建治終極密碼，範圍為0+1~99+1

	int min = 1, max = 100;//定義範圍上下限
	for (int i = 1; i>0; i++)//建一無限迴圈使能重複猜
	{
	
		printf("終。極。密。碼\n第%d輪\t範圍：%d ~ %d\n", i, min, max);
		int guess;
		scanf("%d", &guess);
		if (guess<number)//所猜數字小於終極密碼，更新下限
		{
			min = guess;
		}
		else if (guess>number)//所猜數字大於終極密碼，更新上限
		{
			max = guess;
		}
		else
		{
			break;//當所猜的數字等於終極密碼時自動脫出
		}
		
	}
	printf("終極密碼為%d！！！恭喜爆炸！",number);
	system("pause");
}
//上下界若輸入不符合，仍執行
//以while設定會當掉無法運作
//待修正