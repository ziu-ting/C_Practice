#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int dicefunction(char sum) {
	if (sum>=11&&sum<=18)
	{
		return 1;
	}
	else if (sum==9||sum==10)
	{
		return 2;
	}
	else if (sum<=8&&sum>=1)
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

int main(void) {
	
	char Dare;//賭大中小
	int Own_money = 15;//擁有總籌碼
	int Use_money = 0;//投注金額
	int End_money = 0;//一局結束後所贏得金額

	printf("=======遊戲規則=======\nB：\t大：11~18\t賠率：2\nM：\t中：09~10\t賠率：10\nS：\t小：01~08\t賠率：2\nE：\tEsc：終止遊戲\n\n");
	printf("=======遊戲開始=======\n");

	srand(time(NULL));

	while (Own_money>0)
	{
		printf("目前擁有金額為\t%d\n", Own_money);
		printf("請輸入投注金額：");
		scanf("%d", &Use_money);
		Own_money -= Use_money;//更新總籌碼為原籌碼減去投注金額

		printf("請輸入（B/M/S/E）：");
		scanf(" %c", &Dare);

		int DiceSum = 0;//初始設定三顆骰子之值為0
		DiceSum += rand() % 6 + 1;
		DiceSum += rand() % 6 + 1;
		DiceSum += rand() % 6 + 1;

		if (Dare == 66 || Dare == 98 || Dare == 77 || Dare == 109 || Dare == 83 || Dare == 115 || Dare == 69 || Dare == 101)
		{
			switch (Dare)
			{
			case 66:
			case 98:
				if (DiceSum >= 11 && DiceSum <= 18)//擲骰結果為大
				{
					End_money = Use_money * 2;
				}
				else
				{
					End_money = 0;
				}
				break;
			case 77:
			case 109:
				if (DiceSum == 9 || DiceSum == 10)//擲骰結果為大
				{
					End_money = Use_money * 10;
				}
				else
				{
					End_money = 0;
				}
				break;
			case 83:
			case 115:
				if (DiceSum <= 8 && DiceSum >= 1)//擲骰結果為大
				{
					End_money = Use_money * 2;
				}
				else
				{
					End_money = 0;
				}
				break;
			case 69:
			case 101:
				return 0;
				break;
			default:
				break;
			}
			printf("擲骰結果為\t%d\n", DiceSum);
			Own_money = Own_money + End_money;
		}
		else
		{
			printf("請輸入有效項目\n");
			return 0;
		}
	}
	system("pause");

}